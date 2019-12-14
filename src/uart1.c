#include "uart1.h"
#include "stc15.h"
void uart1_init(void)
{
    S2CON=0X50;//S2SM0 =0;S2REN=1;模式0
    AUXR=0X14;//TR2=1;T2_C/T=0;T2x12=1;
    T2L=T2VALUE;
    T2H=T2VALUE>>8;

}
