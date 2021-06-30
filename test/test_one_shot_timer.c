// AUTHOR: Matthew Braniff
// 06/30/2021

#include "unity.h"

#include "one_shot_timer.h"
#include "mock_one_shot_timer.h"
#include "timer_driver.h"

one_shot_timer_t timer;
uint8_t stop_time;
uint32_t callback_count = 0;

static void callback(void* context)
{
    callback_count += 1;
}

static void time_did_change_redirect(one_shot_timer_t* _timer)
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
    stop_time = 2;

}

void tearDown(void)
{
    timer.current_time = 0;
    callback_count = 0;
    one_shot_timer_time_did_change_reset();
    one_shot_timer_init_reset();
}

void test_timer_is_initiated(void)
{
    timer_init(&timer, stop_time, 0, 0);

    TEST_ASSERT_CALLED(one_shot_timer_init);
}

void test_whenTimePasses_thenCurrentTimeIsUpdatedAndTimeDidChangeIsCalled(void)
{
    timer_init(&timer, stop_time, 0, 0);

    time_pass(&timer, 2);
    TEST_ASSERT_CALLED(one_shot_timer_time_did_change);
    TEST_ASSERT(timer.current_time == 2);
}

void test_whenTimePassesAndIsNotAtOrPastStopTime_thenCallbackShouldNotBeCalled(void)
{
    timer_init(&timer, stop_time, callback, 0);

    one_shot_timer_time_did_change_fake.custom_fake = time_did_change_redirect;
    time_pass(&timer, 1);
    TEST_ASSERT(callback_count == 0);
}

void test_whenTimePassesStopTime_thenTimerShouldCallback(void)
{
    timer_init(&timer, stop_time, callback, 0);

    one_shot_timer_time_did_change_fake.custom_fake = time_did_change_redirect;
    time_pass(&timer, 2);
    TEST_ASSERT(callback_count == 1);
}
