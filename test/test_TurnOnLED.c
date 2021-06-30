#include "unity.h"
#include "mock_Timer.h"
#include "TurnOnLED.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// void test_LED_is_on(void)
// {
//     bool is_on = LED(1);
//     TEST_ASSERT (is_on == true);
// }

// void test_LED_is_not_on(void)
// {
//     bool is_on = LED(2);
//     TEST_ASSERT(is_on == true);
// }

void test_LED_is_off(void)
{
    bool is_on = LED(0);
    TEST_ASSERT(is_on == false);
}

// void test_timer_output(void)
// {
//     //int timer_value = 7;
//     timer_ExpectAndReturn(7);
//     TEST_ASSERT(timer() == 7);
// }

// void test_timer_turns_on_LED(void)
// {
//     timer_ExpectAndReturn(1);
//     int time = timer();
//     bool is_on = LED(time);
//     TEST_ASSERT(is_on == true);
// }

// // void test_timer_LED_is_off(void)
// // {
// //     timer_ExpectAndReturn(0);
// //     int time = timer();
// //     bool is_on = LED(time);
// //     TEST_ASSERT(is_on == false);
// // }
