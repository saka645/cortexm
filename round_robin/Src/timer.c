/*
 * timer.c
 *
 *  Created on: 06-Oct-2024
 *      Author: saka6
 */


#include <timer.h>

volatile uint32_t g_cur_tick =0, tick_freq = 1,g_cur_tick_p=0;



void systick_init(uint32_t tick)
{
	uint32_t *pSRVR = (uint32_t *)SYSTICK_RELOAD_REG;
	uint32_t *pCTR = (uint32_t *)0xE000E010;
	uint32_t count = HSI_FREQ/tick;
	/*clear rvr*/
	*pSRVR &= ~(0x00FFFFFF);
	//LOAD THE VALUE//
	*pSRVR = count-1;
	/*enable counter*/
	*pCTR |= 0x07;
	__enable_irq();

}


void tick_increment()
{
	g_cur_tick += tick_freq;
}

uint32_t get_tick()
{
	__disable_irq();
	g_cur_tick_p = g_cur_tick;
	__enable_irq();
	return g_cur_tick_p;
}

void delay(uint32_t del)
{
	uint32_t tick_start = get_tick();
	uint32_t wait = del;
	if(wait < MAX_DELAY)
	{
		wait += tick_freq;
	}
	while((get_tick()-tick_start)<wait);
}
