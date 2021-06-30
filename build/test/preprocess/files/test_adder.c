#include "mock_adder.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_addTwoNumbersExpectingReturnAndTwoArguments()

{

    add_CMockExpectAndReturn(15, 1, 1, 2);

    int ret = add(1,1);

    do {if ((ret == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(17)));}} while(0);

}



void test_addTwoNumbersExpectingReturnButIgnoringArguments()

{

    add_CMockIgnoreAndReturn(22, 2);

    int ret = add(5,6);

    do {if ((ret == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(24)));}} while(0);

}
