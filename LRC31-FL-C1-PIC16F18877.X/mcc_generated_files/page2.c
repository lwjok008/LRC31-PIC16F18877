
#include"mcc.h"
#include "head.h"
uint A_CLOSE_counter,B_CLOSE_counter,C_CLOSE_counter;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page2_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
    disp_ASCII_8x16(16,2,2,red,black);	 
//    disp_ASCII_8x16(0,2,1,white,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,he,white,black);  //  
    disp_16x16(16*3,2,za,white,black);  //    
    disp_16x16(16*4,2,ci,white,black);  //  
    disp_16x16(16*5,2,shu,white,black);  //   
    disp_16x16(16*6,2,ji4,white,black);  //  
    disp_16x16(16*7,2,shu,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

    disp_16x16(16*0+8,32,A,yellow,black);  //  
    disp_16x16(16*1,32,xiang,yellow,black);  //    
    disp_16x16(16*2,32,ci,yellow,black);  //  
    disp_16x16(16*3,32,shu,yellow,black);  //   
disp_ASCII_8x16(16*4,32,36,yellow,black);	
h_bcd(A_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,32,qian,white,black);
    disp_ASCII_8x16(16*6,32,bai,white,black);
    disp_ASCII_8x16(16*6+8,32,shi,white,black);
    disp_ASCII_8x16(16*7,32,ge,white,black);
    disp_16x16(16*8,32,ci,white,black);  // 
    
    disp_16x16(16*0+8,64,B,green,black);  //  
    disp_16x16(16*1,64,xiang,green,black);  //    
    disp_16x16(16*2,64,ci,green,black);  //  
    disp_16x16(16*3,64,shu,green,black);  // 
disp_ASCII_8x16(16*4,64,36,green,black);
h_bcd(B_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,64,qian,white,black);
    disp_ASCII_8x16(16*6,64,bai,white,black);
    disp_ASCII_8x16(16*6+8,64,shi,white,black);
    disp_ASCII_8x16(16*7,64,ge,white,black);
    disp_16x16(16*8,64,ci,white,black);  // 
    
    disp_16x16(16*0+8,96,C,red,black);  //  
    disp_16x16(16*1,96,xiang,red,black);  //    
    disp_16x16(16*2,96,ci,red,black);  //  
    disp_16x16(16*3,96,shu,red,black);  //   
disp_ASCII_8x16(16*4,96,36,red,black);	
h_bcd(C_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,96,qian,white,black);
    disp_ASCII_8x16(16*6,96,bai,white,black);
    disp_ASCII_8x16(16*6+8,96,shi,white,black);
    disp_ASCII_8x16(16*7,96,ge,white,black);
    disp_16x16(16*8,96,ci,white,black);  //   
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page2_change(void)
{
h_bcd(A_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,32,qian,white,black);
    disp_ASCII_8x16(16*6,32,bai,white,black);
    disp_ASCII_8x16(16*6+8,32,shi,white,black);
    disp_ASCII_8x16(16*7,32,ge,white,black);

    
h_bcd(B_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,64,qian,white,black);
    disp_ASCII_8x16(16*6,64,bai,white,black);
    disp_ASCII_8x16(16*6+8,64,shi,white,black);
    disp_ASCII_8x16(16*7,64,ge,white,black);

    

h_bcd(C_CLOSE_counter);
    disp_ASCII_8x16(16*5+8,96,qian,white,black);
    disp_ASCII_8x16(16*6,96,bai,white,black);
    disp_ASCII_8x16(16*6+8,96,shi,white,black);
    disp_ASCII_8x16(16*7,96,ge,white,black);

}
