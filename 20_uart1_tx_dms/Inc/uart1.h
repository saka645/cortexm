/*
 * uart1.h
 *
 *  Created on: Jan 26, 2024
 *      Author: sanjay.kumar
 */

#ifndef UART1_H_
#define UART1_H_

#include <stm32f0xx.h>
#define SR_RXNE			(1U<<5)

void set_baudrate(USART_TypeDef *USARTTX, uint32_t PeriphClk, uint32_t BaudRate);
uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);
void uart1_write(uint8_t ch);
void uart1_tx_init();
char uart1_read(void);
void uart1_rx_interrupt_init();
#endif /* UART1_H_ */
