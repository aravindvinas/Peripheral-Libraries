/**
  *file:   uart.c
  *author: Vinas 
  *brief:  UART driver file 
  */  

#include "conf.h"

uin32_t uart_init(uart_typedef *handle)
{
  uint32_t regDef = 0;

  /*****USART CR1 REG CONFIG******/
  regDef |= ((handle->config.word_len) << USART_CR1_M0_Pos);
  regDef |= ((handle->config.parity_bit) << USART_CR1_PS_Pos);
  regDef |= ((handle->config.mode) << USART_CR1_RE_Pos;
  handle->reg.CR1 |= regDef;

  /******USART CR2 REG CONFIG******/
  regDef = 0;
  regDef = ((handle->config.stop_bit << USART_CR2_STOP_Pos);
  handle->reg.CR2 |= regDef;

  /******USART CR3 REG CONFIG******/
  regDef = 0;
  regDef = (handle->config.hw_fctrl) << USART_CR3_RTSE);
  handle->reg.CR3 |= regDef;

  /******USART BRR REG CONFIG******/
  handle->reg.BRR |= 0x341; //8MHz fClk and 9600 bits/sec

  /******USART ENABLE******/
  handle->reg.CR1 |= (1 << USART_CR1_UE_Pos);

}

uint32_t uart_transmit(uint8_t *data)
{

}
