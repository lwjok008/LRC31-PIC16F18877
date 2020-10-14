#include"mcc.h"
#include "head.h"
#include "font_library.h"
uint16_t TEMP_SUB=5,RH_ALARM=90,TEMP_ALARM=50;
uint16_t RH_HEATER=85,RH_BLOWER=85,TEMP_HEATER=5,TEMP_BLOWER=50;
uint16_t HEATER_CURRENT=1,temperature_value=0;
uint8_t HEAT1_RUN_SET=10,HEAT2_RUN_SET=10,HEAT3_RUN_SET=10,HEAT1_STOP_SET=20,HEAT2_STOP_SET=20,HEAT3_STOP_SET=20;
bit FLAG_HEAT1_RUN,FLAG_HEAT2_RUN,FLAG_HEAT3_RUN,FLAG_HEAT1_BREAK,FLAG_HEAT2_BREAK,FLAG_HEAT3_BREAK;
bit flag_set_ok=0;

/*

page1---储能弹簧压力状态
page2--合闸总次数
page3--储能电机启动次数
page4--24小时启动次数
page5--启动120S倒计时
page6--储能超时信息
page7--24小时启动次数
page8--电机运行状态
page9--电机运行电流
page10--复位设置
*/
//////////////////////////////////////////////////////////////////////////////////////////
void lcd_page_display()		
{
    switch(lcd_page)
    {
        case 1:	page1_change(); break;
        case 2:	page2_change(); break;
        case 3:	page3_change(); break;
        case 4:	page4_change(); break;
        case 5: page5_change(); break;
        case 6:	page6_change(); break;
        case 7:	page7_change(); break;
        case 8:	page8_change(); break;
        case 9:	page9_change(); break;   
        case 10:
        {
            if(!FLAG_SET)
            {
                page10_change(); 
            }
            else
            {
                if((!flag_page10_set1)&&(!flag_page10_set2))
                {
                    switch(set)
                    {
                        case 0: parameter_set1(); break;
                        case 1:	parameter_set2(); break;              
                    }   
                }
                else
                {
                    switch(set)
                    {
                        case 0: page10_set1();; break;
                        case 1:	page10_set2(); break;             
                    }                  
                }
            }
        } break; 
    }      
}
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page0_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
				
	disp_24x21(24*1+6,2,shi2,white,black);	//实时温度
	disp_24x21(24*2+6,2,shi1,white,black);
	disp_24x21(24*3+6,2,wen,white,black);
	disp_24x21(24*4+6,2,du,white,black);

    disp_16x16(24*5+10,72,ssd1,white,black);  //    
    

    h_bcd(temperature_value);	
//    if(FLAG_TEMP_BREAK)
//    {
//        bai=11;shi=11;ge=11;
//        flag_minus=0;
//    }    
//    if(flag_minus)
//    {
//        disp_num_24x48(4+8,48,11,red,white);	
//    }
//    else
//    {
//        disp_num_24x48(4+8,48,12,red,white);	
//    }         
//    disp_num_24x48(4+24+8,48,bai,red,white);	
//    disp_num_24x48(4+48+12,48,shi,red,white);
    disp_num_24x48(4+72+12,48,10,white,black);  //
//    disp_num_24x48(4+96,48,ge,red,black);

    if(FLAG_TEMP_BREAK)
    {
        bai=11;shi=11;ge=11;
        flag_minus=0;
    }    
    if(flag_minus)
    {
        disp_num_24x48(4+8,48,11,white,black);	
    }
    else
    {
        disp_num_24x48(4+8,48,12,white,black);	
    }      
    if(bai==0)   
    {
        disp_num_24x48(4+24+8,48,12,white,black);	
    }
    else
    {
        disp_num_24x48(4+24+8,48,bai,white,black);	
    }
    disp_num_24x48(4+48+12,48,shi,white,black);    
    disp_num_24x48(4+96,48,ge,white,black);
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page0_change(void)
{
    
    h_bcd(temperature_value);	
    if(FLAG_TEMP_BREAK)
    {
        bai=11;shi=11;ge=11;
        flag_minus=0;
    }    
    if(flag_minus)
    {
        disp_num_24x48(4+8,48,11,white,black);	
    }
    else
    {
        disp_num_24x48(4+8,48,12,white,black);	
    }      
    if(bai==0)   
    {
        disp_num_24x48(4+24+8,48,12,white,black);	
    }
    else
    {
        disp_num_24x48(4+24+8,48,bai,white,black);	
    }
    disp_num_24x48(4+48+12,48,shi,white,black);    
    disp_num_24x48(4+96,48,ge,white,black);
}


void h_bcd(uint x)
{

	qian=x/1000%10;
	bai=x/100%10;
	shi=x/10%10;
	ge=x%10;

}

//显示16x21点阵数字，或相当于16x21点阵的图像。温馨提示，
void disp_num_16x21(int x,int y, uchar number,int font_color,int back_color)
{
	int i,j,k;
	k=0;
	lcd_address(x,y,16,21);
	for(i=0;i<21;i++)		//高度21
	{
		for(j=0;j<2;j++)	//宽度 2*8=16
		{
			mono_data_out(_num[number][k],font_color,back_color);
			k++;
		}
	}
}

///*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
void disp_num_24x48(int x,int y, uchar number,int font_color,int back_color)
{
	int i,j,k;
	k=0;
	lcd_address(x,y,24,48);
	for(i=0;i<48;i++)		//高度21
	{
		for(j=0;j<3;j++)	//宽度 2*8=16
		{
			mono_data_out(NUM1[number][k],font_color,back_color);
			k++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set0()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//    if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//    if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//
//void parameter_set3()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,white);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,white);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//    if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//    if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set4()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,white);
//    disp_ASCII_8x16(56+8+8,48,ge,green,white);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//    if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//    if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set5()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,white);
//    disp_ASCII_8x16(96+8+8,48,ge,red,white);	
//    if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//    if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set6()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//    if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,white);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,white);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//        if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
//            
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set7()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//        if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,white);
//    disp_ASCII_8x16(56+8+8,68,ge,green,white);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//        if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set8()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//        if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,white);
//    disp_ASCII_8x16(96+8+8,68,ge,red,white);	
//        if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,black);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,black);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////
//void parameter_set9()
//{
///////////////////////////////////////////////////////////////////    
//	h_bcd(HEAT1_RUN_SET);                       //HEAT1_value:
//    disp_ASCII_8x16(56+8,28,shi,green,black);
//    disp_ASCII_8x16(56+8+8,28,ge,green,black);
//    
//	h_bcd(HEAT1_STOP_SET);
//    disp_ASCII_8x16(96+8,28,shi,red,black);
//    disp_ASCII_8x16(96+8+8,28,ge,red,black);	
//    if(flag_force1)    {        disp_ASCII_8x16(96+40,28,15,red,black);     }    else    {        disp_ASCII_8x16(96+40,28,10,red,black);             }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT2_RUN_SET);                        //HEAT2_value:
//    disp_ASCII_8x16(56+8,48,shi,green,black);
//    disp_ASCII_8x16(56+8+8,48,ge,green,black);
//    
//	h_bcd(HEAT2_STOP_SET);
//    disp_ASCII_8x16(96+8,48,shi,red,black);
//    disp_ASCII_8x16(96+8+8,48,ge,red,black);	
//        if(flag_force2)    {        disp_ASCII_8x16(96+40,48,15,red,black);        }    else    {        disp_ASCII_8x16(96+40,48,10,red,black);        }	    
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//	h_bcd(HEAT3_RUN_SET);                        //HEAT3_value:
//    disp_ASCII_8x16(56+8,68,shi,green,black);
//    disp_ASCII_8x16(56+8+8,68,ge,green,black);
//    
//	h_bcd(HEAT3_STOP_SET);
//    disp_ASCII_8x16(96+8,68,shi,red,black);
//    disp_ASCII_8x16(96+8+8,68,ge,red,black);	
//    if(flag_force3)    {        disp_ASCII_8x16(96+40,68,15,red,white);    }    else    {        disp_ASCII_8x16(96+40,68,10,red,white);        }	
///////////////////////////////////////////////////////////////////
//}
///////////////////////////////////////////////////////////////////////////////////////////