#include "mcc.h"
#include"head.h"

void data_init(void) 
{
//	RELAY_BREAK_WIRE=0;
//	RELAY_OVER_TEMP=0;
//    RELAY_OVER_RH=0;
//    RELAY_HEATER=0;
//    RELAY_BLOWER=0;
    
	lcd_display_time=0;
	lcd_page=1;         //Ĭ��ҳ��1----����ѹ��
	lcd_init();
	comm_out(0x29);			//����ʾ
	BACK_LIGHT_CONTROL=1;
	display_color(white);		
    flag_lcd_on=1;
	page1_fixed();      //Ĭ��ҳ��1----����ѹ��
	//page0_change();

}
