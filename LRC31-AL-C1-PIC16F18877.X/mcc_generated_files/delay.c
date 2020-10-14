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

void delayus(uint x)		//16M晶振 延时时间计算公式=x * 3μs+4.25μs  
{
	uint a;
	for(a=x;a>0;a--)
	{	
		clrwdt;		
	}	
}

void delayus1(uint x,uchar y)  //延时x微秒
{
	uint a;
	uchar b;
	for(a=x;a>0;a--);
	for(b=y;b>0;b--);
}



