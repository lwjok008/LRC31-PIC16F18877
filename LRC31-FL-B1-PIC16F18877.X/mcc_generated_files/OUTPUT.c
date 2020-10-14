#include"mcc.h"
bit FLAG_ALARM=0,FLAG_ALARM_OVER1=0,FLAG_ALARM_OVER2=0;
uchar out_order=1,out_stop_order=1,in_order=1,in_stop_order=1,ES_in_stop_order=1,ES_in_order=1,ES_out_stop_order=1,ES_out_order=1,STORED_in_order=1,STORED_in_stop_order=1;
uint I_current=0;
uint led_time_40ms;
void ALARM_CTRL(void)
{

    if(FLAG_RESET_ALARM)
    {
        FLAG_RESET_ALARM=0;                    
        RELAY_ALARM_LAT=1;
        FLAG_ALARM_CMD=0;
        FLAG_ALARM=0;
        FLAG_ALARM_RUN=0;
        FLAG_OVER_TIME_30S=0;
        FLAG_OVER_CURRENT=0;
        FLAG_ALARM_OVER1=0;
        FLAG_ALARM_OVER2=0;
    }
    else
    {
        if((FLAG_ALARM_RUN)||(FLAG_OVER_TIME_30S)||(FLAG_OVER_CURRENT))
        {                       
            RELAY_ALARM_LAT=0;
            if((FLAG_OVER_TIME_30S))
            {
                if(FLAG_ALARM_OVER1)    //�ڶ���ͬ�����ϣ�ֻ���ֶ���λ�������ٲ���
                {
                   FLAG_ALARM=1;    //�������ź�����
                }
                FLAG_ALARM_OVER1=1;
                FLAG_OVER_TIME_30S=0;
            }
            else  if((FLAG_OVER_CURRENT))
            {
                if(FLAG_ALARM_OVER2)    //�ڶ���ͬ�����ϣ�ֻ���ֶ���λ�������ٲ���
                {
                   FLAG_ALARM=1;    //�������ź�����
                }
                FLAG_ALARM_OVER2=1;
                FLAG_OVER_CURRENT=0;
            }
            else    //�����������Ͽ����߽ӵغ�բʱ��ĸ�߱պϣ�ֻ���ֶ���λ�������ٲ���
            {
                FLAG_ALARM=1;  //�������ź�����
            }
            
        }
        else if((!FLAG_ALARM_CMD)&&(!FLAG_ALARM_RUN)&&(!FLAG_OVER_TIME_30S)&&(!FLAG_OVER_CURRENT)&&(!FLAG_ALARM_OVER1)&&(!FLAG_ALARM_OVER2))    //����ȫ���ָ������ϳ��ռ̵�������Ͽ�
        {
            RELAY_ALARM_LAT=1;
        }
    }
}
void LED_CTRL(void)
{
//    if(FLAG_ALARM)
    {
        if(FLAG_OVER_TIME_30S)          //��ʱ����
        {
            led_time_40ms++;
            if(led_time_40ms>=25)
            {
                led_time_40ms=0;
                LED_ALARM_LAT = ~LED_ALARM_LAT;
            } 
                FLAG_QS_MOTOR_IN=0; //���ɿ��غ�բ��־λ
                FLAG_QS_MOTOR_OUT=0; //���ɿ��ط�բ��־λ
                FLAG_ES_MOTOR_IN=0; //�ӵؿ��غ�բ��־λ
                FLAG_ES_MOTOR_OUT=0; //�ӵؿ��ط�բ��־λ   
                FLAG_STORED_IN=0;
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

        if(FLAG_OVER_CURRENT)      //��ת����
        {
                LED_ALARM_LAT = 1;   
                FLAG_QS_MOTOR_IN=0; //���ɿ��غ�բ��־λ
                FLAG_QS_MOTOR_OUT=0; //���ɿ��ط�բ��־λ
                FLAG_ES_MOTOR_IN=0; //�ӵؿ��غ�բ��־λ
                FLAG_ES_MOTOR_OUT=0; //�ӵؿ��ط�բ��־λ   
                FLAG_STORED_IN=0;
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
        if(FLAG_ALARM_OVER1)    //���泬ʱ����
        {
            led_time_40ms++;
            if(led_time_40ms>=25)
            {
                led_time_40ms=0;
                LED_ALARM_LAT = ~LED_ALARM_LAT;
            }             
        }        
        else if(FLAG_ALARM_OVER2)   //�����ת����
        {
            LED_ALARM_LAT = 1;  
        }
        else if((FLAG_ALARM_CMD)||(FLAG_ALARM_RUN)) //ָ���쳣����������ĸ���쳣����
        {
            led_time_40ms++;
            if(led_time_40ms>=3)
            {
                led_time_40ms=0;
                LED_ALARM_LAT = ~LED_ALARM_LAT;
            } 
        }
        else    //ȫ������
        {
            LED_ALARM_LAT=0;   
            RELAY_ALARM_LAT=1;
        }        
    }

}
void MOTOR_CTRL(void)
{
  ///////////////////���ɿ��غ�բ����////////////////
    if(FLAG_QS_MOTOR_IN)
    {
        in_stop_order=1;
        
        switch(in_order)
        {            
            case 1:	
            {
                RELAY_Y2_LAT=1;
                in_order=4;
            }break;
            case 4:	
            {  
                MOS_Y2_LAT=1;
                in_order=6;
                
            }break;
            case 6:	
            {  
                test_time=0;
                motor_run_1s=0;
                in_order=5;
            }break;            
            case 5:	
            {
                
            }
        }
    }
    else    ///////////////////���ɿ��غ�բֹͣ////////////////
    {       
        in_order=1;
        switch(in_stop_order)
        {
            case 1:	
            {
                MOS_Y2_LAT=0;
                in_stop_order=2;
            }break;
            case 2:	
            {  
                RELAY_Y2_LAT=0;
                in_stop_order=3;
            }break;        
        }    
    }     
    ///////////////////���ɿ��ط�բ����////////////////
    if(FLAG_QS_MOTOR_OUT)
    {
        out_stop_order=1;
        switch(out_order)
        {              
            case 1:	
            {
                RELAY_Y1_LAT=1;
                out_order=4;
            }break;
            case 4:	
            {  
                MOS_Y1_LAT=1;
                test_time=0;
                motor_run_1s=0;
                out_order=6;
                //ADCC_DischargeSampleCapacitor();
            }break; 
            case 6:	
            {  
                //MOS_OPEN_LAT=1;
                test_time=0;
                motor_run_1s=0;
                out_order=5;
                //ADCC_DischargeSampleCapacitor();
            }break;             
            case 5:	
            {
                 
            }            
        }
    }
    else     ///////////////////���ɿ��ط�բֹͣ////////////////
    {    
        out_order=1;
         switch(out_stop_order)
        {
            case 1:	
            {
                MOS_Y1_LAT=0;
                out_stop_order=2;
            }break;
            case 2:	
            {  
                RELAY_Y1_LAT=0;
                out_stop_order=3;
            }break;        
        }
    }
 
///////////////////�ӵؿ��غ�բ����////////////////
    if(FLAG_ES_MOTOR_IN)
    {
        ES_in_stop_order=1;
        
        switch(ES_in_order)
        {
            case 1:	
            {
                
                MOS_ES_N_LAT=0;
                ES_in_order=2;
            }break;
            case 2:	
            {  
                RELAY_ES_N_LAT=0;
                ES_in_order=3;
                
            }break;              
            case 3:	
            {
                RELAY_ES_P_LAT=1;
                ES_in_order=4;
            }break;
            case 4:	
            {  
                MOS_ES_P_LAT=1;
                test_time=0;
                motor_run_1s=0;
                ES_in_order=6;
                
            }break;
            case 6:	
            {  
                test_time=0;
                motor_run_1s=0;
                ES_in_order=5;
            }break;            
            case 5:	
            {
                
            }
        }
    }
    else    ///////////////////�ӵؿ��غ�բֹͣ////////////////
    {       
        ES_in_order=1;
        switch(ES_in_stop_order)
        {
            case 1:	
            {
                MOS_ES_P_LAT=0;
                ES_in_stop_order=2;
            }break;
            case 2:	
            {  
                RELAY_ES_P_LAT=0;
                ES_in_stop_order=3;
            }break;        
        }    
    }     
    ///////////////////�ӵؿ��ط�բ����////////////////
    if(FLAG_ES_MOTOR_OUT)
    {
        ES_out_stop_order=1;
        switch(ES_out_order)
        {
            case 1:	
            {
                MOS_ES_P_LAT=0;
                ES_out_order=2;
            }break;
            case 2:	
            {  
                RELAY_ES_P_LAT=0;
                ES_out_order=3;
            }break;               
            case 3:	
            {
                RELAY_ES_N_LAT=1;
                ES_out_order=4;
            }break;
            case 4:	
            {  
                MOS_ES_N_LAT=1;
                test_time=0;
                motor_run_1s=0;                
                ES_out_order=6;
                //ADCC_DischargeSampleCapacitor();
            }break; 
            case 6:	
            {  
                //MOS_OPEN_LAT=1;
                test_time=0;
                motor_run_1s=0;
                ES_out_order=5;
                
                //ADCC_DischargeSampleCapacitor();
            }break;             
            case 5:	
            {
                 
            }            
        }
    }
    else    ///////////////////�ӵؿ��ط�բֹͣ////////////////
    {    
        ES_out_order=1;
         switch(ES_out_stop_order)
        {
            case 1:	
            {
                MOS_ES_N_LAT=0;
                ES_out_stop_order=2;
            }break;
            case 2:	
            {  
                RELAY_ES_N_LAT=0;
                ES_out_stop_order=3;
            }break;        
        }
    } 
    
//    if(FLAG_QS_MOTOR_OUT)
//    {
//        out_stop_order=1;
//        switch(out_order)
//        {
//            case 1:	
//            {
//                RELAY_Y1_LAT=1;
//                out_order=4;
//            }break;
//            case 4:	
//            {  
//                MOS_Y1_LAT=1;
//                test_time=0;
//                motor_run_1s=0;
//                out_order=5;
//                //ADCC_DischargeSampleCapacitor();
//            }break; 
//            case 6:	
//            {  
//                //MOS_OPEN_LAT=1;
//                out_order=5;
//                //ADCC_DischargeSampleCapacitor();
//            }break;             
//            case 5:	
//            {
//                 
//            }            
//        }
//    }
//    else     ///////////////////���ɿ��ط�բֹͣ////////////////
//    {    
//        out_order=1;
//         switch(out_stop_order)
//        {
//            case 1:	
//            {
//                MOS_Y1_LAT=0;
//                out_stop_order=2;
//            }break;
//            case 2:	
//            {  
//                RELAY_Y1_LAT=0;
//                out_stop_order=3;
//            }break;        
//        }
//    }
    if(FLAG_STORED_IN)
    {
        STORED_in_stop_order=1;
        
        switch(STORED_in_order)
        {
            case 1:	
            {
                MOS_REV_LAT=0;
                STORED_in_order=2;
            }break;
            case 2:	
            {  
                RELAY_REV_LAT=0;
                STORED_in_order=3;
                
            }break;              
            case 3:	
            {
                RELAY_STORED_LAT=1;
                STORED_in_order=4;
            }break;
            case 4:	
            {  
                MOS_STORED_LAT=1;
                test_time=0;
                motor_run_1s=0;
                STORED_in_order=6;
                
            }break;
            case 6:	
            {  
                test_time=0;
                motor_run_1s=0;
                STORED_in_order=5;
                
            }break;            
            case 5:	
            {
                
            }
        }
    }
    else    ///////////////////�ӵؿ��غ�բֹͣ////////////////
    {       
        STORED_in_order=1;
        switch(STORED_in_stop_order)
        {
            case 1:	
            {
                MOS_STORED_LAT=0;
                STORED_in_stop_order=2;
            }break;
            case 2:	
            {  
                RELAY_STORED_LAT=0;
                STORED_in_stop_order=3;
            }break;        
        }    
    }    
}