/**
  * file:   rcc.c
  * author: Vinas
  * brief:  Reset and Clock Control driver file
  */

#include "conf.h"

__STATIC_INLINE void ahb_setpre(uint32_t pre){

	 
	 RCC->CFGR |= pre;
}

__STATIC_INLINE void apb1_setpre(uint32_t pre){
	 
	 RCC->CFGR |= pre;
}

__STATIC_INLINE void apb2_setpre(uint32_t pre){
	 
	 RCC->CFGR |= pre;
}

uint32_t osc_config(osc_initTypedef* osc){
	 
	 if((osc->hse_state) == osc_ie(hse)){             //HSE CONFIGURATION
		 __asm(NOP);
	 }

	 else{
		 if((osc->hse_state) & hse_off){
			 if((get_pllsrc == pll_hse) && (get_sysclk() == sysclk_pll) || (get_sysclk() == sysclk_hse)){
				 return 0;
			 }

			 else{
				  hse_stateconfig(osc->hse_state);
				  uint32_t time_stamp = get_tick();
				  while (osc_itread(hse_src)){
					  if((get_tick() - time_stamp) > hse_to){
						  return 0;
					  }
				  }
			 }
		 }
		 
	     else{
			  hse_stateconfig(osc->hse_state);
			  uint32_t time_stamp = get_tick();
			  while(!osc_itread(hse_src)){
				  if((get_tick() - time_stamp) > hse_to){
					  return 0;
				  }
			  }
		 }
	 }

	 if(osc->hsi_state == osc_ie(hsi)){           //HSI CONFIGURATION
		 __asm(NOP);
	 }
	 
	 else{
		 if((osc->hsi_state) == hsi_off){
			 if((get_pllsrc == pll_hsi) && (get_sysclk() == sysclk_pll) || (get_sysclk() == sysclk_hsi)){
			 return 0;
			 }
			 
			 else{
				 hsi_disable();
				 uint32_t time_stamp = get_tick();
				 while(osc_itread(hsi_src)){
					 if((get_tick()) - time_stamp > hsi_to){
						 return 0;
					 }
				 }
			 }
		 }

		 else{
			 hsi_enable();
			 uint32_t time_stamp =get_tick();
			 while(!osc_itread(hsi_src)){
				 if((get_tick() - time_stamp) > hsi_to){
					 return 0;
				 }
			 }
		 }
	 }

	 if(osc->lsi_state == osc_ie(lsi)){           //LSI CONFIGURATION
		 __asm(NOP);
	 }
	 
	 else{
		 if((osc->lsi_state) == lsi_off){
			 lsi_disable();
			 uint32_t time_stamp = get_tick();
			 while(osc_itread(lsi_src)){
				 if((get_tick() - time_stamp) > lsi_to){
					 return 0;
				 }
			 }
		 }

		 else{
			 lsi_enable();
			 uint32_t time_stamp =get_tick();
			 while(!osc_itread(lsi_src)){
				 if((get_tick() - time_stamp) > lsi_to){
					 return 0;
				 }
			 }
		 }
	 }

	 if((osc->pll.state) == ose_ie(pll)){       //PLL CONFIGURATION
		 __asm(NOP);
	 }

	 else{
		 if(osc->pll.state == pll_off){
			 return 0;
		 }
		 else{
			 pll_config(pll);
			 pll_enable();
			 uint32_t time_stamp = get_tick();
			 while(!osc_itread(pll_src)){
				 if((get_tick() - time_stamp) > pll_to){
					 return 0;
				 }
			 }
		 }
	 }

	 return 1;
}

uint32_t clk_config(clk_initTypedef* clk, uint32_t flash_latency){

	if(flash_latency > get_latency()){
		set_latency(flash_latency);
	}

	if(get_latency != flash_latency){
		return 0;
	}

	ahb_setpre(clk->ahb_div);
	apb1_setpre(clk->apb1_div);
	apb2_setpre(clk->apb2_div);

	if((clk->sysclk_src) == sysclk_hse){
		if(!osc_itread(hse_src)){
			return 0;
		}
	}

	else if((clk->sysclk_hsi) == sysclk_hsi){
		if(!osc_itread(hsi_src)){
			return 0;
		}
	}

	else((clk->sysclk_pll) == sysclk_pll){
		if(!osc_itread(pll_src)){
			return 0;
		}
	}

	set_sysclk(clk->sysclk_src);

	uint32_t time_stamp = get_tick();
	while(!(get_sysclk() = clk->sysclk_src)){
		if((get_tick() - time_stamp) > cwt_to){
			return 0;
		}
	}

	if(flash_latency < get_latency()){
		set_latency() = flash_latency;
	}

	if(get_latency() != flash_latency){
		return 0;
	}

	SystemCoreClockUpdate();	
	Systick_Init();

	return 1;
}
