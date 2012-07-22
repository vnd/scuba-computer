/** \file scuba.c

 $REVISIONS: $
 - 01 Jan 2008: Original writing.

 $COPYRIGHT: $
 - Copyright 2008 by Netrino, LLC. All rights reserved.
**/

#include <stdint.h>
#include "includes.h"
#include "scuba.h"

/* Respiratory minute volume = 1200 centiLitres / minute */
#define RMV (1200)
/* Respiratory half second volume = 10 centilitres / half_second */
#define RHSV (RMV / 120)

/* Computes how much gas is consumed in a half second at a certain depth. */
uint32_t gas_rate_in_cl(uint32_t depth_in_mm)
{
    uint32_t depth_in_m = depth_in_mm / 1000;  
    /* 10m of water = 1 bar = 100 centibar */
    uint16_t ambient_pressure_in_cb = 100 + (10 * depth_in_m);      
                        
    /* Gas consumed at STP = RHSV * ambient pressure / standard pressure */
    return ((RHSV * ambient_pressure_in_cb) / 100);
}

/* This computes how much gas at STP it would take to surface from the current
 * depth, assuming no decompression stops and an ascent rate of
 * ASCENT_RATE_LIMIT. It does this via numerical integration (step size is 1 m).
 * Returns the number of centilitres of gas at STP required to make it to the
 * surface.*/
uint32_t gas_to_surface_in_cl(uint32_t depth_in_mm)
{
    uint32_t gas = 0;
    uint16_t halfsecs_to_ascend_1m = (2 * 60) / ASCENT_RATE_LIMIT;;
    /* Ambient pressure in centiBar */
    uint16_t ambient_pressure_in_cb, depth_in_m;

    for (depth_in_m = depth_in_mm / 1000; depth_in_m > 0; depth_in_m--)
    {
        ambient_pressure_in_cb = 100 + (depth_in_m * 100 / 10);
        gas += (RHSV * halfsecs_to_ascend_1m * ambient_pressure_in_cb) / 100;
    }

    return gas;
}

