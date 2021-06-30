/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_ONE_SHOT_TIMER_H
#define _MOCK_ONE_SHOT_TIMER_H

#include "unity.h"
#include "one_shot_timer.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_one_shot_timer_Init(void);
void mock_one_shot_timer_Destroy(void);
void mock_one_shot_timer_Verify(void);




#define one_shot_timer_init_Ignore() one_shot_timer_init_CMockIgnore()
void one_shot_timer_init_CMockIgnore(void);
#define one_shot_timer_init_StopIgnore() one_shot_timer_init_CMockStopIgnore()
void one_shot_timer_init_CMockStopIgnore(void);
#define one_shot_timer_init_Expect(timer, stop, callback, context) one_shot_timer_init_CMockExpect(__LINE__, timer, stop, callback, context)
void one_shot_timer_init_CMockExpect(UNITY_LINE_TYPE cmock_line, one_shot_timer_t* timer, uint8_t stop, callback_t callback, void* context);
typedef void (* CMOCK_one_shot_timer_init_CALLBACK)(one_shot_timer_t* timer, uint8_t stop, callback_t callback, void* context, int cmock_num_calls);
void one_shot_timer_init_AddCallback(CMOCK_one_shot_timer_init_CALLBACK Callback);
void one_shot_timer_init_Stub(CMOCK_one_shot_timer_init_CALLBACK Callback);
#define one_shot_timer_init_StubWithCallback one_shot_timer_init_Stub
#define one_shot_timer_time_did_change_Ignore() one_shot_timer_time_did_change_CMockIgnore()
void one_shot_timer_time_did_change_CMockIgnore(void);
#define one_shot_timer_time_did_change_StopIgnore() one_shot_timer_time_did_change_CMockStopIgnore()
void one_shot_timer_time_did_change_CMockStopIgnore(void);
#define one_shot_timer_time_did_change_Expect(timer) one_shot_timer_time_did_change_CMockExpect(__LINE__, timer)
void one_shot_timer_time_did_change_CMockExpect(UNITY_LINE_TYPE cmock_line, one_shot_timer_t* timer);
typedef void (* CMOCK_one_shot_timer_time_did_change_CALLBACK)(one_shot_timer_t* timer, int cmock_num_calls);
void one_shot_timer_time_did_change_AddCallback(CMOCK_one_shot_timer_time_did_change_CALLBACK Callback);
void one_shot_timer_time_did_change_Stub(CMOCK_one_shot_timer_time_did_change_CALLBACK Callback);
#define one_shot_timer_time_did_change_StubWithCallback one_shot_timer_time_did_change_Stub
#define one_shot_timer_get_time_Ignore() one_shot_timer_get_time_CMockIgnore()
void one_shot_timer_get_time_CMockIgnore(void);
#define one_shot_timer_get_time_StopIgnore() one_shot_timer_get_time_CMockStopIgnore()
void one_shot_timer_get_time_CMockStopIgnore(void);
#define one_shot_timer_get_time_Expect(timer) one_shot_timer_get_time_CMockExpect(__LINE__, timer)
void one_shot_timer_get_time_CMockExpect(UNITY_LINE_TYPE cmock_line, one_shot_timer_t* timer);
typedef void (* CMOCK_one_shot_timer_get_time_CALLBACK)(one_shot_timer_t* timer, int cmock_num_calls);
void one_shot_timer_get_time_AddCallback(CMOCK_one_shot_timer_get_time_CALLBACK Callback);
void one_shot_timer_get_time_Stub(CMOCK_one_shot_timer_get_time_CALLBACK Callback);
#define one_shot_timer_get_time_StubWithCallback one_shot_timer_get_time_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
