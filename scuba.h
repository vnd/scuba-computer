/** \file scuba.h
*
* @brief Dive computer helper functions.
*
* @par
* COPYRIGHT NOTICE: (c) 2011 Netrino, LLC.
* All rights reserved.
*/

#ifndef _SCUBA_H
#define _SCUBA_H

enum {MAX_AIR_IN_CL = (2000 * 100)}; /* Compressed air capacity (in cL) */
enum {MAX_DEPTH_IN_M = 40};          /* Maximum safe depth (in meters) */
enum {ASCENT_RATE_LIMIT = 15};       /* Maximum safe ascent rate (in m/min) */

#define MM2FT(mm) ((mm) / 305) /* NOTE: It's actually 304.8 mm to a 1 ft */
#define ADC2RATE(adc) (((adc) >= 524) ? (((adc) - 523) / 10) \
                    : (((adc) >= 500) ? 0 : (((adc) - 500) / 10)))

#define depth_change_in_mm(ascent_rate_in_m) \
                    (((ascent_rate_in_m) * 1000) / (2 * 60))

uint32_t gas_rate_in_cl(uint32_t depth_in_mm);
uint32_t gas_to_surface_in_cl(uint32_t depth_in_mm);

#endif /* _SCUBA_H */
