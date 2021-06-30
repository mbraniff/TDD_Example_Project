// AUTHOR: Matthew Braniff
// 06/30/2021

#include "unity.h"

#include "alarm.h"
#include "timer_driver.h"
#include "mock_one_shot_timer.h"
#include "led.h"

one_shot_timer_t timer;
led_t led;
alarm_t alarm;

static void init(void)
{
    alarm_init(&alarm, &timer, &led);
}

static void time_did_change_redirect(one_shot_timer_t* _timer, int num_calls)
{
    if(_timer->current_time >= _timer->stop_time)
    {
        if(_timer->callback)
        {
            _timer->callback(_timer->context);
        }
    }
}

void setUp(void)
{
    uint8_t stop_time = 2;
    one_shot_timer_init_Expect(&timer, stop_time, 0, 0);
    timer_init(&timer, stop_time, 0, 0);
    led_init(&led);
}

void tearDown(void)
{
}

void test_alarmShouldInitWithCorrectTimerAndLedPointer(void)
{
    init();

    TEST_ASSERT(alarm.led == &led && alarm.timer == &timer);
}

void test_whenTimePassesButNotPastStopTime_thenLedShouldRemainOffAndTimerShouldReadCorrectTime(void)
{
    init();

    one_shot_timer_time_did_change_Expect(&timer);
    time_pass(&timer, 1);

    TEST_ASSERT(led_read(&led) == OFF);
    TEST_ASSERT(timer.current_time == 1);
}

void test_whenTimePassesStopTime_thenLedShouldTurnOn(void)
{
    init();

    one_shot_timer_time_did_change_Expect(&timer);
    one_shot_timer_time_did_change_Stub(time_did_change_redirect);
    time_pass(&timer, 2);

    TEST_ASSERT(led_read(&led) == ON);
}