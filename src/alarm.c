// AUTHOR: Matthew Braniff
// 06/30/2021

#include "alarm.h"

static void turnOnLed(void* context)
{
    REINTERPRET(led, context, led_t*);
    led_write(led, ON);
}

void alarm_init(alarm_t* alarm, one_shot_timer_t* timer, led_t* led)
{
    alarm->timer = timer;
    timer->callback = turnOnLed;
    timer->context = led;
    alarm->led = led;
}