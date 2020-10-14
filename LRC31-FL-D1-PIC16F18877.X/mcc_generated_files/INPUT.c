#include"mcc.h"
bit FLAG_RESET_ALARM=0,FLAG_QS_MOTOR_IN=0,FLAG_QS_MOTOR_OUT=0,FLAG_ES_MOTOR_IN=0;
bit FLAG_ES_MOTOR_OUT=0,FLAG_ALARM_CMD=0,FLAG_ALARM_RUN=0,FLAG_STORED_IN=0,FLAG_PROTECT_OFF=0,FLAG_QS_MOTOR_OUT_enable=0,FLAG_QS_MOTOR_IN_enable=0,FLAG_ES_MOTOR_IN_enable=0,FLAG_ES_MOTOR_OUT_enable=0;
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
#define S14  PROTECT_CMD_OFF_IN_PORT
#define S13  CMD_RESET_IN_PORT
#define S10  (!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_STORED_IN)
#define S11  (!FLAG_ALARM)
uchar time_2ms_1=0,time_2ms_2=0,time_2ms_3=0,time_2ms_4=0,time_2ms_5=0,time_2ms_6=0,time_2ms_7=0,time_2ms_8=0,time_2ms_9=0,time_2ms_10=0,time_2ms_11=0,time_2ms_STORED=0,time_2ms_21=0,time_2ms_22=0;
uchar CMD_ERR=0X00;

void INPUT_COLLECT(void)
{

    if((!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_STORED_IN))
    {
        CMD_ERR=0X00;
        CMD_ERR = (S1|(S2<<1)|(S3<<2)|(S4<<3));
        if((((CMD_ERR!=0X0F)&&(CMD_ERR!=0X0E)&&(CMD_ERR!=0X0D)&&(CMD_ERR!=0X0B)&&(CMD_ERR!=0X07)))||((!S5)&&(!S6)))
        {
            time_2ms_5++;
            if(time_2ms_5>5)
            {
                time_2ms_5=0;
                FLAG_ALARM_CMD=1;
                RELAY_ALARM_LAT=0;
            }
        }
        else
        {
            time_2ms_5=0;
            FLAG_ALARM_CMD=0;
        }
    }
    if(!CMD_RESET_IN_PORT)
    {
        time_2ms_6++;
        if(time_2ms_6>10)
        {
            time_2ms_6=0;
            FLAG_RESET_ALARM=1;
        }        
    }
    else
    {
        time_2ms_6=0;
        FLAG_RESET_ALARM=0;
    }
    
    //if((!S1)&&(S2)&&(S3)&&(S4)&&(S7)&&(S10)&&(!S13)&&(S15)&&(S16)&&(!S17)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_ALARM))    //负荷开关合闸
    if((!S1)&&(S2)&&(S3)&&(S4)&&(S5)&&(!S6)&&(S7)&&(!S9)&&(S10)&&(S11)&&(!S12)&&(S13)&&(!FLAG_ALARM_CMD))    //负荷开关合闸
    {
        if(FLAG_QS_MOTOR_IN_enable)
        {
            time_2ms_1++;
            if(time_2ms_1>10)
            {
                time_2ms_1=0;           
                FLAG_QS_MOTOR_IN=1; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
                FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                FLAG_ES_MOTOR_OUT=0; //接地开关分闸标志位
                FLAG_STORED_IN=0;
                FLAG_QS_MOTOR_IN_enable=0;
            }
        }
        
    }
    else
    {
        time_2ms_1=0;
        if(S1)
        FLAG_QS_MOTOR_IN_enable=1;
    }
    if((!S1)&&(S2)&&(S3)&&(S4)&&(S5)&&(!S6)&&(S7)&&(!S9)&&(S10)&&(S11)&&(S12)&&(S13)&&(!FLAG_ALARM_CMD))    //负荷开关储能
    {
        time_2ms_STORED++;
        if(time_2ms_STORED>10)
        {
            time_2ms_STORED=0;           
            FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
            FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
            FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
            FLAG_ES_MOTOR_OUT=0; //接地开关分闸标志位
            FLAG_STORED_IN=1;
        }
    }
    else
    {
        time_2ms_STORED=0;
    }    
    //if((!S2)&&(S1)&&(S3)&&(S4)&&(!S7)&&(S10)&&(!S13)&&(S15)&&(S16)&&(!S17)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_ALARM))    //负荷开关分闸    
    if(((!S2)&&(S1)&&(S3)&&(S4)&&(S6)&&(S7)&&(!S9)&&(S10)&&(S11)&&(S13)&&(!FLAG_ALARM_CMD)))                                                               //负荷开关分闸
    {
        if(FLAG_QS_MOTOR_OUT_enable)
        {
            time_2ms_2++;
            if(time_2ms_2>10)
            {
                time_2ms_2=0;           
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=1; //负荷开关分闸标志位
                FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                FLAG_ES_MOTOR_OUT=0; //接地开关分闸标志位
                FLAG_STORED_IN=0;
                FLAG_QS_MOTOR_OUT_enable=0;
//                if(!S14)
//                {
//                    FLAG_PROTECT_OFF=1;
//                }
//                else
//                {
//                   FLAG_PROTECT_OFF=0; 
//                }                
            }
        }
    }
    else
    {
        time_2ms_2=0;
        if(S2)
        {
            FLAG_QS_MOTOR_OUT_enable=1;
        }
    }      
    if((!S3)&&(S1)&&(S2)&&(S4)&&(S5)&&(S7)&&(!S8)&&(!S9)&&(S10)&&(S11)&&(S13)&&(!FLAG_ALARM_CMD))    //接地开关合闸
//    if(!S3)
    {
        if(FLAG_ES_MOTOR_IN_enable)
        {
            time_2ms_3++;
            if(time_2ms_3>10)
            {
                time_2ms_3=0;           
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
                FLAG_ES_MOTOR_IN=1; //接地开关合闸标志位
                FLAG_ES_MOTOR_OUT=0; //接地开关分闸标志位
                FLAG_STORED_IN=0;
                FLAG_ES_MOTOR_IN_enable=0;
            }
        }
    }
    else
    {
        time_2ms_3=0;
        if(S3)
        FLAG_ES_MOTOR_IN_enable=1;
    } 
    if((!S4)&&(S1)&&(S2)&&(S3)&&(S5)&&(S8)&&(!S9)&&(S10)&&(S11)&&(S13)&&(!FLAG_ALARM_CMD)) 
    //        ||((S7)&&(S10)&&(S17))||((!S7)&&(S10)&&(S17))||((!S7)&&(S10)&&(!S17)))    //接地开关分闸
    {
        if(FLAG_ES_MOTOR_OUT_enable)
        {
            time_2ms_4++;
            if(time_2ms_4>10)
            {
                time_2ms_4=0;           
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
                FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                FLAG_ES_MOTOR_OUT=1; //接地开关分闸标志位
                FLAG_STORED_IN=0;
                FLAG_ES_MOTOR_OUT_enable=0;
            }
        }
    }
    else
    {
        time_2ms_4=0;
        if(S4)
        FLAG_ES_MOTOR_OUT_enable=1;
    }   
    if((FLAG_QS_MOTOR_IN)||(FLAG_QS_MOTOR_OUT)||(FLAG_ES_MOTOR_IN)||(FLAG_ES_MOTOR_OUT)||(FLAG_STORED_IN))    //电机运行过程中联锁信号断开
    {
        RELAY_LOCK_LAT=0;
        {
            if((S9)||((!S5)&&(!S6)))
            {
                time_2ms_7++;
                if(time_2ms_7>5)
                {
                    time_2ms_7=0;
                    FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                    FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志位
                    FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                    FLAG_ES_MOTOR_OUT=0; //接地开关分闸标志位   
                    FLAG_STORED_IN=0;
                    FLAG_ALARM_RUN=1;
                    out_order=1;
                    out_stop_order=1;
                    in_order=1;
                    in_stop_order=1;
                    ES_in_stop_order=1;
                    ES_in_order=1;
                    ES_out_stop_order=1;
                    ES_out_order=1;      
                    STORED_in_stop_order=1;
                    STORED_in_order=1;
                }
            }
            else
            {
                time_2ms_7=0;
            }
        }
        if((!S5)&&(FLAG_QS_MOTOR_IN))  //负荷开关到达合闸位
        {
            time_2ms_8++;
            if(time_2ms_8>5)
            {
                time_2ms_8=0;
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                MOS_Y2_LAT=0; 
                if(FLAG_ALARM_OVER1)
                {
                    FLAG_ALARM_OVER1=0;
                }                
            }
        } 
        else
        {
            time_2ms_8=0;
        }
        if((!S6)&&(FLAG_QS_MOTOR_OUT))   //负荷开关到达分闸位
        {
            time_2ms_9++;
            if(time_2ms_9>5)
            {
                time_2ms_9=0;
                FLAG_QS_MOTOR_OUT=0; //负荷开关合闸标志位
                FLAG_PROTECT_OFF=0;
                MOS_Y1_LAT=0;
                if(FLAG_ALARM_OVER1)
                {
                    FLAG_ALARM_OVER1=0;
                }             
            }
        }  
        else
        {
            time_2ms_9=0;
        }
        if((!S7)&&(FLAG_ES_MOTOR_IN))   //接地开关到达合闸位
        {
            time_2ms_10++;
            if(time_2ms_10>5)
            {
                time_2ms_10=0;
                FLAG_ES_MOTOR_IN=0; //接地开关合闸标志位
                MOS_ES_P_LAT=0;
                if(FLAG_ALARM_OVER1)
                {
                    FLAG_ALARM_OVER1=0;
                }
                if(FLAG_ALARM_OVER2)
                {
                    FLAG_ALARM_OVER2=0;
                }                 
            }
        }  
        else
        {
            time_2ms_10=0;
        }
        if((S7)&&(!S8)&&(FLAG_ES_MOTOR_OUT))   //接地开关到达分闸位
        {
            time_2ms_11++;
            if(time_2ms_11>5)
            {
                time_2ms_11=0;
                FLAG_ES_MOTOR_OUT=0; //负荷开关合闸标志位
                MOS_ES_N_LAT=0;
                if(FLAG_ALARM_OVER1)
                {
                    FLAG_ALARM_OVER1=0;
                }
                if(FLAG_ALARM_OVER2)
                {
                    FLAG_ALARM_OVER2=0;
                }                   
            }
        }
        else
        {
            time_2ms_11=0;
        }
        if((!S12)&&(FLAG_STORED_IN))   //到达储能位
        {
            time_2ms_21++;
            if(time_2ms_21>10)
            {
                time_2ms_21=0;
                FLAG_STORED_IN=0; //储能标志
                FLAG_QS_MOTOR_IN=1; 
                MOS_STORED_LAT=0;                
            }
        }  
        else
        {
            time_2ms_21=0;
        }          
    }
    else
    {
       // RELAY_LOCK_LAT=1;
    }
}

