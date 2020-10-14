#include"mcc.h"
#include "head.h"
bit flag_pressA_NG,flag_pressB_NG,flag_pressC_NG;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page1_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(16,2,1,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,tan,white,black);  //  
    disp_16x16(16*3,2,huang,white,black);  //    
    disp_16x16(16*4,2,ya,white,black);  //  
    disp_16x16(16*5,2,li,white,black);  //   

    disp_16x16(16*6,2,zhuang,white,black);  //  
    disp_16x16(16*7,2,tai,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //    
    disp_16x16(16*2,32,ya,yellow,black);  //  
    disp_16x16(16*3,32,li,yellow,black);  //   
disp_ASCII_8x16(16*4,32,36,yellow,black);	
    if(!flag_pressA_NG)    
    {
        disp_16x16(16*6,32,zheng,white,black);  //  
        disp_16x16(16*7,32,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*6,32,bu,red,black);  //  
        disp_16x16(16*7,32,zu,red,black);  // 
    }
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
    disp_16x16(16*2,64,ya,green,black);  //  
    disp_16x16(16*3,64,li,green,black);  // 
disp_ASCII_8x16(16*4,64,36,green,black);	
    if(!flag_pressB_NG)    
    {
        disp_16x16(16*6,64,zheng,white,black);  //  
        disp_16x16(16*7,64,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*6,64,bu,red,black);  //  
        disp_16x16(16*7,64,zu,red,black);  //     
    }
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
    disp_16x16(16*2,96,ya,red,black);  //  
    disp_16x16(16*3,96,li,red,black);  //   
disp_ASCII_8x16(16*4,96,36,red,black);	   
    if(!flag_pressC_NG)    
    {
    disp_16x16(16*6,96,zheng,white,black);  //  
    disp_16x16(16*7,96,chang,white,black);  //   
    }
    else
    {
    disp_16x16(16*6,96,bu,red,black);  //  
    disp_16x16(16*7,96,zu,red,black);  //      
    }
  
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page1_change(void)
{
    if(!flag_pressA_NG)    
    {
        disp_16x16(16*6,32,zheng,white,black);  //  
        disp_16x16(16*7,32,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*6,32,bu,red,black);  //  
        disp_16x16(16*7,32,zu,red,black);  //     
    }
    if(!flag_pressB_NG)    
    {
        disp_16x16(16*6,64,zheng,white,black);  //  
        disp_16x16(16*7,64,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*6,64,bu,red,black);  //  
        disp_16x16(16*7,64,zu,red,black);  //     
    }
    if(!flag_pressC_NG)    
    {
    disp_16x16(16*6,96,zheng,white,black);  //  
    disp_16x16(16*7,96,chang,white,black);  //   
    }
    else
    {
    disp_16x16(16*6,96,bu,red,black);  //  
    disp_16x16(16*7,96,zu,red,black);  //      
    }
}
