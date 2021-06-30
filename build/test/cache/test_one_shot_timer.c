#include "test/timer_driver.h"
#include "build/test/mocks/mock_one_shot_timer.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










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



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((one_shot_timer_init_fake.call_count)), (("Function " "one_shot_timer_init" " called the incorrect number of times.")), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}



void test_whenTimePasses_thenCurrentTimeIsUpdatedAndTimeDidChangeIsCalled(void)

{

    timer_init(&timer, stop_time, 0, 0);



    time_pass(&timer, 2);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((one_shot_timer_time_did_change_fake.call_count)), (("Function " "one_shot_timer_time_did_change" " called the incorrect number of times.")), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

    do {if ((timer.current_time == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(57)));}} while(0);

}



void test_whenTimePassesAndIsNotAtOrPastStopTime_thenCallbackShouldNotBeCalled(void)

{

    timer_init(&timer, stop_time, callback, 0);



    one_shot_timer_time_did_change_fake.custom_fake = time_did_change_redirect;

    time_pass(&timer, 1);

    do {if ((callback_count == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(66)));}} while(0);

}



void test_whenTimePassesStopTime_thenTimerShouldCallback(void)

{

    timer_init(&timer, stop_time, callback, 0);



    one_shot_timer_time_did_change_fake.custom_fake = time_did_change_redirect;

    time_pass(&timer, 2);

    do {if ((callback_count == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

}
