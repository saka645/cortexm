/*
 * uart1.c
 *
 *  Created on: Jan 26, 2024
 *      Author: sanjay.kumar
 */

#include <uart1.h>

#define UART1EN			(1U<<14)
#define UART2EN			(1U<<17)
#define GPIOAEN			(1U<<17)
#define GPIOBEN			(1U<<18)
#define SYS_FREQ		8000000U//16000000
#define APB1_CLK		SYS_FREQ
#define UART_BAUDRATE	9600U
#define CR1_TE			(1U<<3)
#define CR1_RE			(1U<<2)
#define UART_EN			(1U<<0)
#define SR_TXE			(1U<<7)


#define CR1_RXNEIE		(1U<<5)
#define CR1_UE			(1U<<0)

#define DMA_EN			(1U<<0)
#define DMA_CH_CONFIG	(1U<<0)
#define DMA_CH_2_SEL	(1U<<5)
#define DMA_CH_2_MINC	(1U<<7)
#define DMA_CH_DIR		(1U<<4)

int __io_putchar(int ch)
{
	uart1_write(ch);
	return ch;
}

void uart1_rx_interrupt_init()
{
	//enable clock to gpio//
	RCC->AHBENR |= GPIOBEN;
	//alternate fun mode//pb6 tx
	GPIOB->MODER &= ~(1U<<12);
	GPIOB->MODER |= (1U<<13);
	//alternate fun mode//pb7 rx
	GPIOB->MODER &= ~(1U<<14);
	GPIOB->MODER |= (1U<<15);
	//pb6 to alternate fun tx, af0
	GPIOB->AFR[0] &= ~(1<<24);
	GPIOB->AFR[0] &= ~(1<<25);
	GPIOB->AFR[0] &= ~(1<<26);
	GPIOB->AFR[0] &= ~(1<<27);
	//pb7 to alternate fun rx, af0
	GPIOB->AFR[0] &= ~(1<<28);
	GPIOB->AFR[0] &= ~(1<<29);
	GPIOB->AFR[0] &= ~(1<<30);
	GPIOB->AFR[0] &= ~(1<<31);
	//enable clock to uart1//
	RCC->APB2ENR |= UART1EN;
	//baud rate//
	set_baudrate(USART1, APB1_CLK, UART_BAUDRATE);
	//USART1->BRR = 80000/96;
	//program stop bits//
	//USART1->CR2 = 0x00;
	//configure transmit direction//
	USART1->CR1 = (CR1_TE|CR1_RE|UART_EN);
	//enable uart RX interrupt//
	USART1->CR1 |= CR1_RXNEIE;
	//enable nvic
	NVIC_EnableIRQ(USART1_IRQn);
	//enable uart
	USART1->CR1 |= CR1_UE;
}

void uart1_tx_init()
{
	//enable clock to gpio//
	RCC->AHBENR |= GPIOBEN;
	//alternate fun mode//pb6 tx
	GPIOB->MODER &= ~(1U<<12);
	GPIOB->MODER |= (1U<<13);
	//alternate fun mode//pb7 rx
	GPIOB->MODER &= ~(1U<<14);
	GPIOB->MODER |= (1U<<15);
	//pb6 to alternate fun tx, af0
	GPIOB->AFR[0] &= ~(1<<24);
	GPIOB->AFR[0] &= ~(1<<25);
	GPIOB->AFR[0] &= ~(1<<26);
	GPIOB->AFR[0] &= ~(1<<27);
	//pb7 to alternate fun rx, af0
	GPIOB->AFR[0] &= ~(1<<28);
	GPIOB->AFR[0] &= ~(1<<29);
	GPIOB->AFR[0] &= ~(1<<30);
	GPIOB->AFR[0] &= ~(1<<31);
	//enable clock to uart1//
	RCC->APB2ENR |= UART1EN;
	//baud rate//
	set_baudrate(USART1, APB1_CLK, UART_BAUDRATE);
	//USART1->BRR = 80000/96;
	//program stop bits//
	//USART1->CR2 = 0x00;
	//configure transmit direction//
	USART1->CR1 = (CR1_TE|CR1_RE|UART_EN);
	//enable uart module//
}
void set_baudrate(USART_TypeDef *USARTTX, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTTX->BRR = compute_uart_div(PeriphClk, BaudRate);//0x340//1a1
}

uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

void uart1_write(uint8_t ch)
{

	//make sure transmit data reg is empty//
	//write transmit data to reg//
	while(!(USART1->ISR & SR_TXE));
	USART1->TDR = (ch&0xff);


}
char uart1_read(void)
{
	while(!(USART1->ISR & SR_RXNE));
	return USART1->RDR;
}

void dma_init(uint32_t src, uint32_t dest, uint32_t len)
{
	/*enable clock access to dma */
	RCC->AHBENR |= DMA_EN;
	/*disable dma */
	DMA1_Channel2->CCR &= ~DMA_CH_CONFIG;
	/*clear all interrupt flags of dms*/
	DMA1->IFCR |= (1U<<4);
	DMA1->IFCR |= (1U<<5);
	DMA1->IFCR |= (1U<<6);
	DMA1->IFCR |= (1U<<7);
	/*set destination buffer*/
	DMA1_Channel2->CPAR = dest;
	/*set source buffer*/
	DMA1_Channel2->CMAR = src;
	/*set length*/
	DMA1_Channel2->CNDTR = len;
	/*select channel of dma*/
	DMA1_Channel2->CNDTR = DMA_CH_2_SEL;
	/*enable memory increment*/
	DMA1_Channel2->CCR |= DMA_CH_2_MINC;
	/*configre transfer directior-mem(array) to peripheral(uart)*/
	DMA1_Channel2->CCR |= DMA_CH_DIR;
	/*ENABLE transfer complete interrupt*/
	/*disable fifo mode*/
	/*enable direct mode*/
	/*enable dma*/
	/*enable uart1 transmit dma*/
	/*enable dma interrupt in nvic*/

}
