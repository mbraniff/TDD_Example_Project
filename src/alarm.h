// AUTHOR: Matthew Braniff
// 06/30/2021

#ifndef ALARM_H
#define ALARM_H

#define REINTERPRET(name, from, type) type name = (type)from
#include "one_shot_timer.h"
#include "led.h"

typedef struct alarm_t{
    one_shot_timer_t* timer;
    led_t* led;
}alarm_t;

void alarm_init(alarm_t* alarm, one_shot_timer_t* timer, led_t* led);

#endif // ALARM_H