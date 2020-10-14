/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.h

  @Summary:
    This is the mcc.h file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18877
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45 or later
        MPLAB             :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "adcc.h"
#include "tmr0.h"

#define _XTAL_FREQ  32000000

#define	uint 	unsigned int
#define  uchar 	unsigned char
#define 	ulong 	unsigned long

#define clrwdt		asm("clrwdt")
#define	nop		asm("nop")
#define	reset		asm("reset")

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the device to the default states configured in the
 *                  MCC GUI
 * @Example
    SYSTEM_Initialize(void);
 */
void SYSTEM_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the oscillator to the default states configured in the
 *                  MCC GUI
 * @Example
    OSCILLATOR_Initialize(void);
 */
void OSCILLATOR_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the PMD module to the default states configured in the
 *                  MCC GUI
 * @Example
    PMD_Initialize(void);
 */
void PMD_Initialize(void);

extern bit FLAG_RESET_ALARM,FLAG_QS_MOTOR_IN,FLAG_QS_MOTOR_OUT,FLAG_ES_MOTOR_IN,FLAG_ES_MOTOR_IN_1,FLAG_ES_MOTOR_OUT,FLAG_ALARM_CMD,FLAG_ALARM_RUN;
extern bit FLAG_ALARM,FLAG_OVER_TIME_30S,FLAG_OVER_CURRENT,FLAG_ALARM_OVER1,FLAG_ALARM_OVER2,FLAG_STORED_IN;
extern uchar out_order,out_stop_order,in_order,in_stop_order,ES_in_stop_order,ES_in_order,ES_out_stop_order,ES_out_order,STORED_in_order,STORED_in_stop_order;
extern void INPUT_COLLECT(void);
extern void ALARM_CTRL(void);
extern void MOTOR_CTRL(void);
extern void LED_CTRL(void);
extern uint ad_value_I_TEST;
extern uint I_current,test_time,motor_run_1s;
extern uint led_time_40ms_Test;
#endif	/* MCC_H */
/**
 End of File
*/