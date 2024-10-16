/*
 * kernel.c
 *
 *  Created on: 09-Oct-2024
 *      Author: saka6
 */
#include "kernel.h"
#include "timer.h"

/*xpsr
 * PC
 * LR
 * R12
 * R3
 * R2
 * R1
 * R0(TOP) GETS AUTOMATICALLY SAVED
 */
#define NUM_OF_THREADS	3
#define STACK_SIZE		100
#define SYSCLK			8000000U



uint32_t ms_prescalar = 0;

struct tcb{
	int32_t *stackPt;
	struct tcb *nextPt;
};

typedef struct tcb tcbType;
tcbType tcbs[NUM_OF_THREADS];
tcbType *currentPt;

int32_t TCB_STACK[NUM_OF_THREADS][STACK_SIZE];

void osKernelStackInit(int i)
{
	tcbs[i].stackPt = &TCB_STACK[i][STACK_SIZE - 16];//sp

	TCB_STACK[i][STACK_SIZE - 1] = (1U<<21); //psr = thumb mode

	TCB_STACK[i][STACK_SIZE - 3] = 0XAAAAAAAA;//R14, LR
	TCB_STACK[i][STACK_SIZE - 4] = 0XAAAAAAAA;//R12
	TCB_STACK[i][STACK_SIZE - 5] = 0XAAAAAAAA;//R3
	TCB_STACK[i][STACK_SIZE - 6] = 0XAAAAAAAA;//R2
	TCB_STACK[i][STACK_SIZE - 7] = 0XAAAAAAAA;//R1
	TCB_STACK[i][STACK_SIZE - 8] = 0XAAAAAAAA;//R0

	TCB_STACK[i][STACK_SIZE - 9] = 0XAAAAAAAA;//R11
	TCB_STACK[i][STACK_SIZE - 10] = 0XAAAAAAAA;//R10
	TCB_STACK[i][STACK_SIZE - 11] = 0XAAAAAAAA;//R9
	TCB_STACK[i][STACK_SIZE - 12] = 0XAAAAAAAA;//R8
	TCB_STACK[i][STACK_SIZE - 13] = 0XAAAAAAAA;//R7
	TCB_STACK[i][STACK_SIZE - 14] = 0XAAAAAAAA;//R6
	TCB_STACK[i][STACK_SIZE - 15] = 0XAAAAAAAA;//R5
	TCB_STACK[i][STACK_SIZE - 16] = 0XAAAAAAAA;//R4

}

uint8_t osKernelAddThreads(void(*task0),void(*task1),void(*task2))
{
	__disable_irq();
	tcbs[0].nextPt = &tcbs[1];
	tcbs[1].nextPt = &tcbs[2];
	tcbs[2].nextPt = &tcbs[0];

	osKernelStackInit(0);
	TCB_STACK[0][STACK_SIZE - 2] = (int32_t)(task0);//init pc

	osKernelStackInit(1);
	TCB_STACK[1][STACK_SIZE - 2] = (int32_t)(task1);//init pc

	osKernelStackInit(2);
	TCB_STACK[2][STACK_SIZE - 2] = (int32_t)(task2);//init pc

	currentPt = &tcbs[0];//start from thread 0
}

void osKernelInit()
{
	 ms_prescalar = SYSCLK/1000;
}

void osKernelLaunch(uint32_t quanta)
{
	uint32_t *pSRVR = (uint32_t *)SYSTICK_RELOAD_REG;
	uint32_t *pCTR = (uint32_t *)0xE000E010;
	uint32_t count = quanta*ms_prescalar;
	/*clear rvr*/
	*pSRVR &= ~(0x00FFFFFF);
	//LOAD THE VALUE//
	*pSRVR = count-1;
	//priority//
	NVIC_SetPriority(SysTick_IRQn,15);
	/*enable counter*/
	*pCTR |= 0x07;

	osSchedulerLaunch();
}


void SysTick_Handler(void)
{
	__asm("CPSID I");
	__asm("PUSH {R4-R11}"):
	__asm("LDR R0 =currentPt");
	__asm("LDR R1,[R0]");
	__asm("STR SP,[R1]");

	//CHOOSE NEXT THREAD//
	__asm("LDR R1,[R1,#4]");//r1=curpt->next
	__asm("STR R1,[R0]");
	__asm("LDR SP,[R1]");
	__asm("POP {R4-R11}");
	__asm("CPSIE I");
	__asm("BX LR");


}
