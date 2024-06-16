/*
 * main.h
 *
 *  Created on: 01-May-2024
 *      Author: saka6
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS					4

#define SIZE_TASK_STACK  			1024U
#define SIZE_SCHED_STACK  			1024U

#define SRAM_START  				0x20000000U
#define SIZE_SRAM					(8*1024U)
#define SRAM_END					(SRAM_START+SIZE_SRAM)
#define T1_STACK_START				SRAM_END
#define T2_STACK_START				(SRAM_END-SIZE_TASK_STACK)
#define T3_STACK_START				((SRAM_END)-(2*SIZE_TASK_STACK))
#define T4_STACK_START				((SRAM_END)-(3*SIZE_TASK_STACK))
#define SCHED_STACK_START			((SRAM_END)-(4*SIZE_TASK_STACK))

#define TICK_HZ						1000U
#define HSI_FREQ					8000000U//8MHZ
#define SYSTICK_FREQ				HSI_FREQ
#define SYSTICK_RELOAD_REG			0xE000E014U
#define DUMMY_XPSR					0x01000000U


#endif /* MAIN_H_ */
