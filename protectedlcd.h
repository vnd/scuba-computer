/** \file protectedLCD.h
*
* @brief Reentrant LCD driver.
*
* @par
* COPYRIGHT NOTICE: (c) 2011 Netrino, LLC.
* All rights reserved.
*/

#ifndef _PROTECTEDLCD_H
#define _PROTECTEDLCD_H

void protected_lcd_init(void);
void protected_lcd_display(uint8_t position, const uint8_t *data);
void protected_lcd_clear(void);

#endif  /* _PROTECTEDLCD_H */
