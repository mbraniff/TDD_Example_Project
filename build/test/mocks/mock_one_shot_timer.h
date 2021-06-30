#ifndef mock_one_shot_timer_H
#define mock_one_shot_timer_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "one_shot_timer.h"


DECLARE_FAKE_VOID_FUNC4(one_shot_timer_init, one_shot_timer_t*, uint8_t, callback_t, void*)
DECLARE_FAKE_VOID_FUNC1(one_shot_timer_time_did_change, one_shot_timer_t*)

void mock_one_shot_timer_Init(void);
void mock_one_shot_timer_Verify(void);
void mock_one_shot_timer_Destroy(void);

#endif // mock_one_shot_timer_H
