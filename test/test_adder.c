#include "unity.h"

#include "mock_adder.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addTwoNumbersExpectingReturnAndTwoArguments()
{
    add_ExpectAndReturn(1,1,2);
    int ret = add(1,1);
    TEST_ASSERT(ret == 2);
}

void test_addTwoNumbersExpectingReturnButIgnoringArguments()
{
    add_IgnoreAndReturn(2);
    int ret = add(5,6);
    TEST_ASSERT(ret == 2);
}