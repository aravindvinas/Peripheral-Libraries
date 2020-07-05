/**
  * file:   handler.c
  * author: Vinas
  * brief:  Interrupt and Exception handler driver file
  */

#include "conf.h"

void NMI_Handler(void){while(1){}}

/**brief:  HardFault exception handler 
  *param:  none
  *retval: none
  */
void HardFault_Handler(void){while(1){}}

/**brief:  Memory Management exception handler 
  *param:  none
  *retval: none
  */
void MemManage_Handler(void){while(1){}}

/**brief:  Bus Fault exception handler 
  *param:  none
  *retval: none
  */
void BusFault_Handler(void){while(1){}}

/**brief:  Usage Fault exception handler 
  *param:  none
  *retval: none
  */
void UsageFault_Handler(void){while(1){}}

/**brief:  SVC exception handler 
  *param:  none
  *retval: none
  */
void SVC_Handler(void){while(1){}}

/**brief:  Debug Monitor exception handler 
  *param:  none
  *retval: none
  */
void DebugMon_Handler(void){while(1){}}

/**brief:  PendSV exception handler
  *param:  none
  *retval: none
  */
void PendSV_Handler(void){while(1){}}

/**brief:  Systick interrupt handler 
  *param:  none
  *retval: none
  */
void SysTick_Handler(void){
	time_inc();                    //SysTick handler calls func to increment tick count
}

/**brief:  Flash interrupt handler 
  *param:  none
  *retval: none
  */
void Flash_IRQHandler(void){
	flash_irqhandler();
}

