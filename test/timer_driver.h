// AUTHOR: Matthew Braniff
// 06/30/2021

#include "one_shot_timer.h"

void timer_init(one_shot_timer_t* timer, uint8_t stop, callback_t callback, void* context)
{
    timer->stop_time = stop;
    timer->callback = callback;
    timer->context = context;
    one_shot_timer_init(timer, stop, callback, context);
}

void time_pass(one_shot_timer_t* timer, uint8_t time)
{
    timer->current_time += time;
    one_shot_timer_time_did_change(timer);
}