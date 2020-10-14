#include"mcc.h"
#include "head.h"
bit flag_A_RUN_120S,flag_B_RUN_120S,flag_C_RUN_120S;
bit flag_A_RUN_120S_disp,flag_B_RUN_120S_disp,flag_C_RUN_120S_disp;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page6_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(16,2,6,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,chu3,white,black);  //  
    disp_16x16(16*3,2,neng,white,black);  //    
    disp_16x16(16*4,2,chao,white,black);  //  
    disp_16x16(16*5,2,shi1,white,black);  //   
    disp_16x16(16*6,2,xin,white,black);  //  
    disp_16x16(16*7,2,xi,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //      
disp_ASCII_8x16(16*2,32,36,yellow,black);	
    if(!flag_A_RUN_120S_disp)    
    {
        disp_16x16(16*4,32,zheng,white,black);  //  
        disp_16x16(16*5,32,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,32,chao,red,black);  //  
        disp_16x16(16*5,32,shi1,red,black);  // 
    }
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
disp_ASCII_8x16(16*2,64,36,green,black);	
    if(!flag_B_RUN_120S_disp)    
    {
        disp_16x16(16*4,64,zheng,white,black);  //  
        disp_16x16(16*5,64,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,64,chao,red,black);  //  
        disp_16x16(16*5,64,shi1,red,black);  //     
    }
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
disp_ASCII_8x16(16*2,96,36,red,black);	   
    if(!flag_C_RUN_120S_disp)    
    {
    disp_16x16(16*4,96,zheng,white,black);  //  
    disp_16x16(16*5,96,chang,white,black);  //   
    }
    else
    {
    disp_16x16(16*4,96,chao,red,black);  //  
    disp_16x16(16*5,96,shi1,red,black);  //      
    }
  
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page6_change(void)
{
    if(!flag_A_RUN_120S_disp)    
    {
        disp_16x16(16*4,32,zheng,white,black);  //  
        disp_16x16(16*5,32,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,32,chao,red,black);  //  
        disp_16x16(16*5,32,shi1,red,black);  //     
    }
    if(!flag_B_RUN_120S_disp)    
    {
        disp_16x16(16*4,64,zheng,white,black);  //  
        disp_16x16(16*5,64,chang,white,black);  // 
    }
    else
    {
        disp_16x16(16*4,64,chao,red,black);  //  
        disp_16x16(16*5,64,shi1,red,black);  //     
    }
    if(!flag_C_RUN_120S_disp)    
    {
    disp_16x16(16*4,96,zheng,white,black);  //  
    disp_16x16(16*5,96,chang,white,black);  //   
    }
    else
    {
    disp_16x16(16*4,96,chao,red,black);  //  
    disp_16x16(16*5,96,shi1,red,black);  //      
    }
}
