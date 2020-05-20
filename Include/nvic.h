/**
  * file:   nvic.h
  * author: Vinas
  * brief:  Nested Vector Interrupt Controller driver header file
  */

//MPU has been disabled, API's have not been included
//These API's are for device specific interrupts
//Core exceptions are not managed by these API's

#ifndef __NVIC_H
#define __NVIC_H

#include "def.h"

//Pre-emption Priority Grouping
#define NVIC_PRIOGROUP_0 (0x00000007U)

#define NVIC_PRIOGROUP_1 (0x00000006U)

#define NVIC_PRIOGROUP_2 (0x00000005U)

#define NVIC_PRIOGROUP_3 (0x00000004U)

#define NVIC_PRIOGROUP_4 (0x00000003U)

void nvic_setpriogrouping(uint32_t group_prio);

void nvic_setprio(IRQn_Type irq, uint32_t preempt_prio, uint32_t sub_prio);

void nvic_enable_it(IRQn_Type irq);

void nvic_disable_it(IRQn_Typek irq);

void nvic_sys_reset(void);

uint32_t void nvic_getpriogrouping(void);

void nvic_getprio(IRQn_Type irq, uint32_t group_prio uint32_t preempt_prio, uint32_t sub_prio);

uint32_t nvic_getpenirq(IRQn_Type irq);

void nvic_setpenirq(IRQn_Type irq);

void nvic_clrpenirq(IRQn_Type irq);

uint32_t nvic_getactive(IRQn_Type irq);

#endif
