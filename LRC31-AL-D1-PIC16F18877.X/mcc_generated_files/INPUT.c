#include"mcc.h"
#define S1  LOCK_CLOSE_IN_PORT  //合闸联锁信号
#define S2  CMD_CLOSE_IN_PORT   //合闸信号
#define S3  CMD_OPEN_IN_PORT    //分闸信号
#define S4  P_STORED_IN_PORT    //储能到位信号
#define S5  P_CLOSE_IN_PORT     //合闸位信号
#define S6  P_OPEN_IN_PORT      //分闸位信号
#define S7  CMD_RESET_IN_PORT   //复位信号
#define S8  PROTECT_CMD_OFF_IN_PORT     //有辅助电源时候也能保护分闸
uchar time_2ms_1=0,time_2ms_2=0,time_2ms_3=0,time_2ms_4=0,time_2ms_5=0,time_2ms_6=0,time_2ms_7=0,time_2ms_8=0,time_2ms_9=0,time_2ms_10=0,time_2ms_11=0,time_2ms_12=0,time_2ms_13=0,time_2ms_14=0;
uint  time_2ms_S7=0;
uchar CMD_ERR=0X00,CMD_ERR1=0X00;
bit FLAG_RESET_ALARM=0,FLAG_RESET_ALARM_enable=0,FLAG_QS_MOTOR_IN=0,FLAG_QS_MOTOR_OUT=0,FLAG_ES_MOTOR_IN=0,FLAG_ES_MOTOR_OUT=0,FLAG_ALARM_CMD=0,FLAG_ALARM_RUN=0;
bit FLAG_ALARM_CMD1=0,FLAG_ALARM_CMD2=0,FLAG_STORED_IN=0,FLAG_QS_MOTOR_OUT_enable=0,FLAG_PROTECT_OK=0;
void INPUT_COLLECT(void)
{
    //if((!S1)&&(S2)&&(S3)&&(S4)&&(S7)&&(S10)&&(!S13)&&(S15)&&(S16)&&(!S17)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_ALARM))    //负荷开关合闸
    if((!S1)&&(!S2)&&(S3)&&(!S4)&&(S5)&&(!S6)&&(S7)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ALARM)&&(!FLAG_ALARM_CMD)&&(!FLAG_ALARM_CMD1))
    {
        time_2ms_1++;
        if(time_2ms_1>10)
        {
            time_2ms_1=0;           
            FLAG_QS_MOTOR_IN=1; //负荷开关合闸标志位
        }
    }
    else
    {
        time_2ms_1=0;
    }
    if((!S1)&&(!S2)&&(S3)&&(S4)&&(S5)&&(!S6)&&(S7)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ALARM)&&(!FLAG_ALARM_CMD)&&(!FLAG_ALARM_CMD1))
      //储能电机运行指令
    {
        time_2ms_5++;
        if(time_2ms_5>10)
        {
            time_2ms_5=0;           
            FLAG_STORED_IN=1; //储能运行标志位置位
        }
    }
    else
    {
        time_2ms_5=0;
    }
    //if((!S2)&&(S1)&&(S3)&&(S4)&&(!S7)&&(S10)&&(!S13)&&(S15)&&(S16)&&(!S17)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ES_MOTOR_IN)&&(!FLAG_ES_MOTOR_OUT)&&(!FLAG_ALARM))    //负荷开关分闸    
    if(((S2)&&(!S3)&&(S6)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ALARM)&&(!FLAG_ALARM_CMD)&&(!FLAG_ALARM_CMD1)))    //在中间位可分闸，保护分闸指令也可分闸，故不判断合闸位信号，保护分闸不判断复位信号
    {
       // if(FLAG_QS_MOTOR_OUT_enable)
        {
            time_2ms_2++;
            if(time_2ms_2>10)
            {
                time_2ms_2=0;           
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=1; //负荷开关分闸标志位
                FLAG_QS_MOTOR_OUT_enable=0;
            }
        }
    }
    else
    {
        time_2ms_2=0;
//        if(S8)
//        {
//            FLAG_QS_MOTOR_OUT_enable=1;
//        }
    }
    if(((!S8)&&(S6)&&(!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT)&&(!FLAG_ALARM_CMD1)))    //在中间位可分闸，保护分闸指令也可分闸，故不判断合闸位信号，保护分闸不判断复位信号
    {
        if(FLAG_QS_MOTOR_OUT_enable)
        {
            time_2ms_12++;
            if(time_2ms_12>10)
            {
                time_2ms_12=0;           
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_QS_MOTOR_OUT=1; //负荷开关分闸标志位
                FLAG_QS_MOTOR_OUT_enable=0;
                FLAG_PROTECT_OK=1;
            }
        }
    }
    else
    {
        time_2ms_12=0;
        if(S8)
        {
            FLAG_QS_MOTOR_OUT_enable=1;
        }
    }      
    if((!FLAG_QS_MOTOR_IN)&&(!FLAG_QS_MOTOR_OUT))//待机状态,分合闸指令或分合闸位信号同时存在，报警
    {
        CMD_ERR=0X00;   //分合闸指令同时存在判断  
        CMD_ERR = (S2|(S3<<1));
        if(((CMD_ERR&0x03)==0X00))
        {
            time_2ms_3++;
            if(time_2ms_3>5)
            {
                time_2ms_3=0;
                FLAG_ALARM_CMD=1;
                RELAY_ALARM_LAT=0;
            }
        }
        else
        {
            time_2ms_3=0;
            FLAG_ALARM_CMD=0;
        }
        
        CMD_ERR1=0X00;       //分合闸位同时存在判断   
        CMD_ERR1 = ((S5<<2)|(S6<<3));
        if(((CMD_ERR1&0x0c)==0X00))
        {
            time_2ms_4++;
            if(time_2ms_4>5)
            {
                time_2ms_4=0;
                FLAG_ALARM_CMD1=1;
                RELAY_ALARM_LAT=0;
            }
        }
        else
        {
            time_2ms_4=0;
            FLAG_ALARM_CMD1=0;
        }     
//        if(!S7)
//        {
//            time_2ms_S7++;
//            if(time_2ms_S7>1000)
//            {
//                time_2ms_S7=1001;
//                FLAG_ALARM_CMD2=1;
//            }
//        }
//        else
//        {
//            time_2ms_S7=0;
//            FLAG_ALARM_CMD2=0;
//        }
    }
    if(!S7) //复位输入
    {
        time_2ms_S7++;
        if((time_2ms_S7>10)&&(time_2ms_S7<=1000))
        {
            //time_2ms_6=0;
            FLAG_RESET_ALARM_enable=1;
        }   
        else if(time_2ms_S7>1000)
        {
            time_2ms_S7=1001;
            FLAG_ALARM_CMD2=1;
            RELAY_ALARM_LAT=0;
        }
    }
    else
    {
        time_2ms_S7=0;
        FLAG_ALARM_CMD2=0;
        if(FLAG_RESET_ALARM_enable)
        {
            FLAG_RESET_ALARM=1;
            FLAG_RESET_ALARM_enable=0;
        }
        else
        {
//            
//           FLAG_RESET_ALARM=0;           
        }

    }
    if((FLAG_QS_MOTOR_IN)||(FLAG_QS_MOTOR_OUT)||(FLAG_STORED_IN))   //电机运行过程中 
    {
        RELAY_LOCK_LAT=0;
        if(S1&&(FLAG_QS_MOTOR_IN))      //电机运行过程中联锁信号断开
        {
            time_2ms_7++;
            if(time_2ms_7>10)
            {
                time_2ms_7=0;
                FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                FLAG_ALARM_RUN=1;
                MOS_Y2_LAT=0;
                in_order=1;
                in_stop_order=1;             
            }
        }
        else
        {
            time_2ms_7=0;
        }
        if(S6)  //分闸位断开
        {
            if((!S5)&&(FLAG_QS_MOTOR_IN))  //负荷开关到达合闸位
            {
                time_2ms_8++;
                if(time_2ms_8>10)
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
        }
        else    //分合闸位同时存在
        {
            if((!S5)&&(FLAG_QS_MOTOR_IN))  //负荷开关到达合闸位
            {
                time_2ms_8++;
                if(time_2ms_8>10)
                {
                    time_2ms_8=0;
                    FLAG_QS_MOTOR_IN=0; //负荷开关合闸标志位
                    MOS_Y2_LAT=0;  
                    FLAG_ALARM_RUN=1;
                    //out_order=1;
                    //out_stop_order=1;  
                }
            } 
            else
            {
                time_2ms_8=0;
            }            
        }
        if(S5)  //合闸位断开
        {
            if((!S6)&&(FLAG_QS_MOTOR_OUT))   //负荷开关到达分闸位
            {
                time_2ms_9++;
                if(time_2ms_9>10)
                {
                    time_2ms_9=0;
                    FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志
                    MOS_Y1_LAT=0;   
                    if(FLAG_ALARM_OVER1)
                    {
                        FLAG_ALARM_OVER1=0;
                    }
                   if(FLAG_PROTECT_OK)
                   {
                       FLAG_PROTECT_OK=0;
                       FLAG_RESET_ALARM=1;
                   }
                }
            }  
            else
            {
                time_2ms_9=0;
            }
        }
        else    //分合闸位同时存在
        {
            if((!S6)&&(FLAG_QS_MOTOR_OUT))   //负荷开关到达分闸位
            {
                time_2ms_9++;
                if(time_2ms_9>10)
                {
                    time_2ms_9=0;
                    FLAG_QS_MOTOR_OUT=0; //负荷开关分闸标志
                    FLAG_ALARM_RUN=1;
                    MOS_Y1_LAT=0;              
                }
            }  
            else
            {
                time_2ms_9=0;
            }            
        }
        if((!S4)&&(FLAG_STORED_IN))   //到达储能位
        {
            time_2ms_10++;
            if(time_2ms_10>10)
            {
                time_2ms_10=0;
                FLAG_STORED_IN=0; //储能标志
                FLAG_QS_MOTOR_IN=1; 
                MOS_STORED_LAT=0;                
            }
        }  
        else
        {
            time_2ms_10=0;
        }  
        if(FLAG_STORED_IN)
        {
            if(((!S5)&&(!S6))||(S1))    //分合闸位信号同时存在，停止储能电机运行
            {
                time_2ms_11++;
                if(time_2ms_11>10)
                {
                    time_2ms_11=0;
                    FLAG_STORED_IN=0; //负荷开关分闸标志
                    MOS_STORED_LAT=0;       
                    FLAG_ALARM_RUN=1;
                }            
            }
            else
            {
                time_2ms_11=0;
            }
        }
    }     
    else    //待机过程中，联锁输出闭合
    {       
        if(!S5)
        {
            time_2ms_14=0;
            time_2ms_13++;
            if(time_2ms_13>10)
            {
                time_2ms_13=11;
                RELAY_LOCK_LAT=0; 
            }                       
        }
        else
        {
            time_2ms_13=0;
            time_2ms_14++;
            if(time_2ms_14>10)
            {
                time_2ms_14=11;
                RELAY_LOCK_LAT=1; 
            }              
            //RELAY_LOCK_LAT=1;
        }
    }
           
}


