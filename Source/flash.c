/**
  * file:   flash.c
  * author: Vinas
  * brief:  Flash driver file
  */

#include "conf.h"

/********************
 *
 *  Helper Functions 
 * 
 * ******************/

static void flash_lastcmpl(void)
{
  while(get_flash_status(FLASH_SR_BSY));
}

/*************************
 * 
 *  FLASH PERIPHERAL API's 
 * 
 *************************/
/*brief:  Lock Flash Access
 *param:  None
 *retval: None 
 */
void flash_lock(void)
{
  FLASH->CR |= FLASH_CR_LOCK;
}

/*brief:  Unlock Flash Access
 *param:  None
 *retval: None 
 */
void flash_unlock(void)
{
  FLASH->KEYR |= FLASH_KEY1;
  FLASH->KEYR |= FLASH_KEY2;
}

/*brief:  Program the given Flash Address
 *param:  32 bit address, 16 bit value
 *retval: None 
 */
void flash_program(uint32_t addr, uint16_t data)
{
  flash_unlock();
  flash_lastcmpl();
  FLASH->CR |= FLASH_CR_PG;
  *(__IO uint16_t*)addr = data;
  flash_lastcmpl();
  clear_flash_status(FLASH_SR_EOP);
  FLASH->CR &= ~(FLASH_CR_PG);
}

/*brief:  Erase a single page of Flash Memory
 *param:  initial address of page
 *retval: None 
 */
void flash_erase(uint32_t addr)
{
  flash_unlock();
  flash_lastcmpl();
  FLASH->CR |= FLASH_CR_PER;
  FLASH->AR |= addr;
  FLASH->CR |= FLASH_CR_STRT;
  __NOP();
  flash_lastcmpl();
  clear_flash_status(FLASH_SR_EOP);
  FLASH->CR &= ~(FLASH_CR_PER);
}

/*brief:  Erase all pages of Flash Memory
 *param:  None
 *retval: None 
 */
void flash_eraseall(void)
{
  flash_unlock();
  flash_lastcmpl();
  FLASH->CR |= FLASH_CR_MER;
  FLASH->CR |= FLASH_CR_STRT;
  __NOP();
  flash_lastcmpl();
  clear_flash_status(FLASH_SR_EOP);
  FLASH->CR &= ~(FLASH_CR_MER);
}

/*brief:  Flash Error Callback
 *param:  None
 *retval: None 
 */
__weak void flash_error_callback(void){}

/*brief:  Flash EOP Callback
 *param:  None
 *retval: None 
 */
__weak void flash_eop_callback(void){}
/*brief:  Flash interrupt handler
 *param:  None
 *retval: None 
 */

void flash_irqhandler(void)
{
  if(get_flash_status(FLASH_CR_ERRIE)){
    flash_error_callback();
  }

  if(get_flash_status(FLASH_CR_EOPIE)){
    flash_eop_callback();
  }
}

