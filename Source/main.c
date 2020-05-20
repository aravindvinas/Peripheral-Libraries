/**
  * file:   main.c
  * author: Vinas
  * brief:  main application file
  */

#include "main.h"

void SystemClockConfig(void);

int main(void){

	 prefetch_enable();
	 nvic_setpriogrouping(NVIC_PRIOGROUP_4);
	 SysTick_Init();

	 while(1){

		 /****Insert User Code****/
	 }
}

void SystemConfigClock(void){

	 /****Configure System Core Clock****/
}

void Error_Handler(void){

	 /****Error Handler****/
}

