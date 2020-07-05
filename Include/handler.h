/**
  * file:   handler.h
  * author: Vinas
  * brief:  Interrupt and Exception handler driver header file
  */

#ifndef __HANDLER_H
#define __HANDLER_H

#include "def.h"

                                                     /************EXPORTED FUNCTIONS***************/

void NMI_Handler(void);

void HardFault_Handler(void);

void MemManage_Handler(void);

void BusFault_Handler(void);

void UsageFault_Handler(void);

void SVC_Handler(void);

void DebugMon_Handler(void);

void PendSV_Handler(void);

void SysTick_Handler(void);

void Flash_IRQHandler(void);

#endif
