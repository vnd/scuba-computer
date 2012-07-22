/** \file alarm.c
*
* @brief Alarm Manager
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
#include "alarm.h"

/* Speaker Task Items */
#define SPEAKER_PRIO    11
#define TASK_STACK_SIZE 128

/* PWM Prescalars */
typedef enum {TONE_HI = 450, TONE_MED = 700, TONE_LO = 950} pwm_t;

/* Waveform Data Structure */
typedef struct
{
    pwm_t    tone1;    /* PWM prescalar for Tone 1 */
    pwm_t    tone2;    /* PWM prescalar for Tone 2 */
    uint16_t interval; /* Seconds to play each tone, unless chopped */
    uint8_t  chopped;  /* Ignore interval, use on/off chop instead */

} wave_t;

const wave_t alarm_low    = {TONE_LO,  TONE_MED, 2, 0};
const wave_t alarm_medium = {TONE_MED, TONE_HI,  1, 0};
const wave_t alarm_high   = {TONE_LO,  TONE_HI,  1, 1};

static CPU_STK speaker_stack[TASK_STACK_SIZE];
static OS_TCB  speaker_tcb;

/*!
*
* @brief Configure a timer to drive the speaker via PWM.
*/
static void speaker_config(void)
{
    /* Configure the hardware in preparation for speaker tones.
     * The MTIOCA8 output goes to port A bit 6 (the AUDIO_R signal)
     * No need to explicitly set this as an output since the MTU does that
     * Refer to pages 854, 855, 859, 873 and 889 of the HW manual */
    SYSTEM.MSTPCRA.BIT.MSTPA8 = 0; /* Enable MTU8 */
    MTU8.TCR.BIT.TPSC = 0x03;      /* Prescale by 64 */
    MTU8.TCR.BIT.CCLR = 0x02;      /* Select clear counter on TGRB match */
    MTU8.TIOR.BIT.IOA = 0x02;      /* MTIOCA8 pin initial low, high on match */
    MTU8.TMDR.BIT.MD  = 0x03;      /* PWM mode 2 - page 859 */
    MTU8.TGRB = 400;               /* frequency of 1000 Hz */
    MTU8.TGRA = 375;               /* 50% duty cycle */

    /* Ensure that the speaker is off, start MTU8 */
    MTUB.TSTR.BIT.CST2 = 0;
}

/*!
* @brief Speaker Task
* @param[in] arg Waveform to play.
*/
void speaker_task(void *arg)
{
    wave_t *waveform = (wave_t *)arg;
    OS_ERR err;      

    if (waveform->chopped)
    {
        for (;;)
        {
            /* Play Tone 1 */
            MTU8.TGRB = waveform->tone1;
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 0;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 0;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
                       
            /* Play Tone 2 */
            MTU8.TGRB = waveform->tone2;
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 0;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);
            MTUB.TSTR.BIT.CST2 = 0;
            OSTimeDlyHMSM(0, 0, 0, 125, OS_OPT_TIME_HMSM_STRICT, &err);        
        }
    }
    else
    {
        for (;;)
        {
            /* Play Tone 1 */
            MTU8.TGRB = waveform->tone1;
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, waveform->interval, 0, OS_OPT_TIME_HMSM_STRICT,
                &err);
            MTUB.TSTR.BIT.CST2 = 0;

            /* Play Tone 2 */
            MTU8.TGRB = waveform->tone2;
            MTUB.TSTR.BIT.CST2 = 1;
            OSTimeDlyHMSM(0, 0, waveform->interval, 0, OS_OPT_TIME_HMSM_STRICT,
                &err);
            MTUB.TSTR.BIT.CST2 = 0;
        }
    }
}

static inline void kill_speaker_if_alive(uint8_t *is_alive)
{
    OS_ERR err;     
     
    if (!*is_alive)
        return;

    OSTaskDel(&speaker_tcb, &err);    
    assert(OS_ERR_NONE == err);
    *is_alive = 0;
    
    /* Ensure the speaker is off */
    MTUB.TSTR.BIT.CST2 = 0;                                             
}

extern OS_FLAG_GRP alarm_flags;
/*!
*
* @brief Alarm Task
*/
void alarm_task(void *arg)
{
    wave_t const *waveform = (wave_t *)NULL;
    uint8_t speaker_task_alive = 0;
    uint8_t create_speaker_task;
    OS_FLAGS flags;
    OS_ERR err;                

    (void)arg;

    speaker_config();

    for (;;)    
    {
        flags = OSFlagPend(&alarm_flags, 0xF, 0,
            OS_OPT_PEND_FLAG_SET_ANY | OS_OPT_PEND_FLAG_CONSUME |
            OS_OPT_PEND_BLOCKING, NULL, &err);
        assert(OS_ERR_NONE == err);

        create_speaker_task = 0;
                
        if ((flags & ALARM_HIGH) && (waveform != &alarm_high))
        {
            kill_speaker_if_alive(&speaker_task_alive);
 
            waveform = &alarm_high;
            create_speaker_task = 1;
        }
        else if ((flags & ALARM_MEDIUM) && (waveform != &alarm_medium))
        {
            kill_speaker_if_alive(&speaker_task_alive);

            waveform = &alarm_medium;
            create_speaker_task = 1;
        }
        else if ((flags & ALARM_LOW) && (waveform != &alarm_low))
        {
            kill_speaker_if_alive(&speaker_task_alive);
            
            waveform = &alarm_low;
            create_speaker_task = 1;
        }
        else if (flags & ALARM_NONE)
        {
            kill_speaker_if_alive(&speaker_task_alive);

            waveform = NULL;
            create_speaker_task = 0;
        }
                
        if (create_speaker_task)
        {
            OSTaskCreate(&speaker_tcb, "Speaker Task", speaker_task,
                (void *)waveform, SPEAKER_PRIO, &speaker_stack[0],
                TASK_STACK_SIZE / 10u, TASK_STACK_SIZE, 0u, 0u, 0, 0, &err);
            assert(OS_ERR_NONE == err);

            speaker_task_alive = 1;
        }
    }
}

