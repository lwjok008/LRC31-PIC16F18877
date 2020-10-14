#include"mcc.h"
#include "head.h"
uint A_RUN_counter_24H,B_RUN_counter_24H,C_RUN_counter_24H;

////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page5_fixed()
{
   
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
    disp_ASCII_8x16(0,2,5,red,black);	 
    disp_ASCII_8x16(8+8,2,2,white,black);	
    disp_ASCII_8x16(16+8,2,4,white,black);	
    disp_16x16(16*1+8+8,2,xiao,white,black);  //  
    disp_16x16(16*2+8+8,2,shi1,white,black);  //   	
    disp_16x16(16*3+8+8,2,dian4,white,black);  //  
    disp_16x16(16*4+8+8,2,ji,white,black);  //    
    disp_16x16(16*5+8+8,2,qi3,white,black);  //  
    disp_16x16(16*6+8+8,2,dong,white,black);  //   
    disp_16x16(16*7+8+8,2,ci,white,black);  //  
    disp_16x16(16*8+8+8,2,shu,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //    
    disp_16x16(16*2,32,yun,yellow,black);  //  
    disp_16x16(16*3,32,xing,yellow,black);  //   
disp_ASCII_8x16(16*4,32,36,yellow,black);	
h_bcd(A_RUN_counter_24H);
if(A_RUN_counter_24H>10)
{
    disp_ASCII_8x16(16*5,32,49,red,black);
    disp_ASCII_8x16(16*5+8,32,1,red,black);
    disp_ASCII_8x16(16*6,32,0,red,black);
}
else
{
    disp_ASCII_8x16(16*5+8,32,shi,white,black);
    disp_ASCII_8x16(16*6,32,ge,white,black);
}
    disp_16x16(16*6+8,32,ci,white,black);  //  
    //disp_ASCII_8x16(16*6+8,32,qian,green,black);

    
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
    disp_16x16(16*2,64,yun,green,black);  //  
    disp_16x16(16*3,64,xing,green,black);  // 
disp_ASCII_8x16(16*4,64,36,green,black);
h_bcd(B_RUN_counter_24H);
if(B_RUN_counter_24H>10)
{
    //disp_ASCII_8x16(16*6+8,64,qian,green,black);
    disp_ASCII_8x16(16*5,64,49,red,black);
    disp_ASCII_8x16(16*5+8,64,1,red,black);
    disp_ASCII_8x16(16*6,64,0,red,black);

}
else
{
    disp_ASCII_8x16(16*5+8,64,shi,white,black);
    disp_ASCII_8x16(16*6,64,ge,white,black);
}
    disp_16x16(16*6+8,64,ci,white,black);  //
    
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
    disp_16x16(16*2,96,yun,red,black);  //  
    disp_16x16(16*3,96,xing,red,black);  //   
disp_ASCII_8x16(16*4,96,36,red,black);	
h_bcd(C_RUN_counter_24H);
if(C_RUN_counter_24H>10)
{
    //disp_ASCII_8x16(16*6+8,96,qian,green,black);
    disp_ASCII_8x16(16*5,96,49,red,black);
    disp_ASCII_8x16(16*5+8,96,1,red,black);
    disp_ASCII_8x16(16*6,96,0,red,black);

}
else
{
    disp_ASCII_8x16(16*5+8,96,shi,white,black);
    disp_ASCII_8x16(16*6,96,ge,white,black);
}
    disp_16x16(16*6+8,96,ci,white,black);  // 
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page5_change(void)
{
h_bcd(A_RUN_counter_24H);
if(A_RUN_counter_24H>10)
{
    disp_ASCII_8x16(16*5,32,49,red,black);
    disp_ASCII_8x16(16*5+8,32,1,red,black);
    disp_ASCII_8x16(16*6,32,0,red,black);
}
else
{
    disp_ASCII_8x16(16*5+8,32,shi,white,black);
    disp_ASCII_8x16(16*6,32,ge,white,black);
}
    
h_bcd(B_RUN_counter_24H);
if(B_RUN_counter_24H>10)
{
    //disp_ASCII_8x16(16*6+8,64,qian,green,black);
    disp_ASCII_8x16(16*5,64,49,red,black);
    disp_ASCII_8x16(16*5+8,64,1,red,black);
    disp_ASCII_8x16(16*6,64,0,red,black);

}
else
{
    disp_ASCII_8x16(16*5+8,64,shi,white,black);
    disp_ASCII_8x16(16*6,64,ge,white,black);
}
    
h_bcd(C_RUN_counter_24H);
if(C_RUN_counter_24H>10)
{
    //disp_ASCII_8x16(16*6+8,96,qian,green,black);
    disp_ASCII_8x16(16*5,96,49,red,black);
    disp_ASCII_8x16(16*5+8,96,1,red,black);
    disp_ASCII_8x16(16*6,96,0,red,black);

}
else
{
    disp_ASCII_8x16(16*5+8,96,shi,white,black);
    disp_ASCII_8x16(16*6,96,ge,white,black);
}

}
