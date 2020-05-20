/**
  * file:   rcc.h
  * author: Vinas
  * brief:  Reset and Clock Control driver header file
  */

#ifndef __RCC_H
#define __RCC_H

//BIT-BANDING not used in this driver

#include "def.h"

//OSCILLATORS
#define lsi 0
#define hsi 1
#define lse 2
#define hse 3
#define pll 4

//OSCILLATOR STATE TYPE
#define pll_on    RCC_CR_PLLON
#define pll_off   0
#define hse_on    RCC_CR_HSEON
#define hse_off   0
#define hse_ext   RCC_CR_HSEBYP | RCC_CR_HSEON
#define lse_on    RCC_BDCR_LSEON
#define lse_off   0
#define lse_ext   RCC_BDCR_LSEBYP | RCC_BDCR_LSEON
#define hsi_on    RCC_CR_HSION
#define hsi_off   0
#define lsi_on    RCC_CSR_LSION
#define lsi_off   0

// TIMEOUT VALUES
#define lse_to   (5000U)  
#define lsi_to   (2U)
#define hse_to   (100U)
#define hsi_to   (2U)
#define pll_to   (2U)
#define cwt_to   (5000U)

//PLL SOURCE 
#define pll_src  RCC_CFGR_PLLSRC
#define pll_hsi  RCC_CFGR_PLLSRC_HSI_PREDIV    
#define pll_hse  RCC_CFGR_PLLSRC_HSE_PREDIV    
#define pll_hsi2 0x00000000					  

//PLL multiplication factor
#define pll_mul2  RCC_CFGR_PLLMUL2
#define pll_mul3  RCC_CFGR_PLLMUL3
#define pll_mul4  RCC_CFGR_PLLMUL4
#define pll_mul5  RCC_CFGR_PLLMUL5
#define pll_mul6  RCC_CFGR_PLLMUL6
#define pll_mul7  RCC_CFGR_PLLMUL7
#define pll_mul8  RCC_CFGR_PLLMUL8
#define pll_mul9  RCC_CFGR_PLLMUL9
#define pll_mul10 RCC_CFGR_PLLMUL10
#define pll_mul11 RCC_CFGR_PLLMUL11
#define pll_mul12 RCC_CFGR_PLLMUL12
#define pll_mul13 RCC_CFGR_PLLMUL13
#define pll_mul14 RCC_CFGR_PLLMUL14
#define pll_mul15 RCC_CFGR_PLLMUL15
#define pll_mul16 RCC_CFGR_PLLMUL16

//PLL PREDIV FACTOR
#define pll_pre1  RCC_CFGR2_PREDIV_DIV1
#define pll_pre2  RCC_CFGR2_PREDIV_DIV2
#define pll_pre3  RCC_CFGR2_PREDIV_DIV3
#define pll_pre4  RCC_CFGR2_PREDIV_DIV4
#define pll_pre5  RCC_CFGR2_PREDIV_DIV5
#define pll_pre6  RCC_CFGR2_PREDIV_DIV6
#define pll_pre7  RCC_CFGR2_PREDIV_DIV7
#define pll_pre8  RCC_CFGR2_PREDIV_DIV8
#define pll_pre9  RCC_CFGR2_PREDIV_DIV9
#define pll_pre10 RCC_CFGR2_PREDIV_DIV10
#define pll_pre11 RCC_CFGR2_PREDIV_DIV11
#define pll_pre12 RCC_CFGR2_PREDIV_DIV12
#define pll_pre13 RCC_CFGR2_PREDIV_DIV13
#define pll_pre14 RCC_CFGR2_PREDIV_DIV14
#define pll_pre15 RCC_CFGR2_PREDIV_DIV15
#define pll_pre16 RCC_CFGR2_PREDIV_DIV16

//HSI CALIBRATION DEFAULT
#define hsi_defaultcalib       (0x10U)

//SYSCLK SOURCE SW
#define sysclk_src  RCC_CFGR_SW
#define sysclk_hsi  RCC_CFGR_SW_HSI
#define sysclk_hse  RCC_CFGR_SW_HSE
#define sysclk_pll  RCC_CFGR_SW_PLL

//SYSCLK SOURCE HW
#define sysclk_srchw RCC_CFGR_SWS
#define sysclk_hsihw RCC_CFGR_SWS_HSI 
#define sysclk_hsehw RCC_CFGR_SWS_HSE
#define sysclk_pllhw RCC_CFGR_SWS_PLL

//AHB PRESCALER
#define ahb_pre1    RCC_CFGR_HPRE_DIV
#define ahb_pre2    RCC_CFGR_HPRE_DIV
#define ahb_pre4    RCC_CFGR_HPRE_DIV
#define ahb_pre8    RCC_CFGR_HPRE_DIV
#define ahb_pre16   RCC_CFGR_HPRE_DIV
#define ahb_pre64   RCC_CFGR_HPRE_DIV
#define ahb_pre128  RCC_CFGR_HPRE_DIV
#define ahb_pre256  RCC_CFGR_HPRE_DIV
#define ahb_pre512  RCC_CFGR_HPRE_DIV

//APB1 PRESCALER
#define hclk_pre1  RCC_CFGR_PPRE1_DIV1
#define hclk_pre2  RCC_CFGR_PPRE1_DIV2
#define hclk_pre4  RCC_CFGR_PPRE1_DIV4
#define hclk_pre8  RCC_CFGR_PPRE1_DIV8
#define hclk_pre16 RCC_CFGR_PPRE1_DIV16

//APB2 PRESCALER
#define hclk_pre1  RCC_CFGR_PPRE2_DIV1
#define hclk_pre2  RCC_CFGR_PPRE2_DIV2
#define hclk_pre4  RCC_CFGR_PPRE2_DIV4
#define hclk_pre8  RCC_CFGR_PPRE2_DIV8
#define hclk_pre16 RCC_CFGR_PPRE2_DIV16

//RCC INTERRUPTS
#define css_en   RCC_CR_CSSON     //CSS ENABLE BIT
#define css_it   RCC_CIR_CSSF     //CSS INTERRUPT BIT
#define css_clr  RCC_CIR_CSSC     //CSS PENDING CLEAR BIT

//osc_src
#define lsi_rdy  RCC_CIR_LSIRDYF
#define hsi_rdy  RCC_CIR_HSIRDYF
#define lse_rdy  RCC_CIR_LSERDYF
#define hse_rdy  RCC_CIR_HSERDYF
#define pll_rdy  RCC_CIR_PLLRDYF

//osc_it
#define lsi_it   RCC_CIR_LSIRDYIE
#define hsi_it   RCC_CIR_LSERDYIE
#define lse_it   RCC_CIR_HSIRDYIE
#define hse_it   RCC_CIR_HSERDYIE
#define pll_it   RCC_CIR_PLLRDYIE

//osc_clr
#define lsi_clr  RCC_CIR_LSIRDYC
#define hsi_clr  RCC_CIR_HSIRDYC
#define lse_clr  RCC_CIR_LSERDYC
#define hse_clr  RCC_CIR_HSERDYC
#define pll_clr  RCC_CIR_PLLRDYC


typedef struct{
	 
	 uint32_t pll_src;
	 uint32_t pll_mul;
	 uint32_t pll_pre;
	 uint32_t pll_state;
}pll_initTypedef;

typedef struct{
	 
	 uint32_t hse_state;
     uint32_t hsi_state;
	 uint32_t lse_state;
	 uint32_t lsi_state;
	 uint32_t hse_pre;        //use from group PLL PREDIV FACTOR 
	 uint32_t hsi_calib;
	 pll_initTypedef pll;
}osc_initTypedef;

typedef struct{
	
	 uint32_t sysclk_src;
	 uint32_t ahb_div;
	 uint32_t apb1_div;
	 uint32_t apb2_div;
}clk_initTypedef;

/************************************************************** RCC INTRINSIC API's ***************************************************************************/
/** brief:  HSI oscillator enable
  * param:  none
  * retval: none
  */
_INLINE void hsi_enable(void){
	 RCC->CR |= hsi_on;
}

/** brief:  HSI oscillator disable
  * param:  none
  * retval: none
  */
__INLINE void hsi_disable(void){
	 
	 RCC->CR |= hsi_off;
}

/** brief:  LSI oscillator enable
  * param:  none
  * retval: none
  */
_INLINE void lsi_enable(void){
	 
	 RCC->CSR |= lsi_on ;
}

/** brief:  LSI oscillator disable
  * param:  none
  * retval: none
  */
__INLINE void lsi_disable(void){
	 
	 RCC->CSR |= lsi_off;
}

/** brief:  HSE oscillator enable
  * param:  HSE state type
  * retval: 1->SUCCESS, 0->wrong state input
  */
__INLINE uint32_t hse_stateconfig(uint32_t state){
	 
	 if(state == hse_off){
		 RCC->CR |= state;
		 return 1;
	 }

	 else if(state == hse_on){
		 RCC->CR |= state;
		 return 1;
	 }

	 else if(state == hse_ext){
		 RCC->CR |= state;
		 return 1;
	 }

	 else{ return 0; }
}

/** brief:  LSE oscillator enable
  * param:  LSE state type
  * retval: 1->SUCCESS, 0->wrong state input
  */
__INLINE uint32_t lse_stateconfig(uint32_t state){
	 
	 if(state == lse_off){
		 RCC->BDCR |= state;
		 return 1;
	 }

	 else if(state == lse_on){
		 RCC->BDCR |= state;
		 return 1;
	 }

	 else if(state == lse_ext){
		 RCC->BDCR |= state;
		 return 1;
	 }

	 else{ return 0; }
}

/** brief:  PLL enable
  * param:  none
  * retval: none
  */
__INLINE void pll_enable(void){
	 
	 RCC->CR |= pll_on;
}

/** brief:  PLL_disable
  * param:  none
  * retval: none
  */
__INLINE void pll_disable(void){
	 
	 RCC->CR |= pll_off;
}

/** brief:  PLL config
  * param:  pll_initTypedef object 
  * retval: none
  */
__INLINE void pll_config(pll_initTypedef* pll){

	RCC->CFGR2 |= (pll->pll_pre);
	RCC->CFGR  |= ((pll->pll_mul) || (pll->pll_src)); 
}

/** brief:  Get PLL source
  * param:  none
  * retval: PLL source
  */
uint32_t get_pllsrc(void){
	  
	 uint32_t bit_val;
	 bit_val = (RCC->CFGR) & (pllsrc);
	 return bit_val;
}

/**brief:  Check if oscillator is On/Off
  *param:  none
  *retval: osc_state
  */
uint32_t osc_ie(uint32_t osc){
	 
	 uint32_t ret_val;
	 switch(osc){
	 	case 0:
            if((RCC->CSR) & (lsi_on)){
            	ret_val = lsi_on;
            }
            else{
            	ret_val = lsi_off;
            }
			break;

		case 1:
		    if((RCC->CR) & (hsi_on)){
		    	ret_val = hsi_on;
		    }
		    else{
		    	ret_val = hsi_off;
		    }
		    break;

		case 2:
		    if((RCC->BDCR) & (lse_on)){
		    	ret_val = lse_on;
		    }
		    else{
		    	ret_val = lse_off;
		    }
		    break;

		case 3:
		    if((RCC->CR) & (hse_on)){
		    	ret_val = hse_on;
		    }
		    else{
		    	ret_val = hse_off;
		    }
		    break;

		case 4:
		    if((RCC->CR) & (pll_on)){
		    	ret_val = pll_on;
		    }
		    else{
		    	ret_val = pll_off;
		    }
		    break;
	 }

	 return ret_val;
}


/** brief:  Sysclk source set
  * param:  Sysclk oscillator source type
  * retval: 1->SUCCESS, 0->wrong state input
  */
__INLINE uint32_t set_sysclk(uint32_t src){
	 
	 if(src == sysclk_hsi){
		 RCC->CFGR |= src;
		 return 1;
	 }

	 else if(src == sysclk_hse){
		 RCC->CFGR |= src;
		 return 1;
	 }

	 else if(src == sysclk_pll){
		 RCC->CFGR |= src;
		 return 1;
	 }

	 else{ return 0; }
}

/** brief:  Get Sysclk source
  * param:  none
  * retval: Sysclk source
  */
uint32_t get_sysclk(void){
	 
	 uint32_t bit_val;
	 bit_val = (RCC->CFGR) & (sysclk_srchw);
	 bit_val = (bit_val >> 2);
	 return bit_val;
}

/****************************************************************** OSC INTERRUPT API's *****************************************************************************************/
/**brief:  Enable CSS interrupt
  *param:  none
  *retval: none
  */
__INLINE void css_enable(void){
	 
	 RCC->CR |= css_en;
}

/**brief:  Disable CSS interrupt
  *param:  none
  *retval: none
  */
__INLINE void css_disable(void){
	 
	 RCC->CR &= ~(css_en);
}

/**brief:  CSS interrupt flag check
  *param:  none
  *retval: 1->interrupt triggered, 0->No interrupt triggered
  */
__INLINE uint32_t css_irq(void){
	 
     if((RCC->CIR) & (css_it)){
		  
		 return 1;
		}
	 return 0;
}

/**brief:  CSS clear pending bits
  *param:  none
  *retval: none
  */
__INLINE void css_clrpen(void){
	 
	 RCC->CIR |= css_clr;
}

/**brief:  CSS callback function
  *param:  none
  *retval: none
  */
__weak void css_callback(void){
	 
	 // To be override in application code
}

/**brief:  Oscillator interrupt enable
  *param:  Oscillator Interrupt
  *retval: none
  */
__INLINE void osc_itenable(uint32_t osc_it){
	 
   	 RCC->CIR |= osc_it;
	 
}

/**brief:  Oscillator interrupt disable
  *param:  Oscillator Interrupt
  *retval: none
  */
__INLINE void osc_itdisable(uint32_t osc_it){
	 
	 RCC->CIR &= ~(osc_it);
}

/**brief:  Oscillator interrupt disable
  *param:  Oscillator Interrupt
  *retval: none
  */
__INLINE void osc_clearpen(uint32_t osc_clr){
	 
	 RCC->CIR |= osc_clr;
}

/**brief:  Oscillator interrupt flag
  *param:  Oscillator Interrupt
  *retval: 1->Flag Set, 0-> Flag RESET
  */
__INLINE uint32_t osc_itread(uint32_t osc_src){
	 
	 if((RCC->CIR) & (osc_src)){
		  
		 return 1;
	 }

	 return 0;
}

/****************************************************************** EXPORTED API's *****************************************************************************************/

uint32_t osc_config(osc_initTypedef* osc);

uint32_t clk_config(clk_initTypedef* clk);

uint32_t rcc_default(void);

#endif
