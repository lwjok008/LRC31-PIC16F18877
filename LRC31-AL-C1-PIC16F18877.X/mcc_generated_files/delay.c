#include"head.h"

void  delay(uint x)
{
	uint a,b;
	for(a=x;a>0;a--)
	{
		for(b=260;b>0;b--)
		{
			clrwdt;
		}
	}
}

void delayus(uint x)		//16M���� ��ʱʱ����㹫ʽ=x * 3��s+4.25��s  
{
	uint a;
	for(a=x;a>0;a--)
	{	
		clrwdt;		
	}	
}

void delayus1(uint x,uchar y)  //��ʱx΢��
{
	uint a;
	uchar b;
	for(a=x;a>0;a--);
	for(b=y;b>0;b--);
}



