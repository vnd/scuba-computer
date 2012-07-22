/** \file main.c
*
* @brief Embedded Software Boot Camp
*
* @par
* COPYRIGHT NOTICE: (C) 2011 Netrino, LLC.
* All rights reserved.
*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "os_cfg_app.h"
#include "includes.h"
#include "lcd.h"
#include "protectedlcd.h"
#include "protectedled.h"
#include "pushbutton.h"
#include "adc.h"
#include "alarm.h"
#include "scuba.h"

#define MM 1000
#define CL 100
#define TASK_STACK_SIZE 128
#define STARTUP_TASK_PRIO 1
#define DEBOUNCE_TASK_PRIO 2
#define ADC_TASK_PRIO 3
#define MAIN_TASK_PRIO 4
#define ALARM_TASK_PRIO 5
#define DEFAULT_TASK_PRIO 14
#define LED_PERIOD_MS 167
#define LED_NUM 4
#define AIR_INC 5 * CL
#define AIR_INITIAL 50 * CL
#define BRAND_NAME "RENESAS"

static CPU_STK startup_stack[TASK_STACK_SIZE];
static CPU_STK led_stack[TASK_STACK_SIZE];
static CPU_STK debounce_stack[TASK_STACK_SIZE];
static CPU_STK adc_stack[TASK_STACK_SIZE];
static CPU_STK alarm_stack[TASK_STACK_SIZE];
static CPU_STK main_stack[TASK_STACK_SIZE];

static OS_TCB startup_tcb;
static OS_TCB led_tcb;
static OS_TCB debounce_tcb;
static OS_TCB alarm_tcb;
static OS_TCB main_tcb;
OS_TCB adc_tcb;

OS_Q rate_q;
OS_SEM sw1_sem;
OS_SEM sw2_sem;
OS_FLAG_GRP alarm_flags;

/*!
* @brief Health LED Flasher Task
*/
static void led_task(void *arg)
{
    OS_ERR err;
    
    for (;;)
    {
        protected_led_toggle(LED_NUM);
        
        OSTimeDlyHMSM(0, 0, 0, LED_PERIOD_MS, OS_OPT_TIME_HMSM_STRICT, &err);
        assert(OS_ERR_NONE == err);
    }
}

static void main_task(void *arg)
{
    char msg[LCD_CHARS_PER_LINE];
    int32_t depth = 0, depth_mm = 0, display_meters = 1, rate = 0,
        air_cl = AIR_INITIAL, enough_air = 1;
    OS_TICK dive_started = 0, curr_ticks;
    OS_PEND_DATA pend_tbl[] = {
        {.PendObjPtr = (OS_PEND_OBJ *) &sw1_sem},
        {.PendObjPtr = (OS_PEND_OBJ *) &sw2_sem},
        {.PendObjPtr = (OS_PEND_OBJ *) &rate_q},
    };
    OS_ERR err;

    protected_lcd_display(LCD_LINE1, BRAND_NAME);

    while (1)
    {
        OSPendMulti(&pend_tbl[0], sizeof(pend_tbl)/sizeof(OS_PEND_DATA), 0,
            OS_OPT_PEND_BLOCKING, &err);
        assert(OS_ERR_NONE == err);

        if (pend_tbl[0].RdyObjPtr && !depth_mm)
        {
            air_cl += AIR_INC;
            if (air_cl > MAX_AIR_IN_CL)
                air_cl = MAX_AIR_IN_CL;
        }

        if (pend_tbl[1].RdyObjPtr)
            display_meters = !display_meters;

        if (pend_tbl[2].RdyObjPtr)
        {
            rate = ADC2RATE(*(int32_t *)pend_tbl[2].RdyMsgPtr);

            if (!depth_mm && rate > 0)
                dive_started = OSTimeGet(&err);

            depth_mm += depth_change_in_mm(rate);
            if (depth_mm < 0)
                depth_mm = 0;
            depth = display_meters ? depth_mm / MM : MM2FT(depth_mm);
            if (depth_mm)
            {
                air_cl -= gas_rate_in_cl(depth_mm);
                if (air_cl < 0)
                    air_cl = 0;

                curr_ticks = OSTimeGet(&err);
            }

            enough_air = gas_to_surface_in_cl(depth_mm) <= air_cl;
        }

        sprintf(msg, "DEPTH: %d%s", depth, display_meters ? "M" : "FT");
        protected_lcd_display(LCD_LINE3, (uint8_t *)msg);
        sprintf(msg, "RATE: %+d%s", display_meters ? rate : MM2FT(rate * MM),
            display_meters ? "M" : "FT");
        protected_lcd_display(LCD_LINE4, (uint8_t *)msg);
        sprintf(msg, "AIR: %dL", air_cl / CL);
        protected_lcd_display(LCD_LINE5, (uint8_t *)msg);
        sprintf(msg, "EDT: %ds", dive_started ?
            (curr_ticks - dive_started) / OS_CFG_TICK_RATE_HZ : 0);
        protected_lcd_display(LCD_LINE6, (uint8_t *)msg);

        if (!enough_air)
        {
            OSFlagPost(&alarm_flags, ALARM_HIGH, OS_OPT_POST_FLAG_SET, &err);
            assert(OS_ERR_NONE == err);
            protected_lcd_display(LCD_LINE8, "Alarm: HIGH");
        }
        else if (depth_mm && rate < -ASCENT_RATE_LIMIT)
        {
            OSFlagPost(&alarm_flags, ALARM_MEDIUM, OS_OPT_POST_FLAG_SET, &err);
            assert(OS_ERR_NONE == err);
            protected_lcd_display(LCD_LINE8, "Alarm: MED");
        }
        else if (depth_mm > MAX_DEPTH_IN_M * MM)
        {
            OSFlagPost(&alarm_flags, ALARM_LOW, OS_OPT_POST_FLAG_SET, &err);
            assert(OS_ERR_NONE == err);
            protected_lcd_display(LCD_LINE8, "Alarm: LOW");
        }
        else 
        {
            OSFlagPost(&alarm_flags, ALARM_NONE, OS_OPT_POST_FLAG_SET, &err);
            assert(OS_ERR_NONE == err);
            protected_lcd_display(LCD_LINE8, "");
        }
    }
}

static void startup_task(void *arg)
{
    OS_ERR err;
    
    BSP_Init();
    CPU_Init();
    OS_CPU_TickInit();
    protected_led_init();
    protected_lcd_init();
    
    OSQCreate(&rate_q, "Rate Queue", 1, &err);
    assert(OS_ERR_NONE == err);    
    OSSemCreate(&sw1_sem, "SW1 Semaphore", 0, &err);
    assert(OS_ERR_NONE == err);    
    OSSemCreate(&sw2_sem, "SW2 Semaphore", 0, &err);
    assert(OS_ERR_NONE == err);
    OSFlagCreate(&alarm_flags, "Alarm Flags", 0, &err);
    assert(OS_ERR_NONE == err);
    
    OSTaskCreate(&debounce_tcb, "Debounce Task", debounce_task, NULL,
        DEBOUNCE_TASK_PRIO, &debounce_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL,
        OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);
    
    OSTaskCreate(&adc_tcb, "ADC Task", adc_task, NULL, ADC_TASK_PRIO,
        &adc_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL, OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);
    
    OSTaskCreate(&main_tcb, "Main Task", main_task, NULL, MAIN_TASK_PRIO,
        &main_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL, OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);

    OSTaskCreate(&alarm_tcb, "Alarm Task", alarm_task, NULL, ALARM_TASK_PRIO,
        &alarm_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL, OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);
    
    OSTaskCreate(&led_tcb, "LED Task", led_task, NULL, DEFAULT_TASK_PRIO,
        &led_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL, OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);

    OSTaskDel(NULL, &err);
    assert(0);
}

void main(void)
{
    OS_ERR err;
    
    CPU_IntDis();

    OSInit(&err);
    assert(OS_ERR_NONE == err);
    
    OSTaskCreate(&startup_tcb, "Startup Task", startup_task, NULL,
        STARTUP_TASK_PRIO, &startup_stack[0], 0, TASK_STACK_SIZE, 0, 0, NULL,
        OS_OPT_TASK_NONE, &err);
    assert(OS_ERR_NONE == err);
    
    OSStart(&err);
    assert(0);
}

