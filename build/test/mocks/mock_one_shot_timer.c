#include <string.h>
#include "fff.h"
#include "mock_one_shot_timer.h"

DEFINE_FAKE_VOID_FUNC4(one_shot_timer_init, one_shot_timer_t*, uint8_t, callback_t, void*)
DEFINE_FAKE_VOID_FUNC1(one_shot_timer_time_did_change, one_shot_timer_t*)

void mock_one_shot_timer_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(one_shot_timer_init)
    RESET_FAKE(one_shot_timer_time_did_change)
}
void mock_one_shot_timer_Verify(void)
{
}
void mock_one_shot_timer_Destroy(void)
{
}
