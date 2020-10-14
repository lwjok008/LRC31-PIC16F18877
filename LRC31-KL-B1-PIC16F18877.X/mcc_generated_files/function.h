#ifndef __FUNCTION_H
#define __FUNCTION_H
#include "hal.h"

extern void get_t1(void);

extern void reset_temp1(void);

extern void write_t1(uchar val);

extern  uchar read_t1(void);

extern  void delayus1(uint x,uchar y);  //延时x微秒

extern  void hal_init(void);

extern  void data_init(void);

extern  void OUTPUT_CTRL(void);

extern  uchar crc8_check(uchar *ptr,uchar len);

extern void crc_check(uchar *ptr,uchar len);

extern	void delay(uint x);

extern  void delayus(uint x);

extern  void key_test_AD(void);

extern void alarm_reset(void);

extern  void lcd_page_display(void);

extern    uint get_ad(void);

extern 	void h_bcd(uint x);

extern 	void usart_server(void);

extern	void data_out(uchar data);
extern	void data_out_16(uint data_16bit);
extern	void comm_out(uchar com);
extern	void lcd_init(void);
extern	void lcd_address(uint XS,uint YS,uint x_total,uint y_total);		//设置窗口坐标
extern	void LCD_SetPos(uint x,uint y);		//设置像素点坐标
extern	void display_color(uint color);		//显示全屏单一颜色
extern	void display_image(uchar *dp);		//显示一幅全屏彩图
extern  void line_display_color(uchar y_start, uchar y_end, uint color);  //显示整行单一颜色
extern	void mono_data_out(uchar mono_data,uint font_color,uint back_color); //将单色的8位的数据（代表8个像素点）转换成彩色的数据传输给液晶屏
extern	void mono_data_out_5x8(uchar mono_data,uint font_color,uint back_color);	//将单色的8位的数据的高5位（代表5个像素点）转换成彩色的数据传输给液晶屏
extern	void disp_24x21(int x,int y,char *dp,int font_color,int back_color);
extern	void disp_16x21(int x,int y,char *dp,int font_color,int back_color);       //显示16*21字符
extern	void disp_num_16x21(int x,int y, uchar number,int font_color,int back_color);		//显示数字
extern	void disp_num_24x48(int x,int y, uchar number,int font_color,int back_color);
extern	void disp_16x16(int x,int y,char *dp,int font_color,int back_color);
extern	void disp_ASCII_8x16(int x,int y, uchar number,int font_color,int back_color);
extern	void disp_24x24(int x,int y,char *dp,int font_color,int back_color);
extern  void draw_point(uint x, uint y, uint color);
extern  void vDraw_Line(uint x1,uint y1,uint x2,uint y2,uint Fg_Color);
extern  void page0_fixed(void);   //页面0固有模式			实时电流
extern	void page0_change(void); //页面0数字变化部分

extern  void page1_fixed(void);   //页面1固有模式         实时温度
extern	void page1_change(void); //页面1数字变化部分

extern  void page2_fixed(void);   //页面2固有模式			实时电压（电池）
extern	void page2_change(void); //页面2数字变化部分

extern  void page3_fixed(void);   //页面3固有模式			已设定参数：短路电流、接地电流、报警温度
extern	void page3_change(void); //页面3数字变化部分

extern  void page4_fixed(void);   //页面4固有模式			参数设置
extern	void page4_change(void); //页面4数字变化部分


extern  void page5_fixed(void);   //页面5固有模式			短路电流设置
extern	void page5_change(void); //页面5数字变化部分

extern  void page6_fixed(void);   //页面6固有模式			接地电流设置
extern	void page6_change(void); //页面6数字变化部分

extern  void page7_fixed(void);   //页面7固有模式			报警温度设置
extern	void page7_change(void); //页面7数字变化部分

extern  void page8_fixed(void);   //页面8固有模式			通讯地址设置
extern	void page8_change(void); //页面8数字变化部分

extern  void page9_fixed(void);   //页面8固有模式			通讯地址设置
extern	void page9_change(void); //页面8数字变化部分

extern  void parameter_set0(void);  //
extern  void parameter_set1(void);  //
extern  void parameter_set2(void);  //
extern  void parameter_set3(void);  //
extern  void parameter_set4(void);  //
extern  void parameter_set5(void);  //
extern  void parameter_set6(void);  //
extern  void parameter_set7(void);  //
extern  void parameter_set8(void);  //
extern  void parameter_set9(void);  //
extern void send(void);

extern void data_analyse(void);
extern void data_485_analyse(void);
extern void RS485_Transmit(void);  
//extern void HEAT_CTRL(void);
#endif

