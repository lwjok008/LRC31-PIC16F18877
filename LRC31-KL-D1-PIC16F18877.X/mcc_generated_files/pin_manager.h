/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18877
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set I_TEST_AD_IN aliases
#define I_TEST_AD_IN_TRIS                 TRISAbits.TRISA0
#define I_TEST_AD_IN_LAT                  LATAbits.LATA0
#define I_TEST_AD_IN_PORT                 PORTAbits.RA0
#define I_TEST_AD_IN_WPU                  WPUAbits.WPUA0
#define I_TEST_AD_IN_OD                   ODCONAbits.ODCA0
#define I_TEST_AD_IN_ANS                  ANSELAbits.ANSA0
#define I_TEST_AD_IN_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define I_TEST_AD_IN_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define I_TEST_AD_IN_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define I_TEST_AD_IN_GetValue()           PORTAbits.RA0
#define I_TEST_AD_IN_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define I_TEST_AD_IN_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define I_TEST_AD_IN_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define I_TEST_AD_IN_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define I_TEST_AD_IN_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define I_TEST_AD_IN_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define I_TEST_AD_IN_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define I_TEST_AD_IN_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RELAY_LOCK aliases
#define RELAY_LOCK_TRIS                 TRISAbits.TRISA2
#define RELAY_LOCK_LAT                  LATAbits.LATA2
#define RELAY_LOCK_PORT                 PORTAbits.RA2
#define RELAY_LOCK_WPU                  WPUAbits.WPUA2
#define RELAY_LOCK_OD                   ODCONAbits.ODCA2
#define RELAY_LOCK_ANS                  ANSELAbits.ANSA2
#define RELAY_LOCK_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RELAY_LOCK_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RELAY_LOCK_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RELAY_LOCK_GetValue()           PORTAbits.RA2
#define RELAY_LOCK_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RELAY_LOCK_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RELAY_LOCK_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define RELAY_LOCK_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define RELAY_LOCK_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define RELAY_LOCK_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define RELAY_LOCK_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define RELAY_LOCK_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set NC_RA3 aliases
#define NC_RA3_TRIS                 TRISAbits.TRISA3
#define NC_RA3_LAT                  LATAbits.LATA3
#define NC_RA3_PORT                 PORTAbits.RA3
#define NC_RA3_WPU                  WPUAbits.WPUA3
#define NC_RA3_OD                   ODCONAbits.ODCA3
#define NC_RA3_ANS                  ANSELAbits.ANSA3
#define NC_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define NC_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define NC_RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define NC_RA3_GetValue()           PORTAbits.RA3
#define NC_RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define NC_RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define NC_RA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define NC_RA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define NC_RA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define NC_RA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define NC_RA3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define NC_RA3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RELAY_QS_P aliases
#define RELAY_QS_P_TRIS                 TRISAbits.TRISA4
#define RELAY_QS_P_LAT                  LATAbits.LATA4
#define RELAY_QS_P_PORT                 PORTAbits.RA4
#define RELAY_QS_P_WPU                  WPUAbits.WPUA4
#define RELAY_QS_P_OD                   ODCONAbits.ODCA4
#define RELAY_QS_P_ANS                  ANSELAbits.ANSA4
#define RELAY_QS_P_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RELAY_QS_P_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RELAY_QS_P_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RELAY_QS_P_GetValue()           PORTAbits.RA4
#define RELAY_QS_P_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RELAY_QS_P_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RELAY_QS_P_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RELAY_QS_P_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RELAY_QS_P_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RELAY_QS_P_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RELAY_QS_P_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RELAY_QS_P_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RELAY_QS_N aliases
#define RELAY_QS_N_TRIS                 TRISAbits.TRISA5
#define RELAY_QS_N_LAT                  LATAbits.LATA5
#define RELAY_QS_N_PORT                 PORTAbits.RA5
#define RELAY_QS_N_WPU                  WPUAbits.WPUA5
#define RELAY_QS_N_OD                   ODCONAbits.ODCA5
#define RELAY_QS_N_ANS                  ANSELAbits.ANSA5
#define RELAY_QS_N_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RELAY_QS_N_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RELAY_QS_N_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RELAY_QS_N_GetValue()           PORTAbits.RA5
#define RELAY_QS_N_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RELAY_QS_N_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RELAY_QS_N_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RELAY_QS_N_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RELAY_QS_N_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RELAY_QS_N_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RELAY_QS_N_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define RELAY_QS_N_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_RA6 aliases
#define IO_RA6_TRIS                 TRISAbits.TRISA6
#define IO_RA6_LAT                  LATAbits.LATA6
#define IO_RA6_PORT                 PORTAbits.RA6
#define IO_RA6_WPU                  WPUAbits.WPUA6
#define IO_RA6_OD                   ODCONAbits.ODCA6
#define IO_RA6_ANS                  ANSELAbits.ANSA6
#define IO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_RA6_GetValue()           PORTAbits.RA6
#define IO_RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_RA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_RA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_RA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_RA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_RA6_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define IO_RA6_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_RA7 aliases
#define IO_RA7_TRIS                 TRISAbits.TRISA7
#define IO_RA7_LAT                  LATAbits.LATA7
#define IO_RA7_PORT                 PORTAbits.RA7
#define IO_RA7_WPU                  WPUAbits.WPUA7
#define IO_RA7_OD                   ODCONAbits.ODCA7
#define IO_RA7_ANS                  ANSELAbits.ANSA7
#define IO_RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_RA7_GetValue()           PORTAbits.RA7
#define IO_RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_RA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_RA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_RA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_RA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_RA7_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define IO_RA7_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set NC_RB0 aliases
#define NC_RB0_TRIS                 TRISBbits.TRISB0
#define NC_RB0_LAT                  LATBbits.LATB0
#define NC_RB0_PORT                 PORTBbits.RB0
#define NC_RB0_WPU                  WPUBbits.WPUB0
#define NC_RB0_OD                   ODCONBbits.ODCB0
#define NC_RB0_ANS                  ANSELBbits.ANSB0
#define NC_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define NC_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define NC_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define NC_RB0_GetValue()           PORTBbits.RB0
#define NC_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define NC_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define NC_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define NC_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define NC_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define NC_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define NC_RB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define NC_RB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set LOCK_CLOSE_IN aliases
#define LOCK_CLOSE_IN_TRIS                 TRISBbits.TRISB1
#define LOCK_CLOSE_IN_LAT                  LATBbits.LATB1
#define LOCK_CLOSE_IN_PORT                 PORTBbits.RB1
#define LOCK_CLOSE_IN_WPU                  WPUBbits.WPUB1
#define LOCK_CLOSE_IN_OD                   ODCONBbits.ODCB1
#define LOCK_CLOSE_IN_ANS                  ANSELBbits.ANSB1
#define LOCK_CLOSE_IN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LOCK_CLOSE_IN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LOCK_CLOSE_IN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LOCK_CLOSE_IN_GetValue()           PORTBbits.RB1
#define LOCK_CLOSE_IN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LOCK_CLOSE_IN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LOCK_CLOSE_IN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LOCK_CLOSE_IN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LOCK_CLOSE_IN_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LOCK_CLOSE_IN_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LOCK_CLOSE_IN_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define LOCK_CLOSE_IN_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set CMD_CLOSE_IN aliases
#define CMD_CLOSE_IN_TRIS                 TRISBbits.TRISB2
#define CMD_CLOSE_IN_LAT                  LATBbits.LATB2
#define CMD_CLOSE_IN_PORT                 PORTBbits.RB2
#define CMD_CLOSE_IN_WPU                  WPUBbits.WPUB2
#define CMD_CLOSE_IN_OD                   ODCONBbits.ODCB2
#define CMD_CLOSE_IN_ANS                  ANSELBbits.ANSB2
#define CMD_CLOSE_IN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define CMD_CLOSE_IN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define CMD_CLOSE_IN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define CMD_CLOSE_IN_GetValue()           PORTBbits.RB2
#define CMD_CLOSE_IN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define CMD_CLOSE_IN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define CMD_CLOSE_IN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define CMD_CLOSE_IN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define CMD_CLOSE_IN_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define CMD_CLOSE_IN_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define CMD_CLOSE_IN_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define CMD_CLOSE_IN_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set CMD_RESET_IN aliases
#define CMD_RESET_IN_TRIS                 TRISBbits.TRISB3
#define CMD_RESET_IN_LAT                  LATBbits.LATB3
#define CMD_RESET_IN_PORT                 PORTBbits.RB3
#define CMD_RESET_IN_WPU                  WPUBbits.WPUB3
#define CMD_RESET_IN_OD                   ODCONBbits.ODCB3
#define CMD_RESET_IN_ANS                  ANSELBbits.ANSB3
#define CMD_RESET_IN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define CMD_RESET_IN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define CMD_RESET_IN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define CMD_RESET_IN_GetValue()           PORTBbits.RB3
#define CMD_RESET_IN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define CMD_RESET_IN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define CMD_RESET_IN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define CMD_RESET_IN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define CMD_RESET_IN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define CMD_RESET_IN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define CMD_RESET_IN_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define CMD_RESET_IN_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set CMD_OPEN_IN aliases
#define CMD_OPEN_IN_TRIS                 TRISBbits.TRISB4
#define CMD_OPEN_IN_LAT                  LATBbits.LATB4
#define CMD_OPEN_IN_PORT                 PORTBbits.RB4
#define CMD_OPEN_IN_WPU                  WPUBbits.WPUB4
#define CMD_OPEN_IN_OD                   ODCONBbits.ODCB4
#define CMD_OPEN_IN_ANS                  ANSELBbits.ANSB4
#define CMD_OPEN_IN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define CMD_OPEN_IN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define CMD_OPEN_IN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define CMD_OPEN_IN_GetValue()           PORTBbits.RB4
#define CMD_OPEN_IN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define CMD_OPEN_IN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define CMD_OPEN_IN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define CMD_OPEN_IN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define CMD_OPEN_IN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define CMD_OPEN_IN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define CMD_OPEN_IN_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define CMD_OPEN_IN_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set PROTECT_CMD_OFF_IN aliases
#define PROTECT_CMD_OFF_IN_TRIS                 TRISBbits.TRISB5
#define PROTECT_CMD_OFF_IN_LAT                  LATBbits.LATB5
#define PROTECT_CMD_OFF_IN_PORT                 PORTBbits.RB5
#define PROTECT_CMD_OFF_IN_WPU                  WPUBbits.WPUB5
#define PROTECT_CMD_OFF_IN_OD                   ODCONBbits.ODCB5
#define PROTECT_CMD_OFF_IN_ANS                  ANSELBbits.ANSB5
#define PROTECT_CMD_OFF_IN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define PROTECT_CMD_OFF_IN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define PROTECT_CMD_OFF_IN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define PROTECT_CMD_OFF_IN_GetValue()           PORTBbits.RB5
#define PROTECT_CMD_OFF_IN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define PROTECT_CMD_OFF_IN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define PROTECT_CMD_OFF_IN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define PROTECT_CMD_OFF_IN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define PROTECT_CMD_OFF_IN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define PROTECT_CMD_OFF_IN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define PROTECT_CMD_OFF_IN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define PROTECT_CMD_OFF_IN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set NC6 aliases
#define NC6_TRIS                 TRISBbits.TRISB6
#define NC6_LAT                  LATBbits.LATB6
#define NC6_PORT                 PORTBbits.RB6
#define NC6_WPU                  WPUBbits.WPUB6
#define NC6_OD                   ODCONBbits.ODCB6
#define NC6_ANS                  ANSELBbits.ANSB6
#define NC6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define NC6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define NC6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define NC6_GetValue()           PORTBbits.RB6
#define NC6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define NC6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define NC6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define NC6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define NC6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define NC6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define NC6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define NC6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set NC7 aliases
#define NC7_TRIS                 TRISBbits.TRISB7
#define NC7_LAT                  LATBbits.LATB7
#define NC7_PORT                 PORTBbits.RB7
#define NC7_WPU                  WPUBbits.WPUB7
#define NC7_OD                   ODCONBbits.ODCB7
#define NC7_ANS                  ANSELBbits.ANSB7
#define NC7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define NC7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define NC7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define NC7_GetValue()           PORTBbits.RB7
#define NC7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define NC7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define NC7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define NC7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define NC7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define NC7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define NC7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define NC7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set P_OPEN_IN aliases
#define P_OPEN_IN_TRIS                 TRISCbits.TRISC0
#define P_OPEN_IN_LAT                  LATCbits.LATC0
#define P_OPEN_IN_PORT                 PORTCbits.RC0
#define P_OPEN_IN_WPU                  WPUCbits.WPUC0
#define P_OPEN_IN_OD                   ODCONCbits.ODCC0
#define P_OPEN_IN_ANS                  ANSELCbits.ANSC0
#define P_OPEN_IN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define P_OPEN_IN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define P_OPEN_IN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define P_OPEN_IN_GetValue()           PORTCbits.RC0
#define P_OPEN_IN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define P_OPEN_IN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define P_OPEN_IN_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define P_OPEN_IN_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define P_OPEN_IN_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define P_OPEN_IN_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define P_OPEN_IN_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define P_OPEN_IN_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set P_CLOSE_IN aliases
#define P_CLOSE_IN_TRIS                 TRISCbits.TRISC1
#define P_CLOSE_IN_LAT                  LATCbits.LATC1
#define P_CLOSE_IN_PORT                 PORTCbits.RC1
#define P_CLOSE_IN_WPU                  WPUCbits.WPUC1
#define P_CLOSE_IN_OD                   ODCONCbits.ODCC1
#define P_CLOSE_IN_ANS                  ANSELCbits.ANSC1
#define P_CLOSE_IN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define P_CLOSE_IN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define P_CLOSE_IN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define P_CLOSE_IN_GetValue()           PORTCbits.RC1
#define P_CLOSE_IN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define P_CLOSE_IN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define P_CLOSE_IN_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define P_CLOSE_IN_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define P_CLOSE_IN_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define P_CLOSE_IN_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define P_CLOSE_IN_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define P_CLOSE_IN_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set P_STORED_IN aliases
#define P_STORED_IN_TRIS                 TRISCbits.TRISC2
#define P_STORED_IN_LAT                  LATCbits.LATC2
#define P_STORED_IN_PORT                 PORTCbits.RC2
#define P_STORED_IN_WPU                  WPUCbits.WPUC2
#define P_STORED_IN_OD                   ODCONCbits.ODCC2
#define P_STORED_IN_ANS                  ANSELCbits.ANSC2
#define P_STORED_IN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define P_STORED_IN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define P_STORED_IN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define P_STORED_IN_GetValue()           PORTCbits.RC2
#define P_STORED_IN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define P_STORED_IN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define P_STORED_IN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define P_STORED_IN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define P_STORED_IN_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define P_STORED_IN_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define P_STORED_IN_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define P_STORED_IN_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set MOS_QS_N aliases
#define MOS_QS_N_TRIS                 TRISCbits.TRISC3
#define MOS_QS_N_LAT                  LATCbits.LATC3
#define MOS_QS_N_PORT                 PORTCbits.RC3
#define MOS_QS_N_WPU                  WPUCbits.WPUC3
#define MOS_QS_N_OD                   ODCONCbits.ODCC3
#define MOS_QS_N_ANS                  ANSELCbits.ANSC3
#define MOS_QS_N_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define MOS_QS_N_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define MOS_QS_N_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define MOS_QS_N_GetValue()           PORTCbits.RC3
#define MOS_QS_N_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define MOS_QS_N_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define MOS_QS_N_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define MOS_QS_N_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define MOS_QS_N_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define MOS_QS_N_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define MOS_QS_N_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define MOS_QS_N_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RELAY_STORED aliases
#define RELAY_STORED_TRIS                 TRISCbits.TRISC4
#define RELAY_STORED_LAT                  LATCbits.LATC4
#define RELAY_STORED_PORT                 PORTCbits.RC4
#define RELAY_STORED_WPU                  WPUCbits.WPUC4
#define RELAY_STORED_OD                   ODCONCbits.ODCC4
#define RELAY_STORED_ANS                  ANSELCbits.ANSC4
#define RELAY_STORED_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RELAY_STORED_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RELAY_STORED_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RELAY_STORED_GetValue()           PORTCbits.RC4
#define RELAY_STORED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RELAY_STORED_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RELAY_STORED_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define RELAY_STORED_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define RELAY_STORED_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define RELAY_STORED_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define RELAY_STORED_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define RELAY_STORED_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RE_DE aliases
#define RE_DE_TRIS                 TRISCbits.TRISC5
#define RE_DE_LAT                  LATCbits.LATC5
#define RE_DE_PORT                 PORTCbits.RC5
#define RE_DE_WPU                  WPUCbits.WPUC5
#define RE_DE_OD                   ODCONCbits.ODCC5
#define RE_DE_ANS                  ANSELCbits.ANSC5
#define RE_DE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RE_DE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RE_DE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RE_DE_GetValue()           PORTCbits.RC5
#define RE_DE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RE_DE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RE_DE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RE_DE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RE_DE_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define RE_DE_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define RE_DE_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define RE_DE_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set NC3 aliases
#define NC3_TRIS                 TRISCbits.TRISC6
#define NC3_LAT                  LATCbits.LATC6
#define NC3_PORT                 PORTCbits.RC6
#define NC3_WPU                  WPUCbits.WPUC6
#define NC3_OD                   ODCONCbits.ODCC6
#define NC3_ANS                  ANSELCbits.ANSC6
#define NC3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define NC3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define NC3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define NC3_GetValue()           PORTCbits.RC6
#define NC3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define NC3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define NC3_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define NC3_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define NC3_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define NC3_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define NC3_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define NC3_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RELAY_ALARM aliases
#define RELAY_ALARM_TRIS                 TRISDbits.TRISD0
#define RELAY_ALARM_LAT                  LATDbits.LATD0
#define RELAY_ALARM_PORT                 PORTDbits.RD0
#define RELAY_ALARM_WPU                  WPUDbits.WPUD0
#define RELAY_ALARM_OD                   ODCONDbits.ODCD0
#define RELAY_ALARM_ANS                  ANSELDbits.ANSD0
#define RELAY_ALARM_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RELAY_ALARM_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RELAY_ALARM_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RELAY_ALARM_GetValue()           PORTDbits.RD0
#define RELAY_ALARM_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RELAY_ALARM_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RELAY_ALARM_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define RELAY_ALARM_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define RELAY_ALARM_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define RELAY_ALARM_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define RELAY_ALARM_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define RELAY_ALARM_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RELAY_Y1 aliases
#define RELAY_Y1_TRIS                 TRISDbits.TRISD1
#define RELAY_Y1_LAT                  LATDbits.LATD1
#define RELAY_Y1_PORT                 PORTDbits.RD1
#define RELAY_Y1_WPU                  WPUDbits.WPUD1
#define RELAY_Y1_OD                   ODCONDbits.ODCD1
#define RELAY_Y1_ANS                  ANSELDbits.ANSD1
#define RELAY_Y1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RELAY_Y1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RELAY_Y1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RELAY_Y1_GetValue()           PORTDbits.RD1
#define RELAY_Y1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RELAY_Y1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RELAY_Y1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define RELAY_Y1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define RELAY_Y1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define RELAY_Y1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define RELAY_Y1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define RELAY_Y1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RELAY_Y2 aliases
#define RELAY_Y2_TRIS                 TRISDbits.TRISD2
#define RELAY_Y2_LAT                  LATDbits.LATD2
#define RELAY_Y2_PORT                 PORTDbits.RD2
#define RELAY_Y2_WPU                  WPUDbits.WPUD2
#define RELAY_Y2_OD                   ODCONDbits.ODCD2
#define RELAY_Y2_ANS                  ANSELDbits.ANSD2
#define RELAY_Y2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RELAY_Y2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RELAY_Y2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RELAY_Y2_GetValue()           PORTDbits.RD2
#define RELAY_Y2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RELAY_Y2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RELAY_Y2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define RELAY_Y2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define RELAY_Y2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define RELAY_Y2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define RELAY_Y2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define RELAY_Y2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set RELAY_REV aliases
#define RELAY_REV_TRIS                 TRISDbits.TRISD3
#define RELAY_REV_LAT                  LATDbits.LATD3
#define RELAY_REV_PORT                 PORTDbits.RD3
#define RELAY_REV_WPU                  WPUDbits.WPUD3
#define RELAY_REV_OD                   ODCONDbits.ODCD3
#define RELAY_REV_ANS                  ANSELDbits.ANSD3
#define RELAY_REV_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RELAY_REV_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RELAY_REV_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RELAY_REV_GetValue()           PORTDbits.RD3
#define RELAY_REV_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RELAY_REV_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RELAY_REV_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define RELAY_REV_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define RELAY_REV_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define RELAY_REV_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define RELAY_REV_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define RELAY_REV_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set MOS_Y1 aliases
#define MOS_Y1_TRIS                 TRISDbits.TRISD4
#define MOS_Y1_LAT                  LATDbits.LATD4
#define MOS_Y1_PORT                 PORTDbits.RD4
#define MOS_Y1_WPU                  WPUDbits.WPUD4
#define MOS_Y1_OD                   ODCONDbits.ODCD4
#define MOS_Y1_ANS                  ANSELDbits.ANSD4
#define MOS_Y1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define MOS_Y1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define MOS_Y1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define MOS_Y1_GetValue()           PORTDbits.RD4
#define MOS_Y1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define MOS_Y1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define MOS_Y1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define MOS_Y1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define MOS_Y1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define MOS_Y1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define MOS_Y1_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define MOS_Y1_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set MOS_Y2 aliases
#define MOS_Y2_TRIS                 TRISDbits.TRISD5
#define MOS_Y2_LAT                  LATDbits.LATD5
#define MOS_Y2_PORT                 PORTDbits.RD5
#define MOS_Y2_WPU                  WPUDbits.WPUD5
#define MOS_Y2_OD                   ODCONDbits.ODCD5
#define MOS_Y2_ANS                  ANSELDbits.ANSD5
#define MOS_Y2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define MOS_Y2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define MOS_Y2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define MOS_Y2_GetValue()           PORTDbits.RD5
#define MOS_Y2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define MOS_Y2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define MOS_Y2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define MOS_Y2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define MOS_Y2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define MOS_Y2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define MOS_Y2_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define MOS_Y2_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set MOS_REV aliases
#define MOS_REV_TRIS                 TRISDbits.TRISD6
#define MOS_REV_LAT                  LATDbits.LATD6
#define MOS_REV_PORT                 PORTDbits.RD6
#define MOS_REV_WPU                  WPUDbits.WPUD6
#define MOS_REV_OD                   ODCONDbits.ODCD6
#define MOS_REV_ANS                  ANSELDbits.ANSD6
#define MOS_REV_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define MOS_REV_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define MOS_REV_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define MOS_REV_GetValue()           PORTDbits.RD6
#define MOS_REV_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define MOS_REV_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define MOS_REV_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define MOS_REV_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define MOS_REV_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define MOS_REV_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define MOS_REV_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define MOS_REV_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set MOS_STORED aliases
#define MOS_STORED_TRIS                 TRISDbits.TRISD7
#define MOS_STORED_LAT                  LATDbits.LATD7
#define MOS_STORED_PORT                 PORTDbits.RD7
#define MOS_STORED_WPU                  WPUDbits.WPUD7
#define MOS_STORED_OD                   ODCONDbits.ODCD7
#define MOS_STORED_ANS                  ANSELDbits.ANSD7
#define MOS_STORED_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define MOS_STORED_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define MOS_STORED_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define MOS_STORED_GetValue()           PORTDbits.RD7
#define MOS_STORED_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define MOS_STORED_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define MOS_STORED_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define MOS_STORED_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define MOS_STORED_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define MOS_STORED_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define MOS_STORED_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define MOS_STORED_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set RELAY_ES_P aliases
#define RELAY_ES_P_TRIS                 TRISEbits.TRISE0
#define RELAY_ES_P_LAT                  LATEbits.LATE0
#define RELAY_ES_P_PORT                 PORTEbits.RE0
#define RELAY_ES_P_WPU                  WPUEbits.WPUE0
#define RELAY_ES_P_OD                   ODCONEbits.ODCE0
#define RELAY_ES_P_ANS                  ANSELEbits.ANSE0
#define RELAY_ES_P_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define RELAY_ES_P_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define RELAY_ES_P_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define RELAY_ES_P_GetValue()           PORTEbits.RE0
#define RELAY_ES_P_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define RELAY_ES_P_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define RELAY_ES_P_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define RELAY_ES_P_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define RELAY_ES_P_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define RELAY_ES_P_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define RELAY_ES_P_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define RELAY_ES_P_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set RELAY_ES_N aliases
#define RELAY_ES_N_TRIS                 TRISEbits.TRISE1
#define RELAY_ES_N_LAT                  LATEbits.LATE1
#define RELAY_ES_N_PORT                 PORTEbits.RE1
#define RELAY_ES_N_WPU                  WPUEbits.WPUE1
#define RELAY_ES_N_OD                   ODCONEbits.ODCE1
#define RELAY_ES_N_ANS                  ANSELEbits.ANSE1
#define RELAY_ES_N_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define RELAY_ES_N_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define RELAY_ES_N_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define RELAY_ES_N_GetValue()           PORTEbits.RE1
#define RELAY_ES_N_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define RELAY_ES_N_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define RELAY_ES_N_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define RELAY_ES_N_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define RELAY_ES_N_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define RELAY_ES_N_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define RELAY_ES_N_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define RELAY_ES_N_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set LED_ALARM aliases
#define LED_ALARM_TRIS                 TRISEbits.TRISE2
#define LED_ALARM_LAT                  LATEbits.LATE2
#define LED_ALARM_PORT                 PORTEbits.RE2
#define LED_ALARM_WPU                  WPUEbits.WPUE2
#define LED_ALARM_OD                   ODCONEbits.ODCE2
#define LED_ALARM_ANS                  ANSELEbits.ANSE2
#define LED_ALARM_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_ALARM_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_ALARM_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_ALARM_GetValue()           PORTEbits.RE2
#define LED_ALARM_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_ALARM_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_ALARM_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LED_ALARM_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LED_ALARM_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define LED_ALARM_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define LED_ALARM_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define LED_ALARM_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/