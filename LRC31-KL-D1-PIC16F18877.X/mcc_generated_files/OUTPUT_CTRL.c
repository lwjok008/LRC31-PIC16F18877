#include "mcc.h"
#include"head.h"
#define BREAK_WIRE_VALUE 10
BYTE_BITS SYSTEM_FLAG;
uchar run_orderA=1,stop_orderA,down_counterA,up_counterA;
uchar run_orderB=1,stop_orderB,down_counterB,up_counterB;
uchar run_orderC=1,stop_orderC,down_counterC,up_counterC;
uchar up_counterAA,up_counterBB,up_counterCC,down_counterAA,down_counterBB,down_counterCC;
bit flag_runA,flag_motorB_RUN,flag_motorC_RUN;
void INPUT_COLLECT(void);
void MOTOR_CTRL(void);  
void ALARM_OUT(void);
void LED_CTRL(void);
void MOTOR_CURRENT_COLLECT(void);
uint break_heater_current=10,break_blower_current=10;
bit HEATER_WIRE_OK=0,BLOWER_WIRE_OK=0;
bit FLAG_HEAT1_LAT=0,FLAG_HEAT2_LAT=0,FLAG_HEAT3_LAT=0;
uint AD_HEAT1_value,AD_HEAT2_value,AD_HEAT3_value;
bit flag_err_led,flag_err1_led;
uchar FLAG_BYTE,FLAG_BYTE_BKP;
uint32_t ad_value_A,ad_value_B,ad_value_C;
void OUTPUT_CTRL(void)
{
    INPUT_COLLECT();
    MOTOR_CTRL(); 
    ALARM_OUT();

    //LED_CTRL();
}
void ALARM_OUT(void)
{
//    flag_COUNTA_NG=1;
//    flag_COUNTB_NG=1;
//    flag_COUNTC_NG=1;
    FLAG_BYTE = (flag_COUNTA_NG)+(flag_COUNTB_NG<<1)+(flag_COUNTC_NG<<2)+(flag_A_RUN_120S<<3)+(flag_B_RUN_120S<<4)+(flag_C_RUN_120S<<5);
    if(FLAG_BYTE>FLAG_BYTE_BKP)
    {
        FLAG_ALARM_RESET=0;
        FLAG_ALL_RESET = 0;
    }
    else
    {
        if(FLAG_ALARM_RESET)
        {
            FLAG_ALARM_RESET=1;
        }  
        if(FLAG_ALL_RESET)
        {
            FLAG_ALL_RESET=1;
        }          
    }
    FLAG_BYTE_BKP = FLAG_BYTE;
//    if(FLAG_BYTE==7)
//    {
//        LED_ALARM_LAT =1;
//    }
    if((!(FLAG_ALARM_RESET))&&((!(FLAG_ALL_RESET))))
    {
        if((flag_COUNTA_NG||flag_COUNTB_NG||flag_COUNTC_NG)||(flag_A_RUN_120S||flag_B_RUN_120S||flag_C_RUN_120S))
        {
            LED_ALARM_LAT = 1;
        }
        else
        {
//            LED_ALARM_LAT = 0;;
        }
        if(flag_A_RUN_120S||flag_B_RUN_120S||flag_C_RUN_120S)
        {
            ALARM_OVERTIME_LAT = 1;
        }
        else
        {
//            ALARM_OVERTIME_LAT = 0;
        }
        if((flag_COUNTA_NG||flag_COUNTB_NG||flag_COUNTC_NG))
        {
            ALARM_OVERCOUT_LAT = 1;
        }
        else
        {
//            ALARM_OVERCOUT_LAT = 0;
        }
    }
    else
    {
        LED_ALARM_LAT = 0;
        ALARM_OVERCOUT_LAT = 0;
        ALARM_OVERTIME_LAT = 0;
        LED_ALARM_LAT = 0;;
        ALARM_OVERTIME_LAT = 0;
        ALARM_OVERCOUT_LAT = 0;
        flag_A_RUN_120S_disp=0;
        flag_B_RUN_120S_disp=0;
        flag_C_RUN_120S_disp=0;
//        flag_COUNTA_NG_disp=0;
//        flag_COUNTB_NG_disp=0;
//        flag_COUNTC_NG_disp=0;
        flag_COUNTA_NG=0;
        flag_COUNTB_NG=0;
        flag_COUNTC_NG=0;       
    }
}
void LED_CTRL(void)
{
//    RLYC_LAT = 1;
//    RLYB_LAT = 1;
//    RLYA_LAT = 1;
    //LED_ALARM_LAT = ~LED_ALARM_LAT;
}
uint A_RUN_counter_24H=0;
void MOTOR_CTRL(void)
{
    uchar i;
    if(!flag_A_RUN_120S) 
    {
        if(flag_pressA_NG)
        {
            switch(run_orderA)
            {
                case 1:	
                {
                    RLYA_LAT=1;
                    run_orderA=2;
                }break;
                case 2:	
                {  
                    MOSA_LAT=1;
                    run_orderA=3;
                    flag_runA=1;
                    A_RUN_counter++;
                    A_RUN_counter_24H++;
                    if(A_RUN_counter_24H>10)
                    {
                        A_RUN_counter_24H=11;
                    }                   
                    if(A_RUN_counter>9999)
                    {
                        A_RUN_counter=9999;
                    }
                }break;
            }
        }
        else
        {
            switch(stop_orderA)
            {
                case 1:	
                {
                    MOSA_LAT=0;
                    stop_orderA=2;
                }break;
                case 2:	
                {  
                    RLYA_LAT=0;
                    flag_runA=0;
                    stop_orderA=3;
                }break;
            } 
        }
    }
    else
    {
        switch(stop_orderA)
        {
            case 1:	
            {
                MOSA_LAT=0;
                stop_orderA=2;
            }break;
            case 2:	
            {  
                RLYA_LAT=0;
                flag_runA=0;
                stop_orderA=3;
            }break;
        }         
    }

/*********************************************************/  
    if(!flag_B_RUN_120S)
    {
        if(flag_pressB_NG)
        {
            switch(run_orderB)
            {
                case 1:	
                {
                    RLYB_LAT=1;
                    run_orderB=2;
                }break;
                case 2:	
                {  
                    MOSB_LAT=1;
                    flag_runB=1;
                    run_orderB=3;
                    B_RUN_counter++;
                    B_RUN_counter_24H++;
                    if(B_RUN_counter_24H>99)
                    {
                        B_RUN_counter_24H=99;
                    }                    
                    if(B_RUN_counter>9999)
                    {
                        B_RUN_counter=9999;
                    }                
                }break;
            }
        }
        else
        {
            switch(stop_orderB)
            {
                case 1:	
                {
                    MOSB_LAT=0;
                    stop_orderB=2;
                }break;
                case 2:	
                {  
                    RLYB_LAT=0;
                    flag_runB=0;
                    stop_orderB=3;
                }break;
            } 
        } 
    }
    else
    {
        switch(stop_orderB)
        {
            case 1:	
            {
                MOSB_LAT=0;
                stop_orderB=2;
            }break;
            case 2:	
            {  
                RLYB_LAT=0;
                flag_runB=0;
                stop_orderB=3;
            }break;
        }         
    }
/***************************************************/   
    if(!flag_C_RUN_120S)
    {    
        if(flag_pressC_NG)
        {
            switch(run_orderC)
            {
                case 1:	
                {
                    RLYC_LAT=1;
                    run_orderC=2;
                }break;
                case 2:	
                {  
                    MOSC_LAT=1;
                    flag_runC=1;
                    run_orderC=3;
                    C_RUN_counter++;
                    C_RUN_counter_24H++;
                    if(C_RUN_counter_24H>99)
                    {
                        C_RUN_counter_24H=99;
                    }                       
                    if(C_RUN_counter>9999)
                    {
                        C_RUN_counter=9999;
                    }                 
                }break;
            }
        }
        else
        {
            switch(stop_orderC)
            {
                case 1:	
                {
                    MOSC_LAT=0;
                    stop_orderC=2;
                }break;
                case 2:	
                {  
                    RLYC_LAT=0;
                    flag_runC=0;
                    stop_orderC=3;
                }break;
            } 
        }     
    }
    else
    {
        switch(stop_orderC)
        {
            case 1:	
            {
                MOSC_LAT=0;
                stop_orderC=2;
            }break;
            case 2:	
            {  
                RLYC_LAT=0;
                flag_runC=0;
                stop_orderC=3;
            }break;
        }         
    }
}
void INPUT_COLLECT(void)
{
    if(!INA_PORT)
    {
        down_counterA++;
        if(down_counterA>1)
        {
            down_counterA = 0;
            flag_pressA_NG = 1;
            stop_orderA = 1;
        }
    }
    else
    {
        up_counterA++;
        if(up_counterA>1)
        {
            up_counterA = 0;
            flag_pressA_NG = 0;
            run_orderA = 1;
        }
    }
    if(!INB_PORT)
    {
        down_counterB++;
        if(down_counterB>1)
        {
            down_counterB = 0;
            flag_pressB_NG = 1;
            stop_orderB = 1;
        }
    }
    else
    {
        up_counterB++;
        if(up_counterB>1)
        {
            up_counterB = 0;
            flag_pressB_NG = 0;
            run_orderB = 1;
        }
    }
    if(!INC_PORT)
    {
        down_counterC++;
        if(down_counterC>1)
        {
            down_counterC = 0;
            flag_pressC_NG = 1;
            stop_orderC = 1;
        }
    }
    else
    {
        up_counterC++;
        if(up_counterC>1)
        {
            up_counterC = 0;
            flag_pressC_NG = 0;
            run_orderC = 1;
        }
    }    
    if(!INAA_PORT)
    {
        down_counterAA++;
        if(down_counterAA>1)
        {
            if(down_counterAA == 2)
            {
                A_CLOSE_counter++;
                if(A_CLOSE_counter>9999)
                {
                    A_CLOSE_counter=9999;
                }                
            }
            down_counterAA = 3;
            up_counterAA = 0;
        }
    }
    else
    {
        up_counterAA++;
        if(up_counterAA>1)
        {
            up_counterAA = 3;
            down_counterAA = 0;
        }        
    }
    if(!INBB_PORT)
    {
        down_counterBB++;
        if(down_counterBB>1)
        {
            if(down_counterBB == 2)
            {
                B_CLOSE_counter++;
                if(B_CLOSE_counter>9999)
                {
                    B_CLOSE_counter=9999;
                }                
            }
            down_counterBB = 3;
            up_counterBB = 0;
        }
    }
    else
    {
        up_counterBB++;
        if(up_counterBB>1)
        {
            up_counterBB = 3;
            down_counterBB = 0;
        }        
    }
    if(!INCC_PORT)
    {
        down_counterCC++;
        if(down_counterCC>1)
        {
            if(down_counterCC == 2)
            {
                C_CLOSE_counter++;
                if(C_CLOSE_counter>9999)
                {
                    C_CLOSE_counter=9999;
                }
            }
            down_counterCC = 3;
            up_counterCC = 0;
        }
    }
    else
    {
        up_counterCC++;
        if(up_counterCC>1)
        {
            up_counterCC = 3;
            down_counterCC = 0;
        }        
    }    
}

void MOTOR_CURRENT_COLLECT(void)
{
   // uint32_t ad_value_A=0,ad_value_B=0,ad_value_C=0;
/******************************************************/       
    if(flag_runA)
    {
        ADCC_DischargeSampleCapacitor();
        delay(1);
        ad_value_A = ADCC_GetSingleConversion(AD_MOTORA);
        A_current = ((165*ad_value_A)>>10)+0.5;
    }
    else
    {
        A_current = 0;
        ad_value_A = 0;
    }
/******************************************************/    
    if(flag_runB)
    {
        ADCC_DischargeSampleCapacitor();  
        delay(1);
        ad_value_B = ADCC_GetSingleConversion(AD_MOTORB);
        B_current = ((165*ad_value_B)>>10)+0.5;
    }
    else
    {
        B_current = 0;
        ad_value_B = 0;
    }    
/******************************************************/
    if(flag_runC)
    {
        ADCC_DischargeSampleCapacitor();  
        delay(1);
        ad_value_C = ADCC_GetSingleConversion(AD_MOTORC);
        C_current = ((165*ad_value_C)>>10)+0.5;
    }
    else
    {
        C_current = 0;
        ad_value_C = 0;
    }    
/******************************************************/    
}