/**
 * @file FsmTest.c
 * @brief FSM of FsmTest
 * @generator BufferFlowX
**/
#ifdef __cplusplus
extern "C" {
#endif
/* headers import ---------------------------------------------------------------------------------------------*/
#include <stddef.h>
#include "FsmTest.h"

/* state callback ---------------------------------------------------------------------------------------------*/

__attribute__((weak)) void BFX_FsmTest_Setup_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Bootloader_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Runmain_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Coredump_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Runmain_Ledon_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Runmain_Ledoff_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}
__attribute__((weak)) void BFX_FsmTest_Runmain_Displayoled_ActionCb(BFX_FSM_ACTION_CTX *ctx, void *arg, uint16_t argSize)
{
}

/* state table ------------------------------------------------------------------------------------------------*/
const BFX_FSM_TRAN_RECORD g_FsmTest_setup_TransTbl[] = {
    { FSMTEST_SELFCHECKDONE, FSMTEST_BOOTLOADER }, ///< 自检完成
    
};
const BFX_FSM_TRAN_RECORD g_FsmTest_bootloader_TransTbl[] = {
    { FSMTEST_FILELOADED, FSMTEST_RUNMAIN }, ///< 文件加载完成
    { FSMTEST_ERROCCUR, FSMTEST_COREDUMP }, ///< 校验错误
    { FSMTEST_ERROCCUR, FSMTEST_COREDUMP }, ///< 加载错误
    
};
const BFX_FSM_TRAN_RECORD g_FsmTest_runmain_TransTbl[] = {
    { FSMTEST_ERROCCUR, FSMTEST_COREDUMP }, ///< 主程序运行错误
    
};
const BFX_FSM_TRAN_RECORD g_FsmTest_coredump_TransTbl[] = {
    { FSMTEST_DUMPFIN, 0 },
    
};
const BFX_FSM_TRAN_RECORD g_FsmTest_runmain_ledon_TransTbl[] = {
    { FSMTEST_TMR200MS, FSMTEST_RUNMAIN_LEDOFF }, ///< 200ms定时器超时
    { FSMTEST_BOTTONPRESSED, FSMTEST_RUNMAIN_DISPLAYOLED }, ///< 按钮按下
    
};
const BFX_FSM_TRAN_RECORD g_FsmTest_runmain_ledoff_TransTbl[] = {
    { FSMTEST_TMR200MS, FSMTEST_RUNMAIN_LEDON }, ///< 200ms定时器超时
    { FSMTEST_BOTTONPRESSED, FSMTEST_RUNMAIN_DISPLAYOLED }, ///< 按钮按下
    
};

const BFX_FSM_STATE g_FsmTest_allstatus[] = {
    {
        FSMTEST_SETUP, FSMTEST_SETUP, BFX_STATUS_FATHER_NONE,
        sizeof(g_FsmTest_setup_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_setup_TransTbl,
        BFX_FsmTest_Setup_ActionCb
    },
    {
        FSMTEST_BOOTLOADER, FSMTEST_BOOTLOADER, BFX_STATUS_FATHER_NONE,
        sizeof(g_FsmTest_bootloader_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_bootloader_TransTbl,
        BFX_FsmTest_Bootloader_ActionCb
    },
    {
        FSMTEST_RUNMAIN, FSMTEST_RUNMAIN_LEDON, BFX_STATUS_FATHER_NONE,
        sizeof(g_FsmTest_runmain_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_runmain_TransTbl,
        BFX_FsmTest_Runmain_ActionCb
    },
    {
        FSMTEST_COREDUMP, FSMTEST_COREDUMP, BFX_STATUS_FATHER_NONE,
        sizeof(g_FsmTest_coredump_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_coredump_TransTbl,
        BFX_FsmTest_Coredump_ActionCb
    },
    {
        FSMTEST_RUNMAIN_LEDON, FSMTEST_RUNMAIN_LEDON, FSMTEST_RUNMAIN,
        sizeof(g_FsmTest_runmain_ledon_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_runmain_ledon_TransTbl,
        BFX_FsmTest_Runmain_Ledon_ActionCb
    },
    {
        FSMTEST_RUNMAIN_LEDOFF, FSMTEST_RUNMAIN_LEDOFF, FSMTEST_RUNMAIN,
        sizeof(g_FsmTest_runmain_ledoff_TransTbl) / sizeof(BFX_FSM_TRAN_RECORD), g_FsmTest_runmain_ledoff_TransTbl,
        BFX_FsmTest_Runmain_Ledoff_ActionCb
    },
    {
        FSMTEST_RUNMAIN_DISPLAYOLED, FSMTEST_RUNMAIN_DISPLAYOLED, FSMTEST_RUNMAIN,
        0, (BFX_FSM_TRAN_RECORD const *)NULL,
        BFX_FsmTest_Runmain_Displayoled_ActionCb
    }
    
};
/* FSM handle -------------------------------------------------------------------------------------------------*/
BFX_FSM_HANDLE g_FsmTest_fsmHandle = {
    .stateTbl = g_FsmTest_allstatus,
    .stateCnt = sizeof(g_FsmTest_allstatus) / sizeof(BFX_FSM_STATE),
    .currentStateId = FSMTEST_INITIAL_STATE,
};
#ifdef __cplusplus
}
#endif