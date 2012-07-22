#include <assert.h>
#include <stdint.h>
#include "includes.h"
#include "protectedled.h"

static OS_MUTEX led_mutex;

void protected_led_init(void)
{
    OS_ERR err;

    OSMutexCreate(&led_mutex, "LED Mutex", &err);
    assert(OS_ERR_NONE == err);
}

void protected_led_toggle(uint8_t led)
{
    OS_ERR err;

    OSMutexPend(&led_mutex, 0, OS_OPT_PEND_BLOCKING, 0, &err);
    assert(OS_ERR_NONE == err);
    LED_Toggle(led);
    OSMutexPost(&led_mutex, OS_OPT_POST_NONE, &err);
    assert(OS_ERR_NONE == err);
}

