#include "src/led.h"
#include "build/test/mocks/mock_one_shot_timer.h"
#include "test/timer_driver.h"
#include "src/alarm.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










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

    one_shot_timer_init_CMockExpect(34, &timer, stop_time, 0, 0);

    timer_init(&timer, stop_time, 0, 0);

    led_init(&led);

}



void tearDown(void)

{

}



void test_alarmShouldInitWithCorrectTimerAndLedPointer(void)

{

    init();



    do {if ((alarm.led == &led && alarm.timer == &timer)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

}



void test_whenTimePassesButNotPastStopTime_thenLedShouldRemainOffAndTimerShouldReadCorrectTime(void)

{

    init();



    one_shot_timer_time_did_change_CMockExpect(54, &timer);

    time_pass(&timer, 1);



    do {if ((led_read(&led) == 

   0

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(57)));}} while(0);

    do {if ((timer.current_time == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}



void test_whenTimePassesStopTime_thenLedShouldTurnOn(void)

{

    init();



    one_shot_timer_time_did_change_CMockExpect(65, &timer);

    one_shot_timer_time_did_change_Stub(time_did_change_redirect);

    time_pass(&timer, 2);



    do {if ((led_read(&led) == 

   1

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

}
