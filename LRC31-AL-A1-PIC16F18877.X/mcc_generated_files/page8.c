#include"mcc.h"
#include "head.h"
bit flag_runA,flag_runB,flag_runC;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page8_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(16,2,8,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,dian4,white,black);  //  
    disp_16x16(16*3,2,ji,white,black);  //    
    disp_16x16(16*4,2,yun,white,black);  //  
    disp_16x16(16*5,2,xing,white,black);  //   
    disp_16x16(16*6,2,zhuang,white,black);  //  
    disp_16x16(16*7,2,tai,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //      
disp_ASCII_8x16(16*2,32,36,yellow,black);	
    if(!flag_runA)    
    {
        disp_16x16(16*4,32,ting,white,black);  //  
        disp_16x16(16*5,32,zhi,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,32,qi3,red,black);  //  
        disp_16x16(16*5,32,dong,red,black);  // 
    }
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
disp_ASCII_8x16(16*2,64,36,green,black);	
    if(!flag_runB)    
    {
        disp_16x16(16*4,64,ting,white,black);  //  
        disp_16x16(16*5,64,zhi,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,64,qi3,red,black);  //  
        disp_16x16(16*5,64,dong,red,black);  //     
    }
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
disp_ASCII_8x16(16*2,96,36,red,black);	   
    if(!flag_runC)    
    {
    disp_16x16(16*4,96,ting,white,black);  //  
    disp_16x16(16*5,96,zhi,white,black);  //   
    }
    else
    {
    disp_16x16(16*4,96,qi3,red,black);  //  
    disp_16x16(16*5,96,dong,red,black);  //      
    }
  
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page8_change(void)
{
    if(!flag_runA)    
    {
        disp_16x16(16*4,32,ting,white,black);  //  
        disp_16x16(16*5,32,zhi,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,32,qi3,red,black);  //  
        disp_16x16(16*5,32,dong,red,black);  // 
    }
    if(!flag_runB)    
    {
        disp_16x16(16*4,64,ting,white,black);  //  
        disp_16x16(16*5,64,zhi,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,64,qi3,red,black);  //  
        disp_16x16(16*5,64,dong,red,black);  //     
    }
    if(!flag_runC)    
    {
    disp_16x16(16*4,96,ting,white,black);  //  
    disp_16x16(16*5,96,zhi,white,black);  //   
    }
    else
    {
    disp_16x16(16*4,96,qi3,red,black);  //  
    disp_16x16(16*5,96,dong,red,black);  //      
    }
}
