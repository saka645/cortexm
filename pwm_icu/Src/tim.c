/*
 * tim.c
 *
 *  Created on: Sep 22, 2024
 *      Author: saka6
 */

#include "tim.h"

#include "stm32f0xx.h"

#define 	TIM3_EN    	(1<<1U)
#define 	TIM1_EN    	(1<<11U)
#define 	TIM3_CNT_EN (1<<0U)
#define 	OC_TOGGLE   (1<<4U) | (1<<5U)
#define 	TIM3_CH3_OE (1<<8u)
#define 	TIM1_CCMR	(1<<0U)
#define 	TIM1_RISING	(1<<0U)

#define		GPIOC_EN    (1<<19U)

#define		GPIOA_EN    (1<<17U)

void tim3_1hz_init()
{

	/*enable clock*/
	RCC->APB1ENR |= TIM3_EN;
	/*set prescalar*/
	TIM3->PSC = 4800-1;//48000000/4800 = 10000
	/*set auto reload*/
	TIM3->ARR = 1000 -1; // 10000/10000 = 1HZ
	/*clear timer counter*/
	TIM3->CNT = 0;
	/*enable the timer*/
	TIM3->CR1 |= TIM3_CNT_EN;
}


void tim3_pc8_output_compare_init()
{
	/*enable clock access for gpio c*/
	RCC->AHBENR |= GPIOC_EN;
	/*set pc8 to alternate function mode*/
	GPIOC->MODER &= ~(1<<16);
	GPIOC->MODER |= (1<<17);
	/*set pc8 alternate function to tim3 ch3*/
	GPIOC->AFR[1] &= ~(1<<0);
	GPIOC->AFR[1] &= ~(1<<1);
	GPIOC->AFR[1] &= ~(1<<2);
	/*enable clock*/
	RCC->APB1ENR |= TIM3_EN;
	/*set prescalar*/
	TIM3->PSC = 4800-1;//48000000/4800 = 10000
	/*set auto reload*/
	TIM3->ARR = 1000 -1; // 10000/10000 = 1HZ
	/*set output compare toggle mode*/
	TIM3->CCMR2 = OC_TOGGLE;
	//ena ble tim3 ch3 in compare mode//
	TIM3->CCER |= TIM3_CH3_OE;
	/*clear timer counter*/
	TIM3->CNT = 0;
	/*enable the timer*/
	TIM3->CR1 |= TIM3_CNT_EN;

}


void tim1_a8_input_compare_init()//tim1ch1
{
	//enable clock to gpio a//
	RCC->AHBENR |= GPIOA_EN;
	//pa8 to alternate fun//
	GPIOA->MODER &= ~(1<<16);
	GPIOA->MODER |= (1<<17);
	//pa8 to tim1 ch1//
	GPIOA->AFR[1] &= ~(1<<0);
	GPIOA->AFR[1] |= (1<<1);
	GPIOA->AFR[1] &= ~(1<<2);
	//enable clock access to tim1//
	RCC->APB2ENR |= TIM1_EN;
	//set prescalar//
	TIM1->PSC = 4800-1;
	//set ch1 to capture at every edge//
	TIM1->CCMR1 |= TIM1_CCMR;
	//enabel ch1 to capture at rising edge//
	TIM1->CCER |= TIM1_RISING;
	//enable timer1//
	TIM1->CR1 |= TIM3_CNT_EN;
}
