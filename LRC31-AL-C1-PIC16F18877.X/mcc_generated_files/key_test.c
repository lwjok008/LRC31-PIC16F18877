#include"mcc.h"
#include "head.h"
bit flag_force=0,FLAG_SET=0,FLAG_SET_page10=0,flag_force1,flag_force2,flag_force3;
bit FLAG_UP,FLAG_DOWN,FLAG_ENTER,FLAG_RETURN,FLAG_RESET;
bit flag_page10_set1=0,flag_page10_set2=0;
bit FLAG_ALL_RESET,FLAG_ALARM_RESET;
void key_test_AD(void)
{
    uint ad_value;
    ad_value = ADCC_GetSingleConversion(KEY_AD);
    if(((ad_value)>100)&&((ad_value)<200))     //0.5V S1
    {
        FLAG_RETURN=1;
    }
    else if(((ad_value)>250)&&((ad_value)<350))   //1V S2
    {
        FLAG_ENTER=1;
    }
    else if(((ad_value)>400)&&((ad_value)<500))   //1.5V S3
    {
        FLAG_RESET=1;
    }
    else if(((ad_value)>550)&&((ad_value)<650))   //2.0V S6
    {
        FLAG_UP=1;
    }
    else if(((ad_value)>750)&&((ad_value)<800))   //2.5V S5
    {
        FLAG_DOWN=1;
    }        
    ad_value=1024;
////////////////////////////////////////////////////////////////    
    if(FLAG_UP)
    {       
        ad_value = ADCC_GetSingleConversion(KEY_AD);
        if(ad_value>900)
        {      
            FLAG_UP=0;
            if(!FLAG_SET)
            {
                if(lcd_page<=9)			//第五页开始为设置页面
                {
                    lcd_page++;
                }
                else
                {
                    lcd_page=1;
                }
                switch(lcd_page)
                {
                    case 1:	page1_fixed(); break;
                    case 2:	page2_fixed(); break;
                    case 3:	page3_fixed(); break;
                    case 4:	page4_fixed(); break;
                    case 5: page5_fixed(); break;
                    case 6:	page6_fixed(); break;
                    case 7:	page7_fixed(); break;
                    case 8:	page8_fixed(); break;
                    case 9:	page9_fixed(); break;   
                    case 10:page10_fixed(); break; 
                }   
            }
            else
            {
                if((!flag_page10_set1)&&(!flag_page10_set2))
                {                
                    set++;
                    if(set>=2)			
                    {   
                        set=0;	
                    }	
                    switch(set)
                    {
                        case 0: parameter_set1(); break;
                        case 1:	parameter_set2(); break;             
                    }      
                }
            }            
        }
    }
    else if(FLAG_DOWN)
    {        
        ad_value = ADCC_GetSingleConversion(KEY_AD);
        if(ad_value>900)
        {          
            FLAG_DOWN=0;
            if(!FLAG_SET)
            {
                if(lcd_page>1)			//第五页开始为设置页面
                {
                    lcd_page--;
                }
                else
                {
                    lcd_page=10;
                }
                switch(lcd_page)
                {
                    case 1:	page1_fixed(); break;
                    case 2:	page2_fixed(); break;
                    case 3:	page3_fixed(); break;
                    case 4:	page4_fixed(); break;
                    case 5: page5_fixed(); break;
                    case 6:	page6_fixed(); break;
                    case 7:	page7_fixed(); break;
                    case 8:	page8_fixed(); break;
                    case 9:	page9_fixed(); break;   
                    case 10:page10_fixed(); break; 
                }   
            }
            else
            {
              
                if((!flag_page10_set1)&&(!flag_page10_set2))
                {
                    set++;
                    if(set>=2)			
                    {   
                        set=0;	
                    }	
                    switch(set)
                    {
                        case 0: parameter_set1(); break;
                        case 1:	parameter_set2(); break;             
                    }      
                }
                
            }
        }
    }
    else if(FLAG_ENTER)
    {    
            ad_value = ADCC_GetSingleConversion(KEY_AD);
            if(ad_value>900)
            {
                if(10==lcd_page)
                {                   
                    if(!FLAG_SET)
                    {
                        FLAG_SET_page10=1;
                        FLAG_SET=1;
                        set=0;
                        switch(set)
                        {
                            case 0: parameter_set1(); break;
                            case 1:	parameter_set2(); break;             
                        }  
                        FLAG_ENTER=0;
                    }
                    else
                    {        
                        if((!flag_page10_set1)&&(!flag_page10_set2))
                        {
                            switch(set)
                            {
                                case 0: 
                                {
                                    display_color(black);	//全屏写白色（清屏）	

                                    page10_set1();
                                    flag_page10_set1=1;
                                }break;
                                case 1:	
                                {
                                    display_color(black);	//全屏写白色（清屏）	

                                    page10_set2(); 
                                    flag_page10_set2=1;
                                }break;             
                            } 
                            FLAG_ENTER=0;
                        }
                        else
                        {
                            if(flag_page10_set1)
                            {
                                set=3;
                               if(FLAG_SET_page10)
                               {
                                   FLAG_SET_page10=0;
                                   FLAG_SET=0;
                                   page10_fixed();
                               }
                               if(flag_page10_set1)
                               {
                                   flag_page10_set1=0;
                               }
                               if(flag_page10_set2)
                               {
                                   flag_page10_set2=0;
                               } 
                                FLAG_ALL_RESET=1;
A_CLOSE_counter=0;B_CLOSE_counter=0;C_CLOSE_counter=0;
A_RUN_counter=0;B_RUN_counter=0;C_RUN_counter=0;
A_RUN_counter_24H=0;B_RUN_counter_24H=0;C_RUN_counter_24H=0;
for(i=0;i<10;i++)
{
    counter_timerAA[i]=0;
    counter_timerBB[i]=0;
    counter_timerCC[i]=0;
}
    //////////////////////////////////////
    //////////////////////////////////////
    //一键全部复位，此次添加复位变量和标志位//
    //////////////////////////////////////
    //////////////////////////////////////
                            }
                            else if(flag_page10_set2)
                            {
                                set=3;
                                if(FLAG_SET_page10)
                                {
                                    FLAG_SET_page10=0;
                                    FLAG_SET=0;
                                    page10_fixed();
                                }
                                if(flag_page10_set1)
                                {
                                    flag_page10_set1=0;
                                }
                                if(flag_page10_set2)
                                {
                                    flag_page10_set2=0;
                                } 
                                FLAG_ALARM_RESET=1;
    //////////////////////////////////////
    //////////////////////////////////////
    //报警复位，此次添加复位变量和标志位//
    //////////////////////////////////////
    //////////////////////////////////////                            
                            }
                        }
                    }   
                }
                
                FLAG_ENTER=0;
            }
            else
            {
                ;
            }              
        
    }
    else if(FLAG_RETURN)
    {
        ad_value = ADCC_GetSingleConversion(KEY_AD);
        if(ad_value>900)
        {           
            FLAG_RETURN=0;
            set=3;
            if(FLAG_SET_page10)
            {
                FLAG_SET_page10=0;
                FLAG_SET=0;
                page10_fixed();
            }
            if(flag_page10_set1)
            {
                flag_page10_set1=0;
            }
            if(flag_page10_set2)
            {
                flag_page10_set2=0;
            }   
        }
    } 
    else if(FLAG_RESET)
    {
        ad_value = ADCC_GetSingleConversion(KEY_AD);
        if(ad_value>900)
        {            
            FLAG_RESET=0;
        }
    }     
}










