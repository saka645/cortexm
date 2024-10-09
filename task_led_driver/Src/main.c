#include <stm32f0xx.h>
#include <stdio.h>
#include <uart1.h>
#include <timer.h>


extern void initialise_monitor_handles(void);
uint16_t ms_cnt=0,sec_cnt=0;
void motor_run();
void motor_stop();
void valve_open();
void valve_close();


void motor_main()
{
	while(1)
	{
		motor_run();
		delay(1);
		motor_stop();
		delay(1);
	}
}

void valve_main()
{
	while(1)
	{
		valve_open();
		delay(1);
		valve_close();
		delay(1);
	}
}

int main()
{
	uint32_t volatile flag=0;
	initialise_monitor_handles();
	systick_init(TICK_HZ);
	printf("hello please enter A\n");

	if(flag)
	{
		motor_main();
	}
	else
	{
		valve_main();
	}

	while(1)
	{


	}
}
void SysTick_Handler(void)
{
	if(ms_cnt++ >= 1000)
	{
		ms_cnt=0;
		tick_increment();
	}

}

void motor_run()
{
	printf("motor running\n");
}

void motor_stop()
{
	printf("motor stopping\n");
}

void valve_open()
{
	printf("valve_open\n");
}

void valve_close()
{
	printf("valve_close\n");
}
