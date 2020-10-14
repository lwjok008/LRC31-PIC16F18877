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

#define S1  CMD_QS_CLOSE_IN_PORT
#define S2  CMD_QS_OPEN_IN_PORT
#define S3  CMD_ES_CLOSE_IN_PORT
#define S4  CMD_ES_OPEN_IN_PORT
#define S5  P_QS_CLOSE_IN_PORT
#define S6  P_QS_OPEN_IN_PORT
#define S7  P_ES_CLOSE_IN_PORT
#define S8  P_ES_OPEN_IN_PORT
#define S9  LOCK_CLOSE_IN_PORT
#define S12  P_STORED_IN_PORT
//#define S14  PROTECT_CMD_OFF_IN_PORT
#define S13  CMD_RESET_IN_PORT

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
uint led_time_40ms_Test;
void main(void)
{

    // initialize the device
    SYSTEM_Initialize();
    sum_value=0;
    i_avg=0;    
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
    while (1)
    {
        if(PIR0bits.TMR0IF) //2ms心跳基准
        {    
            
            if((S7)&&(S8)&&(!S5))    //上电时，在中间位，接地开关分闸
            {
                time_2ms_12++;
                if(time_2ms_12>10)
                {
                    time_2ms_12=15;           
                    FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                    FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
                    FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                    FLAG_ES_MOTOR_OUT=1; //接地开关分闸标志位
                    FLAG_STORED_IN=0;
                    break;
                }
            }
            else
            {
                time_2ms_13++;
                if(time_2ms_13>10)
                {
                    time_2ms_13=15; 
                    break;
                }
            }
            
        }
    }
    time_2ms_12=0; 
    time_2ms_13=0; 
    while (1)
    {
        clrwdt;
        // ADCC_DischargeSampleCapacitor();
        //delay(1);
        
/**************************短路保护************************************/     
        if((5==STORED_in_order))
        {
            ad_value_I_TEST = ADCC_GetSingleConversion(I_TEST_AD_IN);
            if(ad_value_I_TEST>182)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ
            {            
                MOS_STORED_LAT=0;
                flag_overload_out=1;
                overload_time_out=0; 
            }
        }        
        if((5==ES_in_order))
        {  
            ad_value_I_TEST = ADCC_GetSingleConversion(I_TEST_AD_IN);
            if(ad_value_I_TEST>182)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ
            {
                MOS_ES_P_LAT=0;
                flag_overload_in_ES=1;
                overload_time_in_ES=0;
            }
        }  
        else if((5==ES_out_order))
        {  
            ad_value_I_TEST = ADCC_GetSingleConversion(I_TEST_AD_IN);
            if(ad_value_I_TEST>182)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ
            {
                MOS_ES_N_LAT=0;
                flag_overload_out_ES=1;
                overload_time_out_ES=0;
            }
        }          
        delay(1);  //106.625us的AD采样间隔   
/******************************************************************************/        
        if(PIR0bits.TMR0IF) //2ms心跳基准
        {
            
            TMR0_Initialize();
            INPUT_COLLECT();  
            if((5==out_order)||(5==in_order)||(5==ES_in_order)||(5==ES_out_order)||(5==STORED_in_order))
            {
                test_time++;               
                if(test_time>=100)
                {
                    test_time=0;
                    if((5==ES_in_order)||(5==ES_out_order)||(5==STORED_in_order))
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
                    if(ad_value_I_TEST_avg>58)  //27=1.3A,62=1.5A,41=2A,计算公式：（0.1*I）/5*1024，采样电阻200mΩ
                    {
                        //FLAG_OVER_TIME_30S=1;
                        FLAG_OVER_CURRENT=1;
                    }    
                }
/**************************短路保护************************************/ 
                if(ad_value[i_avg]>182)  //OVERLOAD=3A*1.414，计算公式：（0.1*I）/5*1024，采样电阻100mΩ，311/42=7.4A，ad_74=151
                {
                    if((5==STORED_in_order))
                    {
                        MOS_STORED_LAT=0;
                        flag_overload_out=1;
                        overload_time_out=0;                        
                    }
                    else if((5==ES_in_order))
                    {  
                        MOS_ES_P_LAT=0;
                        flag_overload_in_ES=1;
                        overload_time_in_ES=0;                       
                    }  
                    else if((5==ES_out_order))
                    {  
                        MOS_ES_N_LAT=0;
                        flag_overload_out_ES=1;
                        overload_time_out_ES=0;                      
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
            if(flag_overload_out)
            {
                overload_time_out++;
                if(overload_time_out>=100)
                {
                    if((5==STORED_in_order)&&(FLAG_STORED_IN))
                    {
                        MOS_STORED_LAT=1;
                        flag_overload_out=0;
                        overload_time_out=0;
                    }
                }
            }
            else if(flag_overload_out_ES)
            {
                overload_time_out_ES++;
                if(overload_time_out_ES>=100)
                {
                    if((5==ES_out_order)&&(FLAG_ES_MOTOR_OUT))
                    {
                        MOS_ES_N_LAT=1;
                        flag_overload_out_ES=0;
                        overload_time_out_ES=0;
                    }
                }                
            }
            else if(flag_overload_in_ES)
            {
                overload_time_in_ES++;
                if(overload_time_in_ES>=100)
                {
                    if((5==ES_in_order)&&(FLAG_ES_MOTOR_IN))
                    {
                        MOS_ES_P_LAT=1;
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