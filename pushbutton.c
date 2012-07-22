/** \file pushbutton.c
*
* @brief Button Debouncer
*
* @par
* COPYRIGHT NOTICE: (C) 2011 Netrino, LLC.
* All rights reserved.
*/

#include <assert.h>
#include <stdint.h>
#include "includes.h"
#include "iorx62n.h"
#include "pushbutton.h"                                                         

extern OS_SEM sw1_sem;
extern OS_SEM sw2_sem;

/*!
*
* @brief Button Debounce Task
*/
void debounce_task(void *arg)
{
    uint8_t sw1_curr, sw1_prev, sw2_curr, sw2_prev, sw2_retriggered;
    uint8_t raw;
    OS_ERR err;

    (void)arg;

    sw1_curr = sw1_prev = sw2_curr = sw2_prev = sw2_retriggered = 1;
    
    /* Configure GPIO Port4 as an input */
    PORT4.DDR.BYTE = 0;

    for (;;)
    {
         OSTimeDlyHMSM(0, 0, 0, 50, OS_OPT_TIME_HMSM_STRICT, &err);
         
         raw = PORT4.PORT.BYTE;

         sw1_curr = raw & 0x01;
         if ((0 == sw1_curr) && (0 == sw1_prev))
         {
             OSSemPost(&sw1_sem, OS_OPT_POST_ALL, &err);
             assert(OS_ERR_NONE == err);
         }
         sw1_prev = sw1_curr;
         
         sw2_curr = raw & 0x02;
         if ((0 == sw2_curr) && (0 == sw2_prev))
         {
             if (sw2_retriggered)
             {
                 OSSemPost(&sw2_sem, OS_OPT_POST_ALL, &err);
                 assert(OS_ERR_NONE == err);

                 sw2_retriggered = 0;
             }
         }
         else
             sw2_retriggered = 1;

         sw2_prev = sw2_curr;
    }
}
