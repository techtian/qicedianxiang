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
void main(void)
{
    T2_init();
    //uart1_init();
    uart2_init();
    while(1)
    {
        mputc(0x76);
    //    puts("asdfasdf");
#ifdef __debug
			if(P55==1)
			{P55=0;}
			else
			{P55=1;}
        delayms(50);
#endif
    }
}
