#include"mcc.h"
#include "head.h"
uint A_RUN_counter_120S,B_RUN_counter_120S,C_RUN_counter_120S;
////////////////////////������ʾʵʱ�¶���ֵ//////////////////////////////////////////////////////////////////////
void page4_fixed()
{
	display_color(black);	//ȫ��д��ɫ��������	
	line_display_color(0,23,black);  //��һ�б����� ��ɫ����
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
    disp_ASCII_8x16(16,2,4,red,black);	 
//    disp_ASCII_8x16(0,2,1,white,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,dian4,white,black);  //  
    disp_16x16(16*3,2,ji,white,black);  //    
    disp_16x16(16*4,2,yun,white,black);  //  
    disp_16x16(16*5,2,xing,white,black);  //   
    disp_16x16(16*6,2,ji4,white,black);  //  
    disp_16x16(16*7,2,shi1,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //    
    disp_16x16(16*2,32,yun,yellow,black);  //  
    disp_16x16(16*3,32,xing,yellow,black);  //   
disp_ASCII_8x16(16*4,32,36,yellow,black);	
h_bcd(A_RUN_counter_120S);
if(A_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,32,bai,red,black);
    disp_ASCII_8x16(16*6+8,32,shi,red,black);
    disp_ASCII_8x16(16*7,32,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,32,bai,white,black);
    disp_ASCII_8x16(16*6+8,32,shi,white,black);
    disp_ASCII_8x16(16*7,32,ge,white,black);
}

    disp_16x16(16*8,32,miao,white,black);  //
    
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
    disp_16x16(16*2,64,yun,green,black);  //  
    disp_16x16(16*3,64,xing,green,black);  // 
disp_ASCII_8x16(16*4,64,36,green,black);
h_bcd(B_RUN_counter_120S);
if(B_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,64,bai,red,black);
    disp_ASCII_8x16(16*6+8,64,shi,red,black);
    disp_ASCII_8x16(16*7,64,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,64,bai,white,black);
    disp_ASCII_8x16(16*6+8,64,shi,white,black);
    disp_ASCII_8x16(16*7,64,ge,white,black);
}
    disp_16x16(16*8,64,miao,white,black);  //
    
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
    disp_16x16(16*2,96,yun,red,black);  //  
    disp_16x16(16*3,96,xing,red,black);  //   
disp_ASCII_8x16(16*4,96,36,red,black);	
h_bcd(C_RUN_counter_120S);
if(C_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,96,bai,red,black);
    disp_ASCII_8x16(16*6+8,96,shi,red,black);
    disp_ASCII_8x16(16*7,96,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,96,bai,white,black);
    disp_ASCII_8x16(16*6+8,96,shi,white,black);
    disp_ASCII_8x16(16*7,96,ge,white,black);
}
    disp_16x16(16*8,96,miao,white,black);  //  
}

///////////////////////////////////ʵʱ�¶ȱ仯�ֲ�ˢ����ʾ////////////////////////////////////////////////////////////
void page4_change(void)
{
h_bcd(A_RUN_counter_120S);
if(A_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,32,bai,red,black);
    disp_ASCII_8x16(16*6+8,32,shi,red,black);
    disp_ASCII_8x16(16*7,32,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,32,bai,white,black);
    disp_ASCII_8x16(16*6+8,32,shi,white,black);
    disp_ASCII_8x16(16*7,32,ge,white,black);
}

h_bcd(B_RUN_counter_120S);
if(B_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,64,bai,red,black);
    disp_ASCII_8x16(16*6+8,64,shi,red,black);
    disp_ASCII_8x16(16*7,64,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,64,bai,white,black);
    disp_ASCII_8x16(16*6+8,64,shi,white,black);
    disp_ASCII_8x16(16*7,64,ge,white,black);
}
h_bcd(C_RUN_counter_120S);
if(C_RUN_counter_120S>=120)
{
    disp_ASCII_8x16(16*6,96,bai,red,black);
    disp_ASCII_8x16(16*6+8,96,shi,red,black);
    disp_ASCII_8x16(16*7,96,ge,red,black);
}
else
{
    disp_ASCII_8x16(16*6,96,bai,white,black);
    disp_ASCII_8x16(16*6+8,96,shi,white,black);
    disp_ASCII_8x16(16*7,96,ge,white,black);
}
}
