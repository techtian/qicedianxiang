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
    SPCTL;//010?_1001
    SPSTAT =SPIF | WCOL ; 
    SPDAT = 0;
    AUXR1;


}