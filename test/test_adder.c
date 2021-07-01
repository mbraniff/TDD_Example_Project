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

void test_addingMultingNumbersExpectingDifferentReturnsIgnoringParameters()
{
    int returnVals[3] = {2,4,6};
    for(int i=0;i<3;i++)
    {
        add_IgnoreAndReturn(returnVals[i]);
        TEST_ASSERT_EQUAL(returnVals[i], add(1,1));
    }
}