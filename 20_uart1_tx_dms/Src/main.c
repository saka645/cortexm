#include <stm32f0xx.h>
#include <stdio.h>
#include <uart1.h>

static void uart_callback();

char read_char=0;
int main()
{
	uart1_rx_interrupt_init();
	printf("hello please enter A\n");
	while(1)
	{
		//read_char = uart1_read();

	}
}
static void uart_callback()
{
	read_char = USART1->RDR;
	if(read_char=='A')
		printf("you pressed A\n");
}
void USART1_IRQHandler(void)
{
	//check interrupt flag
	if(USART1->ISR & SR_RXNE)
	{
		uart_callback();
	}
}
