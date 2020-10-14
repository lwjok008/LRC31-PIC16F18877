#ifndef	_HAL_H_
#define	_HAL_H_


/*液晶屏驱动相关宏定义内容*/
#define	CS0	 	LCD_CS_LAT		//片选 低电平有效
#define	DC0		LCD_DC_LAT		//数据，为1时数据   为0时指令
#define	WR0		LCD_WR_LAT		//读写，为1时读数据  为0时写数据
#define	RD		LCD_RD_LAT		//使能信号
#define	RST		LATDbits.LATD5
#define	LCD_DB	LATB
#define BACK_LIGHT_CONTROL	LCD_BACK_LIGHT_LAT		//背光驱动打开

#define red    0xf800		//定义红色
#define blue   0x001f		//定义蓝色
#define green  0x07e0 	//定义绿色				
#define white  0xffff 		//定义白色	
#define black  0x0000 	//定义黑色	
#define orange 0xfc08 	//定义橙色
#define yellow 0xffe0		//定义黄色
#define pink   0xf3f3 	//定义粉红色
#define purple 0xa1d6	 	//定义紫色
#define brown  0x8200	 //定义棕色
#define gray   0x8410	 	//定义灰色

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#define RELAY_HEATER1	RE1
#define RELAY_HEATER2	RE0
#define RELAY_HEATER3	RG0
#define RELAY_ALARM		RG2
//#define RELAY_BLOWER		RG4

#define KEY_UP		RB0
#define KEY_DOWN	RB1
#define KEY_ENTER	RB2
#define KEY_RETURN	RB3
#define KEY_RESET	RB4


#define	T1			RF2				//T2温度传感器数据输入口
#define	T1_HIGH()	TRISF2=1
#define	T1_LOW()	TRISF2=0;LATF2=0

#endif






















