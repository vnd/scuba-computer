/** \file adc.c
*
* @brief ADC Driver
*
* @par
* COPYRIGHT NOTICE: (c) 2011 Netrino, LLC.
* All rights reserved.
*/

#include <assert.h>
#include <stdint.h>                             
#include <stdio.h>
#include "includes.h"
#include "iorx62n.h"
#include "lcd.h"
#include "protectedlcd.h"
#include "adc.h"
#include "alarm.h"

#define ADC_SOURCE_VR1 4
#define ADC_INTERRUPT_AFTER_SCAN 0x10
#define ADC_START 0x80
#define LCD_LINE_WIDTH 13
#define POLL_INTERVAL 500

#define BIT(n) (1 << (n))

/* Refer to p. 1677 of Processor_UsersManual_Hardware.pdf */
typedef struct
{
  uint8_t        control;                     // Offset 0x00
  uint8_t  const _unused1[3];
  uint16_t       channel_select;              // Offset 0x04
  uint16_t const _unused2;
  uint16_t       value_addition_mode_select;  // Offset 0x08
  uint16_t const _unused3;
  uint8_t        value_addition_count_select; // Offset 0x0C
  uint8_t  const _unused4;
  uint16_t       control_extended;            // Offset 0x0E
  uint8_t        start_trigger_select;        // Offset 0x10
  uint8_t  const _unused5[15];
  uint16_t       data[8];                     // Offset 0x20
} adc_t;

adc_t volatile * const p_adc = (adc_t *) 0x00089000;
#define adc (*p_adc)

/*!
* @brief Configure the ADC hardware to read Potentiometer VR1 and interrupt.
*/
static void adc_config(void)
{
    uint8_t *IER, *IPR;

    /* Select the 12-bit ADC */
    SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;

    /* Enable A/D interrupts at an appropriate priority, as instructed */
    IER = (uint8_t *)0x0008720C;
    IPR = (uint8_t *)0x00087348;

    *IPR = 9;     /* Set interrupt priority. */
    *IER |= 0x40; /* Unmask A/D interrupt. */

    /* Configure the A/D to perform a single scan and interrupt. */
    adc.control = ADC_INTERRUPT_AFTER_SCAN;
    adc.channel_select = BIT(ADC_SOURCE_VR1);
}

extern uint32_t rate;
/*!
*
* @brief: ADC Driver Task
*/
void adc_task(void *arg)
{
    OS_ERR err;
    
    (void)arg;

    /* configure ADC hardware to read Potentiometer VR1 and interrupt. */
    adc_config();
        
    for (;;)    
    {
        OSTimeDlyHMSM(0, 0, 0, 500, OS_OPT_TIME_HMSM_STRICT, &err);
        assert(OS_ERR_NONE == err);

        /* Trigger ADC conversion. */
        adc.control |= ADC_START;
    }
}

extern OS_Q rate_q;
/*!
*
* @brief ADC Interrupt Handler
*/
void adc_isr(void)
{
    /* not on the stack; so address is valid. */
    static int32_t sample;
    OS_ERR err;

    /* read from the A/D converter and reduce range from 12-bit to 10-bit */
    sample = adc.data[ADC_SOURCE_VR1] >> 2;
        
    OSQPost(&rate_q, &sample, sizeof(sample), OS_OPT_POST_FIFO, &err);
    assert(OS_ERR_NONE == err);
}

