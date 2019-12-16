/***************力邦测控（洛阳）有限公司**********************/
/*文件功能：串口函数
/*作者：田世通
/*创建日期日期：2019-12-13
/*
/*最后修改日期：
/***********************************************************/
#ifndef __uart_h__
#define __uart_h__


#define FOSC 18432000
#define BAUD 115200
#define T2VALUE (65536-(FOSC/BAUD/4))

void T2_init(void);
void uart1_init(void);
void uart2_init(void);
void uart3_intt(void);
void uart4_init(void);
void putc(unsigned char );
void puts(unsigned char *);
void mputc(unsigned char);
void mputs(unsigned char *);
#endif