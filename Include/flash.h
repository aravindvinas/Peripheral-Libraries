/**
  * file:   flash.h
  * author: Vinas
  * brief:  Flash driver header file
  */

#ifndef __FLASH_H
#define __FLASH_H

#include "def.h"

#define FLASH_TIMEOUT    (50000U)

/*************************
 * 
 *  FLASH INTRINSIC API's 
 * 
 *************************/

/**brief:  Set Flash Latency
  *param:  FLASH_LATENCY_x (x= {0, 1, 2})
  *retval: None 
  */ 
__INLINE void set_flash_latency(uint32_t latency)
{
  FLASH->ACR &= ~(FLASH_ACR_LATENCY);
  FLASH->ACR |= (latency);
}

/**brief:  Get Flash Latency 
  *param:  None 
  *retval: FLASH_LATENCY_x (x= {0, 1, 2}) 
  */
uint32_t get_flash_latency(void)
{
  uint32_t latency = 0;
  latency = (FLASH->ACR) & (FLASH_ACR_LATENCY); 
  return latency;
}

/*brief:  Enable Half Cycle Access
 *param:  None
 *retval: None
 */
__INLINE void enable_halfcycle(void)
{
  FLASH->ACR |= (FLASH_ACR_HLFCYA);
}

/**brief:  Disable Half Cycle Access
  *param:  None
  *retval: None
  */
__INLINE void disable_halfcycle(void)
{
  FLASH->ACR &= ~(FLASH_ACR_HLFCYA);
}

/**brief:   Enable prefetch buffer
  *param:   None
  * retval: None
  */  
__INLINE void prefetch_enable(void)
{
  FLASH->ACR |= (FLASH_ACR_PRFTBE);
}

/**brief:   Disable prefetch buffer
  *param:   None
  * retval: None
  */  
__INLINE void prefetch_disable()
{
  FLASH->ACR &= ~(FLASH_ACR_PRFTBE); 
}

/**brief:  Get Flash Flag Status
  *param:  FLASH_SR_xxx (xxx = {EOP, WRPRERR, PGERR, BSY})
  *retval: 0->Flag Reset, 1->Flag Set 
  */ 
uint8_t get_flash_status(uint32_t flag)
{
  if((FLASH->SR & flag) == flag){
    return 1; 
  }

  return 0;
}

/**brief:  Clear Flash Flag Status
  *param:  FLASH_SR_xxx (xxx = {EOP, WRPERR, PGERR})
  *retval: None 
  */ 
__INLINE void clear_flash_status(uint32_t flag)
{
  FLASH->SR |= flag;
}

/**brief:  Enable Interrupt in Flash Controller
  *param:  FLASH_CR_xxx (xxx = {EOPIE, ERRIE})
  *retval: None 
  */ 
__INLINE void flash_enableIT(uint32_t interrupt)
{
  FLASH->CR |= interrupt;
}

/**brief:  Disable Interrupt in Flash Controller
  *param:  FLASH_CR_xxx (xxx = {EOPIE, ERRIE})
  *retval: None 
  */ 
__INLINE void flash_disableIT(uint32_t interrupt)
{
  FLASH->CR &= ~(interrupt);
}


/*************************
 * 
 *  FLASH PERIPHERAL API's 
 * 
 *************************/

void flash_lock(void);
void flash_unlock(void);
void flash_program(uint32_t addr, uint16_t data);
void flash_erase(uint32_t addr);
void flash_eraseall(void);
void flash_irqhandler(void);


#endif
