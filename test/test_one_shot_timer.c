// AUTHOR: Matthew Braniff
// 06/30/2021

#include "unity.h"

#include "mock_one_shot_timer.h"
#include "timer_driver.h"

one_shot_timer_t timer;
uint8_t stop_time;
uint32_t callback_count = 0;

static void callback(void* context)
{
    callback_count += 1;
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

    stop_time = 2;
}

void tearDown(void)
{
    timer.current_time = 0;
    callback_count = 0;
}

void test_timer_is_initiated(void)
{
    one_shot_timer_init_Expect(&timer, stop_time, 0, 0);
    timer_init(&timer, stop_time, 0, 0);
}

void test_whenTimePasses_thenCurrentTimeIsUpdatedAndTimeDidChangeIsCalled(void)
{
    // Given
    one_shot_timer_init_Expect(&timer, stop_time, 0, 0);
    timer_init(&timer, stop_time, 0, 0);

    // Then
    one_shot_timer_time_did_change_Expect(&timer);

    // when
    time_pass(&timer, 2);
    TEST_ASSERT(timer.current_time == 2);
}

void test_whenTimePassesAndIsNotAtOrPastStopTime_thenCallbackShouldNotBeCalled(void)
{
    // Given
    one_shot_timer_init_Expect(&timer, stop_time, callback, 0);
    timer_init(&timer, stop_time, callback, 0);

    // Then 
    one_shot_timer_time_did_change_Expect(&timer);
    one_shot_timer_time_did_change_Stub(time_did_change_redirect);
    
    // When
    time_pass(&timer, 1);
    TEST_ASSERT(callback_count == 0);
}

void test_whenTimePassesStopTime_thenTimerShouldCallback(void)
{
    one_shot_timer_init_Expect(&timer, stop_time, callback, 0);
    timer_init(&timer, stop_time, callback, 0);

    one_shot_timer_time_did_change_Expect(&timer);
    one_shot_timer_time_did_change_Stub(time_did_change_redirect);
    time_pass(&timer, 2);
    TEST_ASSERT(callback_count == 1);
}