/***************力邦测控（洛阳）有限公司**********************/
/*文件功能：SPI&ADC
/*作者：田世通
/*创建日期日期：2019-12-17
/*
/*最后修改日期：
/***********************************************************/
#include "adc.h"
#ifdef __debug
#include "stdio.h"
#endif
#define SPIF        0x80
#define WCOL        0x40
void spi_init(void)
{
    SPDAT = 0;
    SPCTL = 0xd9;//0101_1001
    SPSTAT =SPIF | WCOL ; 
}
void spi_test(void)
{
    unsigned int temp=0;
    P12=0;
	SPDAT=ADVOID;
    while(!(SPSTAT&SPIF));
    SPSTAT =SPIF | WCOL ; 
    temp=SPDAT;
    SPDAT = ADVOID; 
    while(!(SPSTAT&SPIF));
    SPSTAT =SPIF | WCOL ; 
    temp <<=8;
    temp +=SPDAT;
    printf("data is %x\r\n",temp);
    P12=1;
}