#include "build/test/mocks/mock_adder.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




int returnVals[3] = {2,4,6};



void setUp(void)

{

}



void tearDown(void)

{

}



void test_addTwoNumbersExpectingReturnAndTwoArguments()

{

    add_fake.return_val_seq = returnVals; add_fake.return_val_seq_len = 1;;

    do {if ((add(1,1) == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(18)));}} while(0);

    do {if ((add_fake.arg0_history[0] == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(19)));}} while(0);

    do {if ((add_fake.arg1_history[0] == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(20)));}} while(0);

}



void test_addTwoNumbersExpectingReturnButIgnoringArguments()

{

    add_fake.return_val_seq = returnVals; add_fake.return_val_seq_len = 1;;

    do {if ((add(5,6) == 2)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(26)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((add_fake.call_count)), (("Function " "add" " called the incorrect number of times.")), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

}



void test_addingMultingNumbersExpectingDifferentReturnsIgnoringParameters()

{

    add_fake.return_val_seq = returnVals; add_fake.return_val_seq_len = 3;;

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((add(1,1))), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((add(2,2))), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((add(3,3))), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((add_fake.call_count)), (("Function " "add" " called the incorrect number of times.")), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}
