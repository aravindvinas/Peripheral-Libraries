/**
  *file:   uart.c
  *author: Vinas 
  *brief:  UART driver file 
  */  

#include "conf.h"

static void peri_clk_enable(usart_Typedef *handle)
{
  switch (handle->reg)
  {
  case USART2:
    do{
      RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
      break;
    }while(0)

  case USART3:
    do{
      RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
      break;
    }while(0)

  case UART4:
    do{
      RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
      break;
    }while(0)

  case UART5:
    do{
      RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
      break;
    }while(0)
  
  default:
    break;
  }
}

static void peri_clk_disable(usart_Typedef *handle)
{

  switch (handle->reg)
  {
  case USART2:
    do{
      RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN);
      break;
    }while(0)

  case USART3:
    do{
      RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN);
      break;
    }while(0)

  case UART4:
    do{
      RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN);
      break;
    }while(0)

  case UART5:
    do{
      RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN);
      break;
    }while(0)
  
  default:
    break;
  }
}

static void peri_reset(usart_Typedef *handle)
{
  switch (handle->reg)
  {
  case USART2:
    do{
      RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
      break;
    }

  case USART3:
    do{
      RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
      break;
    }

  case UART4:
    do{
      RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;
      break;
    }

  case UART5:
    do{
      RCC->APB1RSTR |= RCC_APB1RSTR_UART5;
      break;
    }
  
  default:
    break;
  }
}

void usart_init(uart_handleTypedef *handle)
{
  uint32_t temp = 0;
  uint32_t reg = handle->reg;

  __peri_clk_enable(handle);

  /*****USART CR1 REG CONFIG******/
  temp = (USART_CR1_PCE | USART_CR1_PS | USART_CR1_M0);
  temp &= (handle->config.usart_parity << USART_CR1_PS_Pos);
  temp &= (handle->config.usart_word << USART_CR1_M0_Pos);
  reg->CR1 &= (USART_CR1_PCE | USART_CR1_PS | USART_CR1_M0);
  reg->CR1 |= temp;

  /******USART CR2 REG CONFIG******/
  temp = 0;
  temp = USART_CR1_STOP;
  temp &= (handle->config.usart_stop << USART_CR2_STOP_Pos);
  reg->CR2 &= USART_CR2_STOP;
  reg->CR2 |= temp;

  /******USART CR3 REG CONFIG******/
  temp = 0;
  temp = (USART_CR3_RTSE | USART_CR3_CTSE);
  temp = (handle->config.usart_hw_fctrl) << USART_CR3_RTSE);
  reg->CR3 &= (USART_CR3_RTSE | USART_CR3_CTSE);
  reg->CR3 |= temp;

  /******USART BRR REG CONFIG******/
  handle->reg.BRR |= 0x341; //8MHz fClk and 9600 bits/sec

  /******USART ENABLE******/
  handle->reg.CR1 |= (1 << USART_CR1_UE_Pos);
}

void usart_deinit(usart_handleTypedef *handle)
{
  __peri_clk_disable();
}
