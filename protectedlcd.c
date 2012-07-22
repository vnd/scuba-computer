/** \file protectedled.c
*
* @brief Reentrant LCD driver.
*
* @par
* COPYRIGHT NOTICE: (c) 2011 Netrino, LLC.
* All rights reserved.
*/

#include <assert.h>
#include <stdint.h>
#include "includes.h"
#include "protectedlcd.h"		
#include "lcd.h"

static OS_MUTEX lcd_mutex;

/*!
* @brief Initialize the reentrant LCD driver.
*/
void protected_lcd_init(void)
{
    OS_ERR err;
    
    OSMutexCreate(&lcd_mutex, "LCD Mutex", &err);
    assert(OS_ERR_NONE == err);
    OSMutexPend(&lcd_mutex, 0, OS_OPT_PEND_BLOCKING, 0, &err);
    assert(OS_ERR_NONE == err);
    InitialiseLCD();
    OSMutexPost(&lcd_mutex, OS_OPT_POST_NONE, &err);
    assert(OS_ERR_NONE == err);
}

/*!
* @brief Display data on the LCD, safely.
* @param[in] Position and data.
*/
void protected_lcd_display(uint8_t position, const uint8_t *data)
{
    OS_ERR err;
    
    OSMutexPend(&lcd_mutex, 0, OS_OPT_PEND_BLOCKING, 0, &err);
    assert(OS_ERR_NONE == err);
    DisplayLCD(position, data);
    OSMutexPost(&lcd_mutex, OS_OPT_POST_NONE, &err);
    assert(OS_ERR_NONE == err);
}

/*!
* @brief Display data on the LCD, safely.
* @param[in] Position and data.
*/
void protected_lcd_clear(void)
{
    OS_ERR err;
    
    OSMutexPend(&lcd_mutex, 0, OS_OPT_PEND_BLOCKING, 0, &err);
    assert(OS_ERR_NONE == err);
    ClearLCD();
    OSMutexPost(&lcd_mutex, OS_OPT_POST_NONE, &err);
    assert(OS_ERR_NONE == err);
}
