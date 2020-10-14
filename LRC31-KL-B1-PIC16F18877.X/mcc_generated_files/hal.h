#ifndef	_HAL_H_
#define	_HAL_H_


/*Һ����������غ궨������*/
#define	CS0	 	LCD_CS_LAT		//Ƭѡ �͵�ƽ��Ч
#define	DC0		LCD_DC_LAT		//���ݣ�Ϊ1ʱ����   Ϊ0ʱָ��
#define	WR0		LCD_WR_LAT		//��д��Ϊ1ʱ������  Ϊ0ʱд����
#define	RD		LCD_RD_LAT		//ʹ���ź�
#define	RST		LATDbits.LATD5
#define	LCD_DB	LATB
#define BACK_LIGHT_CONTROL	LCD_BACK_LIGHT_LAT		//����������

#define red    0xf800		//�����ɫ
#define blue   0x001f		//������ɫ
#define green  0x07e0 	//������ɫ				
#define white  0xffff 		//�����ɫ	
#define black  0x0000 	//�����ɫ	
#define orange 0xfc08 	//�����ɫ
#define yellow 0xffe0		//�����ɫ
#define pink   0xf3f3 	//����ۺ�ɫ
#define purple 0xa1d6	 	//������ɫ
#define brown  0x8200	 //������ɫ
#define gray   0x8410	 	//�����ɫ

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


#define	T1			RF2				//T2�¶ȴ��������������
#define	T1_HIGH()	TRISF2=1
#define	T1_LOW()	TRISF2=0;LATF2=0

#endif






















