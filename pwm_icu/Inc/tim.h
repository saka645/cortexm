/*
 * tim.h
 *
 *  Created on: Sep 22, 2024
 *      Author: saka6
 */

#ifndef TIM_H_
#define TIM_H_

#include <stm32f0xx.h>

#define TIM3_SR  (1<<0U)
#define TIM1_SR (1<<1U)
void tim3_1hz_init();


void tim3_pc8_output_compare_init();

void tim1_a8_input_compare_init();
#endif /* TIM_H_ */
