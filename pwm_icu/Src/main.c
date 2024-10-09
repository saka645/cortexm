#include <stm32f0xx.h>
#include <stdio.h>
#include <uart1.h>
#include "tim.h"

static void uart_callback();

int timestamp[100];int cnt=0;
int main()
{

	tim3_pc8_output_compare_init();
	tim1_a8_input_compare_init();
	printf("hello please enter A\n");
	while(1)
	{
		while(!(TIM1->SR & TIM1_SR));//WAIT TILL CAPTURE HAPPENS
		TIM1->SR &= ~TIM1_SR;
		timestamp[cnt++] = TIM1->CNT;
		if(cnt>99) cnt=0;

#if 0
		//read_char = uart1_read();
		while(!(TIM3->SR & TIM3_SR));
		/*clear uif*/
		TIM3->SR &= ~(TIM3_SR);
		read_char++;
#endif

	}
}

