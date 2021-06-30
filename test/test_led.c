// AUTHOR: Matthew Braniff
// 06/30/2021

#include "unity.h"

#include "led.h"

led_t led;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ledShouldInitializeToOff(void)
{
    led_init(&led);

    TEST_ASSERT(led_read(&led) == OFF);
}

void test_ledCanBeTurnedOnWithWriteFunction(void)
{
    led_init(&led);

    led_write(&led, ON);
    TEST_ASSERT(led_read(&led) == ON);
}

void test_ledCanBeTurnedOffWithWriteFunction(void)
{
    led_init(&led);

    led_write(&led, ON);
    led_write(&led, OFF);

    TEST_ASSERT(led_read(&led) == OFF);
}