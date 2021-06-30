#include "src/TurnOnLED.h"
#include "build/test/mocks/mock_Timer.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_LED_is_off(void)

{

    

   _Bool 

        is_on = LED(0);

    do {if ((is_on == 

   0

   )) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

}
