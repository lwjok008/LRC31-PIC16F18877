#ifndef	_HEAD_H
#define	_HEAD_H

#define	uint 	unsigned int
#define  uchar 	unsigned char
#define 	ulong 	unsigned long

#define clrwdt		asm("clrwdt")
#define	nop		asm("nop")


#include "hal.h"
#include	"function.h"
//#include "const.h"
#include "var.h"
#include "font_library.h"
extern void MOTOR_CURRENT_COLLECT(void);
extern bit flag_pressA_NG,flag_pressB_NG,flag_pressC_NG;
extern uint A_CLOSE_counter,B_CLOSE_counter,C_CLOSE_counter;
extern uint A_RUN_counter,B_RUN_counter,C_RUN_counter;
extern uint A_RUN_counter_120S,B_RUN_counter_120S,C_RUN_counter_120S;
extern uint A_RUN_counter_24H,B_RUN_counter_24H,C_RUN_counter_24H;
//extern bit flag_TIMEA_NG,flag_TIMEB_NG,flag_TIMEC_NG;
extern bit flag_COUNTA_NG,flag_COUNTB_NG,flag_COUNTC_NG;
//extern bit flag_COUNTA_NG_disp,flag_COUNTB_NG_disp,flag_COUNTC_NG_disp;
extern bit flag_runA,flag_runB,flag_runC;
extern uint A_current,B_current,C_current;
extern bit flag_page10_set1,flag_page10_set2;
extern bit flag_motorA_RUN,flag_motorB_RUN,flag_motorC_RUN;
extern bit flag_A_RUN_120S,flag_B_RUN_120S,flag_C_RUN_120S;
extern bit flag_A_RUN_120S_disp,flag_B_RUN_120S_disp,flag_C_RUN_120S_disp;
extern bit FLAG_ALL_RESET,FLAG_ALARM_RESET;

extern uint counter_timerAA[20];
extern uint counter_timerBB[20];
extern uint counter_timerCC[20];
extern uint counter_timerA,counter_timerB,counter_timerC;
//extern uint A_RUN_counterA;
typedef union 
{
	uchar Byte;
	struct 
	{
    	unsigned  BIT0:1; 
        unsigned  BIT1:1; 
        unsigned  BIT2:1; 
        unsigned  BIT3:1; 
        unsigned  BIT4:1; 
        unsigned  BIT5:1; 
        unsigned  BIT6:1; 
        unsigned  BIT7:1; 
    } Bits;
}BYTE_BITS;
#endif













