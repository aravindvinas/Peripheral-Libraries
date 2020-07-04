/**
  * file:   nvic.c
  * author: Vinas
  * brief:  Nested Vector Interrupt Controller driver file
  */


#include "conf.h"

/**brief  : set priority grouping
 * param  : group priority
 * retval : none
 */
void nvic_setpriogrouping(uint32_t group_prio){
	 
	 NVIC_SetPriorityGrouping(group_prio);
}

/**brief  : set interrupt priority 
 * param  : interrupt number, preempt priority, sub-priority
 * retval : none
 */
void nvic_setprio(IRQn_Type irq, uint32_t preempt_prio, uint32_t sub_prio){
     
     uint32_t group_prio = NVIC_GetPriorityGrouping(); 
	 NVIC_SetPriority(irq, NVIC_EncodePriority(group_prio, preempt_prio, sub_prio));
}

/**brief  : enable interrupt
 * param  : interrupt number
 * retval : none
 */
void nvic_enable_it(IRQn_Type irq){
     
     NVIC_EnableIRQ(irq);
}

/**brief  : disable interrupt
 * param  : interrupt number
 * retval : none
 */
void nvic_disable_it(IRQn_Type irq){
     
	 NVIC_DisableIRQ(irq);
}

/**brief  : reset the system
 * param  : none
 * retval : none
 */
void nvic_sys_reset(void){
	 
	 NVIC_SystemReset();
}

/**brief  : get priority grouping
 * param  : none
 * retval : group priority
 */
uint32_t nvic_getpriogrouping(void){
	 
	 return NVIC_GetPriorityGrouping();
}

/**brief  : get interrupt priority
 * param  : interrupt number, variables to store group, preempt and sub priority values
 * retval : none
 */
void nvic_getprio(IRQn_Type irq, uint32_t group_prio, uint32_t preempt_prio, uint32_t sub_prio){
	 
	 NVIC_DecodePriority(NVIC_GetPriority(irq), group_prio, preempt_prio, sub_prio);
}

/**brief  : get pending interrupt
  *param  : interrupt number
  *retval : 0U | 1U
  */
uint32_t nvic_getpenirq(IRQn_Type irq){
	 
	 uint32_t irqn = NVIC_GetPendingIRQ(irq);
	 return irqn;
}

/**brief  : set pending interrupt
  *param  : interrupt number
  *retval : none
  */
void nvic_setpenirq(IRQn_Type irq){
	 
	 NVIC_SetPendingIRQ(irq);
}

/**brief  : clear pending interrupt
  *param  : interrupt number
  *retval : none
  */
void nvic_clrpenirq(IRQn_Type irq){
	 
	 NVIC_ClearPendingIRQ(irq);
}

/**brief  : get active bit
  *param  : interrupt number
  *retval : 0U | 1U
  */
uint32_t nvic_getactive(IRQn_Type irq){
	 
	 return NVIC_GetActive(irq);
}

