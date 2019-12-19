/***************????(??)????**********************/
/*文件功能：main函数
/*作者:田世通
/*创建日期:2019-12-13
/*
/*最后修改日期:
/***********************************************************/



#include "STC15.h"
#include "uart.h"
#include "system.h"
#include "stdio.h"

void main(void)
{
		int  a=12;
    T2_init();
    uart1_init();
    uart2_init();
	//	char  asdf;
	
    while(1)
    {

#ifdef __debug
			if(P55==1)
			{P55=0;}
			else
			{P55=1;}
		//	printf("asdfasdf");
#endif
    delayms(50);
    }
}
