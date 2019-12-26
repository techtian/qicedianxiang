/***************力邦测控（洛阳）有限公司**********************/
/*文件功能：头文件——SPI&ADC
/*作者：田世通
/*创建日期日期：2019-12-17
/*
/*最后修改日期：
/***********************************************************/
#ifndef __adc_h__
#define __adc_h__
#ifdef __debug 
#include "stdio.h"
#endif
#include "system.h"

#define ADIN1       0x00
#define ADIN2       0x08
#define ADIN3       0x10
#define ADIN4       0x18
#define ADVOID      0x81
void spi_init(void);
void spi_test(void);


#endif