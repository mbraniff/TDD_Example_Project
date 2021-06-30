#include "led.h"

void led_init(led_t* led)
{
    led->state = OFF;
}

void led_write(led_t* led, bool state)
{
    led->state = state;
}
bool led_read(led_t* led)
{
    return led->state;
}