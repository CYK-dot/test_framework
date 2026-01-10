/**
 * @file FsmTest.h
 * @brief FSM of FsmTest
 * @generator BufferFlowX
**/
#ifndef __BFX_FSMTEST_H__
#define __BFX_FSMTEST_H__

/* headers import ---------------------------------------------------------------------------------------------*/
#include "bfx_fsm.h"

/* state macros -----------------------------------------------------------------------------------------------*/
#define FSMTEST_SETUP 1 // 系统初始化
#define FSMTEST_BOOTLOADER 2 // 加载用户程序
#define FSMTEST_RUNMAIN 3 // 运行主程序
#define FSMTEST_COREDUMP 4 // 打印错误信息并停止程序
#define FSMTEST_RUNMAIN_LEDON 5 // 点亮LED
#define FSMTEST_RUNMAIN_LEDOFF 6 // 熄灭LED
#define FSMTEST_RUNMAIN_DISPLAYOLED 7 // 显示OLED


#define FSMTEST_INITIAL_STATE 1

/* event macros -----------------------------------------------------------------------------------------------*/
#define FSMTEST_SELFCHECKDONE 1
#define FSMTEST_FILELOADED 2
#define FSMTEST_ERROCCUR 3
#define FSMTEST_DUMPFIN 4
#define FSMTEST_TMR200MS 5
#define FSMTEST_BOTTONPRESSED 6
#define FSMTEST_IICINITDONE 7
#define FSMTEST_OLEDINITDONE 8
#define FSMTEST_TEXTUPDATED 9

/* FSM generated ----------------------------------------------------------------------------------------------*/
extern BFX_FSM_HANDLE g_FsmTest_fsmHandle;

/* state callback ---------------------------------------------------------------------------------------------*/

__attribute__((weak)) void BFX_FsmTest_Setup_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Bootloader_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Runmain_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Coredump_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Runmain_Ledon_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Runmain_Ledoff_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
__attribute__((weak)) void BFX_FsmTest_Runmain_Displayoled_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize);
#endif