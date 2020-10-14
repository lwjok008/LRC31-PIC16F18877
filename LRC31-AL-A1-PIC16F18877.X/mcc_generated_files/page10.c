#include"mcc.h"
#include "head.h"

////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page10_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(8,2,1,red,black);	
    disp_ASCII_8x16(16,2,0,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		

    disp_16x16(16*3,2,fu,white,black);  //    
    disp_16x16(16*4,2,wei,white,black);  //  
    disp_16x16(16*5,2,she,white,black);  //   
    disp_16x16(16*6,2,zhi4,white,black);  //  

//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*2,32,yi,white,black);  //  
    disp_16x16(16*3,32,jian,white,black);  //    
    disp_16x16(16*4,32,quan,white,black);  //  
    disp_16x16(16*5,32,bu4,white,black);  //   
    disp_16x16(16*6,32,fu,white,black);  //  
    disp_16x16(16*7,32,wei,white,black);  //   

    disp_16x16(16*3,64,bao,white,black);  //    
    disp_16x16(16*4,64,jing,white,black);  //  
    disp_16x16(16*5,64,fu,white,black);  //   
    disp_16x16(16*6,64,wei,white,black);  //  

  
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page10_change(void)
{

/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(8,2,1,red,black);	
    disp_ASCII_8x16(16,2,0,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		

    disp_16x16(16*3,2,fu,white,black);  //    
    disp_16x16(16*4,2,wei,white,black);  //  
    disp_16x16(16*5,2,she,white,black);  //   
    disp_16x16(16*6,2,zhi4,white,black);  //  
    
    disp_16x16(16*2,32,yi,white,black);  //  
    disp_16x16(16*3,32,jian,white,black);  //    
    disp_16x16(16*4,32,quan,white,black);  //  
    disp_16x16(16*5,32,bu4,white,black);  //   
    disp_16x16(16*6,32,fu,white,black);  //  
    disp_16x16(16*7,32,wei,white,black);  //   

    disp_16x16(16*3,64,bao,white,black);  //    
    disp_16x16(16*4,64,jing,white,black);  //  
    disp_16x16(16*5,64,fu,white,black);  //   
    disp_16x16(16*6,64,wei,white,black);  // 
}

void parameter_set1()
{
    disp_16x16(16*2,32,yi,red,white);  //  
    disp_16x16(16*3,32,jian,red,white);  //    
    disp_16x16(16*4,32,quan,red,white);  //  
    disp_16x16(16*5,32,bu4,red,white);  //   
    disp_16x16(16*6,32,fu,red,white);  //  
    disp_16x16(16*7,32,wei,red,white);  //   

    disp_16x16(16*3,64,bao,white,black);  //    
    disp_16x16(16*4,64,jing,white,black);  //  
    disp_16x16(16*5,64,fu,white,black);  //   
    disp_16x16(16*6,64,wei,white,black);  // 

}
/////////////////////////////////////////////////////////////////////////////////////////
void parameter_set2()
{
    disp_16x16(16*2,32,yi,white,black);  //  
    disp_16x16(16*3,32,jian,white,black);  //    
    disp_16x16(16*4,32,quan,white,black);  //  
    disp_16x16(16*5,32,bu4,white,black);  //   
    disp_16x16(16*6,32,fu,white,black);  //  
    disp_16x16(16*7,32,wei,white,black);  //   

    disp_16x16(16*3,64,bao,red,white);  //    
    disp_16x16(16*4,64,jing,red,white);  //  
    disp_16x16(16*5,64,fu,red,white);  //   
    disp_16x16(16*6,64,wei,red,white);  // 
}
void page10_set1()
{

    disp_16x16(16*1,2,que,white,black);  //    
    disp_16x16(16*2,2,ren,white,black);  //  
    disp_16x16(16*3,2,yi,white,black);  //   
    disp_16x16(16*4,2,jian,white,black);  //  
    disp_16x16(16*5,2,quan,white,black);  //   
    disp_16x16(16*6,2,bu4,white,black);  //  
    disp_16x16(16*7,2,fu,white,black);  //  
    disp_16x16(16*8,2,wei,white,black);  //    
    disp_ASCII_8x16(16*9,2,53,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	
}
void page10_set2()
{
    disp_16x16(16*2,2,que,white,black);  //    
    disp_16x16(16*3,2,ren,white,black);  //  
    disp_16x16(16*4,2,bao,white,black);  //   
    disp_16x16(16*5,2,jing,white,black);  //  
    disp_16x16(16*6,2,fu,white,black);  //   
    disp_16x16(16*7,2,wei,white,black);  //     
    disp_ASCII_8x16(16*8,2,53,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	
}
/////////////////////////////////////////////////////////////////////////////////////////