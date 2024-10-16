/*
 * timer.h
 *
 *  Created on: 06-Oct-2024
 *      Author: saka6
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include <cmsis_gcc.h>

#define TICK_HZ						1000U
#define HSI_FREQ					8000000U//8MHZ
#define SYSTICK_FREQ				HSI_FREQ
#define SYSTICK_RELOAD_REG			0xE000E014U
#define DUMMY_XPSR					0x01000000U
#define MAX_DELAY					0xFFFFFFFF

void delay(uint32_t del);
uint32_t get_tick();
void tick_increment();

void systick_init(uint32_t tick);

#endif /* TIMER_H_ */
