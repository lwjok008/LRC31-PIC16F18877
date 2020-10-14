#include "mcc.h"
#include "head.h"


//����8λ������
void data_out(uchar data)
{
	//8080 8bit interface
	CS0 = 0;
	DC0 = 1;
	RD = 1;
	LCD_DB=data;
	//nop;nop;nop;nop;nop;
	WR0 = 0;
	WR0 = 1;
	CS0 = 1;        
}

//��16λ���ݣ�16λ����һ��ֵ
void data_out_16(uint data_16bit)
{
	uchar hdata,ldata;
	hdata=(data_16bit>>8)&0X00FF;
	ldata=data_16bit&0X00FF;
	data_out(hdata);
	data_out(ldata);
}

//����8λ������
void comm_out(uchar com)
{
	//8080 8bit interface
	DC0 = 0;
	CS0 = 0;  
	RD = 1;
	LCD_DB=com;	//nop;nop;nop;nop;nop;
	WR0 = 0;
	WR0 = 1;
	CS0 = 1;
}


//��ʾ24x21����ĺ���
void disp_24x21(int x,int y,char *dp,int font_color,int back_color)
{
	int i,j;
	uchar dis_data;
	lcd_address(x,y,24,21);
	for(i=0;i<21;i++)		//�߶�21
	{
		for(j=0;j<3;j++)	//��� 3*8=24
		{
			dis_data=*dp;
			mono_data_out(dis_data,font_color,back_color);
			//mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}



//��ʾ16x21�����ַ������൱��16x21�����ͼ����ܰ��ʾ������ָ��*dp���ַ������ݣ�char *dp��
void disp_16x21(int x,int y,char *dp,int font_color,int back_color)
{
	int i,j;
	lcd_address(x,y,16,21);
	for(i=0;i<21;i++)		//�߶�21
	{
		for(j=0;j<2;j++)	//��� 2*8=16
		{
			mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}
void disp_ASCII_8x16(int x,int y, uchar number,int font_color,int back_color)
{
	int i,j,k;
	k=0;
	lcd_address(x,y,8,16);
	for(i=0;i<16;i++)		//�߶�16
	{
		for(j=0;j<1;j++)	//��� 8
		{
			mono_data_out(table_asc[number][k],font_color,back_color);
			k++;
		}
	}
}
void disp_24x24(int x,int y,char *dp,int font_color,int back_color)
{
	int i,j;
	lcd_address(x,y,24,24);
	for(i=0;i<24;i++)		//�߶�21
	{
		for(j=0;j<3;j++)	//��� 2*8=16
		{
			mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}
void disp_16x16(int x,int y,char *dp,int font_color,int back_color)
{
	int i,j;
	lcd_address(x,y,16,16);
	for(i=0;i<16;i++)		//�߶�21
	{
		for(j=0;j<2;j++)	//��� 2*8=16
		{
			mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}

//����ɫ��8λ�����ݣ�����8�����ص㣩ת���ɲ�ɫ�����ݴ����Һ����
void mono_data_out(uchar mono_data,uint font_color,uint back_color)
{
	uint k;
	for(k=0;k<8;k++)
	{
	 	if(mono_data&0x80)
		{
			data_out_16(font_color);	//��������1ʱ����ʾ������ɫ
		}
		else
		{
			data_out_16(back_color);	//��������0ʱ����ʾ��ɫ
		}

		mono_data<<=1;
	}
}

/*
//����ɫ��8λ�����ݵĸ�5λ������5�����ص㣩ת���ɲ�ɫ�����ݴ����Һ����
void mono_data_out_5x8(uchar mono_data,uint font_color,uint back_color)
{
	uint k;
	for(k=0;k<6;k++)				 	//��ʾ6�У���Ϊ5x8��������м�����Ǹ�1�У�����һ��
	{
	 	if(mono_data&0x80)
		{
			data_out_16(font_color);	//��������1ʱ����ʾ������ɫ
		}
		else
		{
			data_out_16(back_color);	//��������0ʱ����ʾ��ɫ
		}

		mono_data<<=1;
	}
}
*/

//���崰�����꣺��ʼ���꣨XS,YS)�Լ����ڴ�С��x_total,y_total)
void lcd_address(uint XS,uint YS,uint x_total,uint y_total)
{
	int XE,YE; 
	XE=XS+x_total-1;
	YE=YS+y_total-1;	
	comm_out(0x2a);		// ����X��ʼ�������ĵ�ַ
	data_out_16(XS);	// X��ʼ��ַ(16λ��
	data_out_16(XE);	// X������ַ(16λ��
			
	comm_out(0x2b);		// ����Y��ʼ�������ĵ�ַ
	data_out_16(YS);	// Y��ʼ��ַ(16λ��
	data_out_16(YE);	// Y������ַ(16λ��

	comm_out(0x2c);	    // д���ݿ�ʼ
}

//���嵥�����ص�����꣨x,y��
void LCD_SetPos(uint x,uint y)
{
	comm_out(0x2a);		// ����X��ʼ�������ĵ�ַ
	data_out_16(x);		// X��ʼ��ַ(16λ��
	data_out_16(x+1);	// X������ַ(16λ��

	comm_out(0x2b);		// ����Y��ʼ�������ĵ�ַ
	data_out_16(y);		// Y��ʼ��ַ(16λ��
	data_out_16(y+1);	// Y������ַ(16λ��

	comm_out(0x2c);	    // д���ݿ�ʼ
}



//��ʾȫ����һɫ��
void display_color(uint color)
{  
	int i,j;
	
	lcd_address(0,0,160,128);
	for(i=0;i<128;i++)
	{
		for(j=0;j<160;j++)
		{
			data_out_16(color);
		}
	}
	
	/*������ʾ
	lcd_address(0,0,128,160);
	for(i=0;i<160;i++)
	{
		for(j=0;j<128;j++)
		{
			data_out_16(color);
		}
	}
	*/
}

//������ʾ��һɫ��
void line_display_color(uchar y_start, uchar y_end, uint color)  //y_start--��ʼ��  y_end--������
{  
	int i,j;
	
	lcd_address(0,y_start,160,y_end);
	for(i=0;i<(y_end-y_start);i++)
	{
		for(j=0;j<160;j++)
		{
			data_out_16(color);
		}
	}
	
	/*������ʾ
	lcd_address(0,0,128,160);
	for(i=0;i<160;i++)
	{
		for(j=0;j<128;j++)
		{
			data_out_16(color);
		}
	}
	*/
}


void lcd_init(void)
{
	delay(20);
//	RST=0;				//�͵�ƽ����λ
//	delay(20);
//	RST=1;				//�ߵ�ƽ����λ����
//	delay(10);
	
	//��ʼ��ʼ����
    comm_out(0x11);      
    
    comm_out(0x26);
    data_out(0x04);	//����GAMMA����
    
   	comm_out(0x36);   //��ɨ��˳����ɨ��˳�򣬺��/���� 
    data_out(0xa8); 	//���ã�RAMд�뷽��������ҡ����ϵ��¡�����˳��BGR
                        
    comm_out(0xb1);   //����fr=61.7hz
    data_out(0x0e);
    data_out(0x14);
    //data_out(0x2d);
    
    comm_out(0x3a);    
    data_out(0x05);		//���ݸ�ʽ16bit
    
    comm_out(0x29);		//����ʾ
}
//���㺯��
void draw_point(uint x, uint y, uint color)
{
	LCD_SetPos(x,y);
	data_out_16(color);	
}

//----------------------------------------
// ���ߺ��� ���㷨��
//----------------------------------------
void vDraw_Line(uint x1,uint y1,uint x2,uint y2,uint Fg_Color)
// (x1,y1),(x2,y2)��ֱ����ʼ����ֹλ�����꣬�����ص�Ϊ��λ
{
  uint temp;
  int dalt_x,dalt_y,err=0;
  if (y1>y2)                  //Ҫ��Y1<Y2�����������Ҫ�����������û�
    {
    temp=x1;
    x1=x2;
    x2=temp;
    temp=y1;
    y1=y2;
    y2=temp;
    }
  draw_point(x1,y1,Fg_Color);             // ����ʼ��
  dalt_x=x2-x1;                //��X=X2-X1
  dalt_y=y2-y1;                //��Y=Y2-Y1
  if(dalt_x>=0)
     {
      if(dalt_y>dalt_x)        //k=��Y/��X >1ʱC
      
        {
         while(y1<y2)
         {
          if(err<0)
          {
           x1=x1+1;
           y1=y1+1;
           err=err+dalt_y-dalt_x;
           }
           else
           {
           y1=y1+1;
           err=err-dalt_x;
           }
          draw_point(x1,y1,Fg_Color);     // ����
         }
       }
     else                      //0<k=��Y/��X=<1
      {
       if (dalt_y==0)
          y1=y1-1;
       while(x1<x2)
         {
          if(err<0)
          {
           x1=x1+1;
           err=err+dalt_y;
           }
           else
           {
           y1=y1+1;
           x1=x1+1;
           err=err+dalt_y-dalt_x;
           }
          draw_point(x1,y1,Fg_Color);     //����
         }
     }
     
    }
  else
   {
   dalt_x=x1-x2;  
   if(dalt_y>dalt_x)          //k=��Y/��X<-1
     {
      while(y1<y2)
       {
        if(err<0)
         {
          x1=x1-1;
          y1=y1+1;
          err=err+dalt_y-dalt_x;
         }
        else
         {
          y1=y1+1;
          err=err-dalt_x;
         }
        draw_point(x1,y1,Fg_Color);      //����
      }
    }
   else                       //0>k=��Y/��X>=-1
    {
      if (dalt_y==0)
          y1=y1-1; 
    while(x1>x2)
      {
       if(err<0)
        {
         x1=x1-1;
         err=err+dalt_y;
        }
       else
        {
         x1=x1-1;
         y1=y1+1;
         err=err+dalt_y-dalt_x;
        }
       draw_point(x1,y1,Fg_Color);
      }
    } 
  }
     
}

//void show_pic()
//{
// int i,j,k;
// unsigned char picH,picL;
//
// //areaset();
//
// //for(n=0;n<4;n++)
//  { k=0;
//   for(i=0;i<128;i++)
//   for(j=0;j<160;j++)
//    {
//     picH=picture1[k];
//     k++;
//     picL=picture1[k];
//     k++;
//       LCD_DataWrite(picH,picL);
//     }
//   }
//
//
// }  