/**
  * file:   flash.c
  * author: Vinas
  * brief:  Flash driver file
  */

#include "def.h"

/**brief: enable prefetch buffer
 * param: none
 * retval: none
 */
__INLINE void prefetch_enable(void){
	FLASH->ACR |= FLASH_ACR_PRFTBE;
}

/**brief: diable prefetch buffer
 * param: none
 * retval: none
 */
__INLINE void prefetch_disable(void){
	FLASH->ACR &= (~FLASH_ACR_PRFTBE);

