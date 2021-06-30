#include "src/led.h"
#include "/home/mbraniff/.gem/ruby/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










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



    do {if ((led_read(&led) == 

   0

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(22)));}} while(0);

}



void test_ledCanBeTurnedOnWithWriteFunction(void)

{

    led_init(&led);



    led_write(&led, 

                   1

                     );

    do {if ((led_read(&led) == 

   1

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);

}



void test_ledCanBeTurnedOffWithWriteFunction(void)

{

    led_init(&led);



    led_write(&led, 

                   1

                     );

    led_write(&led, 

                   0

                      );



    do {if ((led_read(&led) == 

   0

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

}
