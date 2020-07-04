/**
  * file:   systick.c
  * author: Vinas
  * brief:  Systick Timer driver file
  */

#include "conf.h"


/**brief  :  func to get current tick value
  *param  :  none
  *retval :  tick_count
  */
uint32_t get_tick(void){
	return tick_count;
}

/**brief  :  func to increment tick_count; used by Systick_Handler()
  *param  :  none
  *retval :  none
  */
void time_inc(void){
	tick_count += tick_count;
}						


/** brief  :    called after reset handler to initialise SysTick Timer
  * param  :    none
  * retval :    0->FAIL, 1->SUCCESS
  */
uint32_t SysTick_Init(){

	uint32_t ticks = SystemCoreClock/1000U;
	if(SysTick_Config(ticks) == 1UL){
		return 0;
	}

	tick_count = 0; //reset the tick_count variable everytime SysTick Timer resets
	return 1;
}

/**brief  :  delay in blocking mode
  *param  :  number of milliseconds
  *retval :  none
  */
void ms_delay(uint32_t period){

	if(period > MAX_DELAY){period=MAX_DELAY;}
	else{period+=(uint32_t)tick_freq;}
    
	uint32_t tick_start = get_tick();
	while(get_tick() - tick_start < period){__NOP();}
}

/**brief  : Change Clk source of SysTick timer
  * param : Clk Source
  *retval : none
  */
void SysTick_ConfClkSrc(uint32_t ClkSrc){

	if(ClkSrc == SYSTICK_SOURCE){

		SysTick->CTRL |= SYSTICK_SOURCE;
	}

	else{
		SysTick->CTRL |= SYSTICK_SOURCE_DIV8;
	}
}

