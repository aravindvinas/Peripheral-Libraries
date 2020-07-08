/**
  * file:   systick.h
  * author: Vinas
  * brief:  Systick Timer driver header file
  */

#ifndef SYSTICK_H
#define SYSTICK_H

#include "def.h"

#define tick_freq      1U

#define MAX_DELAY			 (0xFFFFFFFFU)
#define SYSTICK_SOURCE_DIV8  (0x00000000U)
#define SYSTICK_SOURCE       SysTick_CTRL_CLKSOURCE_Msk

uint32_t SystemCoreClock = 8000000;



/** keeps the tick count from start of systick initialisation.
  */
volatile uint32_t tick_count;

                               /***EXPORTED FUCNTIONS***/
uint32_t get_tick(void);

void time_inc(void);
	
uint32_t SysTick_Init();

void ms_delay(uint32_t period);

void SysTick_ConfClkSrc(uint32_t ClkSrc);

#endif
