#include "build/test/mocks/mock_adder.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




int redirect(int arg0, int arg1, int calls)

{

    printf("Called\n");

    return 0;

}



void setUp(void)

{

}



void tearDown(void)

{

}



void test_addTwoNumbersExpectingReturnAndTwoArguments()

{

    add_CMockExpectAndReturn(21, 1, 1, 2);

    int ret = add(1,1);

    do {if ((ret == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(23)));}} while(0);

}



void test_addTwoNumbersExpectingReturnButIgnoringArguments()

{

    add_CMockIgnoreAndReturn(28, 2);

    int ret = add(5,6);

    do {if ((ret == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);

}



void test_addingMultingNumbersExpectingDifferentReturnsIgnoringParameters()

{

    int returnVals[3] = {2,4,6};

    for(int i=0;i<3;i++)

    {

        add_CMockIgnoreAndReturn(38, returnVals[i]);

        UnityAssertEqualNumber((UNITY_INT)((returnVals[i])), (UNITY_INT)((add(1,1))), (

       ((void *)0)

       ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

    }

}



void test_CallbackCalledCorrectly(void)

{

    add_AddCallback(redirect);

    add_CMockExpectAndReturn(46, 1, 1, 2);

    add(1,1);

}



void test_StubCalledRegardless(void)

{

    add_Stub(redirect);

    add_CMockExpectAndReturn(53, 1, 1, 2);

    add(1,2);

}
