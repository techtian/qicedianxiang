#include "uart.h"
#include "stc15.h"
void T2_init(void)
{
    AUXR    =0x15; //00010101
    T2L     =T2VALUE;
    T2H     =T2VALUE>>8;
}

void uart1_init(void)
{
    SCON    =0X50;//0101_0000
   // PCON    =0;//0000_0000
}
//BBB DD DD 19
#define TI2     0x02
#define RI2     0x01
void uart2_init(void)
{
    S2CON   =0X50;//S2SM0 =0;S2REN=1;模式0
}
void uart3_init(void)
{
    S3CON   =0X10;//0001_0000
}
void uart4_init(void)
{
    S4CON   =0X10;//0001_0000
}
void putc(unsigned char c)
{
    SBUF=c;
    while (~TI);
    TI = 0;
}
void puts(unsigned char *s)
{
    while(*s)
    {
        putc(*s++);
    }

}
void mputc(unsigned char c)
{
    S2BUF=c;
    while (!(S2CON&TI2));
    S2CON&=~TI2; 
}
// #ifdef __debug
// char *sbuf[10];
// void ctos(char c)
// {
//     char *tep[10];
//     char mod;
//     while(c)
//     {
//         mod =c%10;
//         c   =c/10;
//     }
// }
// #endif