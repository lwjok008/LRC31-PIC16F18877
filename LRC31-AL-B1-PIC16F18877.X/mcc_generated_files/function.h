#ifndef __FUNCTION_H
#define __FUNCTION_H
#include "hal.h"

extern void get_t1(void);

extern void reset_temp1(void);

extern void write_t1(uchar val);

extern  uchar read_t1(void);

extern  void delayus1(uint x,uchar y);  //��ʱx΢��

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
extern	void lcd_address(uint XS,uint YS,uint x_total,uint y_total);		//���ô�������
extern	void LCD_SetPos(uint x,uint y);		//�������ص�����
extern	void display_color(uint color);		//��ʾȫ����һ��ɫ
extern	void display_image(uchar *dp);		//��ʾһ��ȫ����ͼ
extern  void line_display_color(uchar y_start, uchar y_end, uint color);  //��ʾ���е�һ��ɫ
extern	void mono_data_out(uchar mono_data,uint font_color,uint back_color); //����ɫ��8λ�����ݣ�����8�����ص㣩ת���ɲ�ɫ�����ݴ����Һ����
extern	void mono_data_out_5x8(uchar mono_data,uint font_color,uint back_color);	//����ɫ��8λ�����ݵĸ�5λ������5�����ص㣩ת���ɲ�ɫ�����ݴ����Һ����
extern	void disp_24x21(int x,int y,char *dp,int font_color,int back_color);
extern	void disp_16x21(int x,int y,char *dp,int font_color,int back_color);       //��ʾ16*21�ַ�
extern	void disp_num_16x21(int x,int y, uchar number,int font_color,int back_color);		//��ʾ����
extern	void disp_num_24x48(int x,int y, uchar number,int font_color,int back_color);
extern	void disp_16x16(int x,int y,char *dp,int font_color,int back_color);
extern	void disp_ASCII_8x16(int x,int y, uchar number,int font_color,int back_color);
extern	void disp_24x24(int x,int y,char *dp,int font_color,int back_color);
extern  void draw_point(uint x, uint y, uint color);
extern  void vDraw_Line(uint x1,uint y1,uint x2,uint y2,uint Fg_Color);
extern  void page0_fixed(void);   //ҳ��0����ģʽ			ʵʱ����
extern	void page0_change(void); //ҳ��0���ֱ仯����

extern  void page1_fixed(void);   //ҳ��1����ģʽ         ʵʱ�¶�
extern	void page1_change(void); //ҳ��1���ֱ仯����

extern  void page2_fixed(void);   //ҳ��2����ģʽ			ʵʱ��ѹ����أ�
extern	void page2_change(void); //ҳ��2���ֱ仯����

extern  void page3_fixed(void);   //ҳ��3����ģʽ			���趨��������·�������ӵص����������¶�
extern	void page3_change(void); //ҳ��3���ֱ仯����

extern  void page4_fixed(void);   //ҳ��4����ģʽ			��������
extern	void page4_change(void); //ҳ��4���ֱ仯����


extern  void page5_fixed(void);   //ҳ��5����ģʽ			��·��������
extern	void page5_change(void); //ҳ��5���ֱ仯����

extern  void page6_fixed(void);   //ҳ��6����ģʽ			�ӵص�������
extern	void page6_change(void); //ҳ��6���ֱ仯����

extern  void page7_fixed(void);   //ҳ��7����ģʽ			�����¶�����
extern	void page7_change(void); //ҳ��7���ֱ仯����

extern  void page8_fixed(void);   //ҳ��8����ģʽ			ͨѶ��ַ����
extern	void page8_change(void); //ҳ��8���ֱ仯����

extern  void page9_fixed(void);   //ҳ��8����ģʽ			ͨѶ��ַ����
extern	void page9_change(void); //ҳ��8���ֱ仯����

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

