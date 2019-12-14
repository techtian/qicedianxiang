#include "system.h"
void IO_init(void)
{
    P0M0 = 0X00;    P0M1 = 0X00;
    P1M0 = 0X00;    P1M1 = 0X00;
    P2M0 = 0X00;    P2M1 = 0X00;
    P3M0 = 0X00;    P3M1 = 0X00;
    P4M0 = 0X00;    P4M1 = 0X00;
    P5M0 = 0X00;    P5M1 = 0X00;
}

void delayms(unsigned int m)
    {
        int a, b;
        for(a=0;a<5000;a++)
        for(b=0;b<m;b++);
	}