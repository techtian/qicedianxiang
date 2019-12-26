/***************力邦测控（洛阳）有限公司**********************/
/*文件功能：串口函数
/*作者：田世通
/*创建日期日期：2019-12-13
/*
/*最后修改日期：
/***********************************************************/
#include "uart.h"
#ifdef __debug
#include "stdio.h"
#endif
unsigned char receive_buff[30];
unsigned char send_buff[30];
unsigned char receive_count=0 ;
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
#define S2TI     0x02
#define S2RI     0x01
void uart2_init(void)//modbus 
{
    S2CON   =0X50;//S2SM0 =0;S2REN=1;模式0
  
    IE2 |= S2IEENABLE;
    IP2 |= PS2L1;
    EA=1;
}
void uart3_init(void)
{
    S3CON   =0X10;//0001_0000
}
void uart4_init(void)
{
    S4CON   =0X10;//0001_0000
}
void s1putc( char c)
{
    SBUF=c;
    while (~TI);
    TI = 0;
}
void s1puts( char *s)
{
    while(*s)
    {
        s1putc(*s++);
    }
}
void mputc(char c)
{
    S2BUF=c;
    while (!(S2CON&S2TI));
    S2CON&=~S2TI; 
}
void mputs(char *s,unsigned char len)
{
    int i = 0;
    for(i;i<len;i++)
    {
        mputc(s[i]);
    } 
}
void Uart2() interrupt 8 using 1
{
    char a;
    if (S2CON&S2RI)
    {
        S2CON &=~S2RI;
        a=S2BUF ;
        receive_buff[receive_count]=a;
        receive_count++;
        if (receive_count==8)
        {
            mputs(send_buff,MODBUSBYTESIZE);
#ifdef __debug 
            //s1puts(receive_buff);
            //send_buff[30]={0x17,0x03,0x02,0x12,0x12,0x7d,0x2a};
            //send_buff[0]=0x17;send_buff[1]=0x03;send_buff[2]=0x02;send_buff[3]=0x12;send_buff[4]=0x12;send_buff[5]=0x7d;send_buff[6]=0x2a;
            //mputs(send_buff,7);
#endif
            receive_count=0;
        }
        
	    s1putc(a);
       // printf("%x",a);
    }
}
#ifdef __debug
char putchar(char c)
{
    s1putc(c);
    return c;
}
#endif
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