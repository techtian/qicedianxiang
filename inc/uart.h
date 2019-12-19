/***************力邦测控（洛阳）有限公司**********************/
/*文件功能：串口函数
/*作者：田世通
/*创建日期日期：2019-12-13
/*
/*最后修改日期：
/***********************************************************/
#ifndef __uart_h__
#define __uart_h__
#ifdef __debug 
#include "stdio.h"
#endif
#include "system.h"
#define BAUD        115200
#define T2VALUE     (65536-(FOSC/BAUD/4))
#define PS2L1           0x01
#define S2IEENABLE      0X01

extern unsigned char reveive_buff[30];
extern unsigned char send_buff[30];
extern unsigned char receive_count;

void T2_init(void);
void uart1_init(void);
void uart2_init(void);
void uart3_intt(void);
void uart4_init(void);
void s1putc( char );
void s1puts( char *);
void mputc(char);
void mputs( char *,unsigned char );
void Uart2() ;
#ifdef __debug
char putchar(char );
#endif


#endif