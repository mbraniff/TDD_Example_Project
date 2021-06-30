#include "one_shot_timer.h"

static void callback(one_shot_timer_t* timer){
    timer->callback(timer->context);
}

void one_shot_timer_init(one_shot_timer_t* timer, uint8_t stop, callback_t callback, void* context)
{
    timer->stop_time = stop;
    timer->callback = callback;
    timer->context = context;
}
void one_shot_timer_set_callback(one_shot_timer_t* timer, callback_t callback);
void one_shot_timer_set_context(one_shot_timer_t* timer, void* context);
void one_shot_timer_time_did_change(one_shot_timer_t* timer)
{
    if(timer->current_time >= timer->stop_time)
    {
        callback(timer);
    }
}