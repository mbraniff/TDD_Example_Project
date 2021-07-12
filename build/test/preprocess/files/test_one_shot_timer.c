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

    one_shot_timer_init_CMockExpect(43, &timer, stop_time, 0, 0);

    timer_init(&timer, stop_time, 0, 0);

}



void test_whenTimePasses_thenCurrentTimeIsUpdatedAndTimeDidChangeIsCalled(void)

{



    one_shot_timer_init_CMockExpect(50, &timer, stop_time, 0, 0);

    timer_init(&timer, stop_time, 0, 0);





    one_shot_timer_time_did_change_CMockExpect(54, &timer);





    time_pass(&timer, 2);

    do {if ((timer.current_time == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}



void test_whenTimePassesAndIsNotAtOrPastStopTime_thenCallbackShouldNotBeCalled(void)

{



    one_shot_timer_init_CMockExpect(64, &timer, stop_time, callback, 0);

    timer_init(&timer, stop_time, callback, 0);





    one_shot_timer_time_did_change_CMockExpect(68, &timer);

    one_shot_timer_time_did_change_Stub(time_did_change_redirect);





    time_pass(&timer, 1);

    do {if ((callback_count == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

}



void test_whenTimePassesStopTime_thenTimerShouldCallback(void)

{

    one_shot_timer_init_CMockExpect(78, &timer, stop_time, callback, 0);

    timer_init(&timer, stop_time, callback, 0);



    one_shot_timer_time_did_change_CMockExpect(81, &timer);

    one_shot_timer_time_did_change_Stub(time_did_change_redirect);

    time_pass(&timer, 2);

    do {if ((callback_count == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(84)));}} while(0);

}



void test_thisTestFails(void)

{

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}
