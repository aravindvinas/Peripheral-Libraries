/**
  * file:   flash.h
  * author: Vinas
  * brief:  Flash driver header file
  */

#ifndef __FLASH_H
#define __FLASH_H

#include "def.h"

//Flash latency 
#define flash_latencysrc 0x00000007   
#define flash_latency0   0x00000000   //0 latency cycles
#define flash_latency1   0x00000001   //1 latency cycles
#define flash_latency2   0x00000002   //2 latency cycles

__INLINE void set_latency(uint32_t flash_latency){

      RCC->ACR |= flash_latency;	  
}

__INLINE uint32_t get_latency(void){

	  uint32_t flash_latency = (RCC->ACR) & (flash_latencysrc);
	  return flash_latency;
}

__INLINE void prefetch_enable(void)
__INLINE void prefetch_disable(void)

#endif
