/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18877
        Driver Version    :  2.00
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
#include "mcc_generated_files/mcc.h"
#define S1  LOCK_CLOSE_IN_PORT
#define S2  CMD_CLOSE_IN_PORT
#define S3  CMD_OPEN_IN_PORT
#define S4  P_STORED_IN_PORT
#define S5  P_CLOSE_IN_PORT
#define S6  P_OPEN_IN_PORT
#define S7  CMD_RESET_IN_PORT
#define S8  PROTECT_CMD_OFF_IN_PORT
#define I_AD_CONST 112      //56=1.5A@200mΩ,155=1.5A@500mΩ,计算公式：（0.1*I）/5*1024 112=3A
#define I_MAX_AD_CONST 336      //3倍I_AD_CONST
//#define S3  CMD_ES_CLOSE_IN_PORT
//#define S4  CMD_ES_OPEN_IN_PORT
//#define S7  P_QS_CLOSE_IN_PORT
//#define S10  P_ES_CLOSE_IN_PORT
//#define S13  LOCK_CLOSE_IN_PORT
//#define S15  LOCK_QS_IN_PORT
//#define S16  LOCK_ES_IN_PORT
//#define S17  P_ES_OPEN_IN_PORT
//#define S33  LOCK_ES_CLOSE_IN_PORT  //主母线带电信号

uchar motor_do_time;
uint ad_value_I_TEST;
uint ad_value[20]={0},sum_value;
uint test_time,motor_run_1s;
bit FLAG_OVER_TIME_30S,FLAG_OVER_CURRENT,flag_overload_out,flag_overload_in,flag_overload_in_ES,flag_overload_out_ES;
uint overload_time_out,overload_time_in,overload_time_out_ES,overload_time_in_ES;
void  delayus(uchar x);
void  delay(uint x);
uchar i_avg;
uint ad_value_I_TEST_avg;
uchar time_2ms_12=0,time_2ms_13=0;
void main(void)
{
    delay(1); //106.625us
    sum_value=0;
    i_avg=0;
    // initialize the device
    SYSTEM_Initialize();
    test_time=0;
    motor_run_1s=0;
    flag_overload_out=0;
    flag_overload_in=0;
    flag_overload_in_ES=0;
    flag_overload_out_ES=0;
    overload_time_out=0;
    overload_time_in=0;
    overload_time_out_ES=0;
    overload_time_in_ES=0;
    FLAG_RESET_ALARM=0;
    RELAY_ALARM_LAT=1; //常闭报警继电器断开
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    time_2ms_12=0; 
    time_2ms_13=0; 
    while (1)
    {
        clrwdt;
        // ADCC_DischargeSampleCapacitor();
        //delay(1);
/**************************短路保护************************************/       

        if((5==ES_in_order))
        {  
            ad_value_I_TEST = ADCC_GetSingleConversion(I_TEST_AD_IN);
            if(ad_value_I_TEST>I_MAX_AD_CONST)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ
            {
                MOS_STORED_LAT=0;
                flag_overload_in_ES=1;
                overload_time_in_ES=0;
            }
        }         
        delay(1);  //106.625us的AD采样间隔   
///******************************************************************************/        
        if(PIR0bits.TMR0IF) //2ms心跳基准
        {
            TMR0_Initialize();
            INPUT_COLLECT();  
            if((5==ES_in_order)||(5==in_order)||(5==out_order))
            {
                test_time++;               
                if(test_time>=100)
                {
                    test_time=0;
                    if((5==ES_in_order))
                    {
                        motor_run_1s++;
                        if(motor_run_1s>=75)    //超时保护时间：15秒
                        {
                            motor_run_1s=0;
                            FLAG_OVER_TIME_30S=1;                        
                        }
                    }
                    else
                    {
                        FLAG_OVER_TIME_30S=1; 
                        test_time=0;
                    }
                }   
//                ADCC_DischargeSampleCapacitor();
//                delay(1);
                ad_value[i_avg] = ADCC_GetSingleConversion(I_TEST_AD_IN);
                sum_value=sum_value+ad_value[i_avg]; 
                i_avg++;
                if(i_avg>=10)       //取10次平均值，计算有效值
                {
                    i_avg=0;
                    ad_value_I_TEST_avg=sum_value/10;
                    sum_value=0;
                    if(ad_value_I_TEST_avg>I_AD_CONST)  //62=1.5A@200mΩ,155=1.5A@500mΩ,计算公式：（0.1*I）/5*1024
                    {
                        //FLAG_OVER_TIME_30S=1;
                        FLAG_OVER_CURRENT=1;
                    }    
                }
/**************************短路保护************************************/ 
                if(ad_value[i_avg]>I_MAX_AD_CONST)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ，311/42=7.4A，ad_74=151
                {
                    if((5==ES_in_order))
                    {  
                        MOS_STORED_LAT=0;
                        flag_overload_in_ES=1;
                        overload_time_in_ES=0;                       
                    }                      
                }
/*****************************************************************************/                
            }
            else
            {
                test_time=0;
                motor_run_1s=0;
            }             

/**************************短路保护恢复机制，200ms恢复运行************************************/              
            if(flag_overload_in_ES)
            {
                overload_time_in_ES++;
                if(overload_time_in_ES>=100)
                {
                    if((5==ES_in_order))
                    {
                        MOS_STORED_LAT=1;
                        flag_overload_in_ES=0;
                        overload_time_in_ES=0;
                    }
                }                
            }
/**************************************************************/              
            motor_do_time++;
            if(motor_do_time>=20)   //40ms采集一次
            {
                motor_do_time=0;              
                MOTOR_CTRL();
                LED_CTRL(); 
                ALARM_CTRL();
                                
            }        
        }
    }
}

void  delayus(uchar x)
{
	uchar a;
	for(a=x;a>0;a--)
	{
		clrwdt;
	}
}
void  delay(uint x)
{
	uint a,b;
	for(a=x;a>0;a--)
	{
		for(b=83;b>0;b--)
		{
			clrwdt;
		}
	}
}
/**
 End of File
*/