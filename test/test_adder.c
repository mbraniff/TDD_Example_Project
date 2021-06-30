#include "unity.h"

#include "mock_adder.h"

int returnVals[3] = {2,4,6};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addTwoNumbersExpectingReturnAndTwoArguments()
{
    SET_RETURN_SEQ(add, returnVals, 1);
    TEST_ASSERT(add(1,1) == 2);
    TEST_ASSERT(add_fake.arg0_history[0] == 1);
    TEST_ASSERT(add_fake.arg1_history[0] == 1);
}

void test_addTwoNumbersExpectingReturnButIgnoringArguments()
{
    SET_RETURN_SEQ(add, returnVals, 1);
    TEST_ASSERT(add(5,6) == 2);
    TEST_ASSERT_CALLED(add);
}

void test_addingMultingNumbersExpectingDifferentReturnsIgnoringParameters()
{
    SET_RETURN_SEQ(add, returnVals, 3);
    TEST_ASSERT_EQUAL(2, add(1,1));
    TEST_ASSERT_EQUAL(4, add(2,2));
    TEST_ASSERT_EQUAL(6, add(3,3));
    TEST_ASSERT_CALLED_TIMES(3, add);
}