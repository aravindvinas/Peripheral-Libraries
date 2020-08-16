/**
  *file:   uart.h
  *author: Vinas 
  *brief:  UART driver header file 
  */  

#ifndef __UART_H
#define __UART_H

#include "def.h"

typedef struct{
  uint32_t usart_baud;
  uint32_t usart_word;
  uint32_t usart_parity;
  uint32_t usart_stop;
  uint32_t usart_mode;
  uint32_t usart_hw_fctrl;
}usart_configTypedef;

typedef struct{
  usart_configTypedef config;
  USART_TypeDef* reg;
  uint8_t *txBuf;
  uint8_t *rxBuf;
  uint32_t txState;
  uint32_t rxState; 
}usart_handleTypedef;

//@ baud rate 
#define USART_BAUD_9600   9600U
// 115200 baud rate functionality not available
//#define USART_BAUD_115200 115200U

//@ word length 
#define USART_WLEN_8 0U
#define USART_WLEN_9 1U

//@ parity bit
#define USART_PAR_NONE 0U
#define USART_PAR_EVEN 2U
#define USART_PAR_ODD  3U

//@ stop bit
#define USART_STOP_1    0U
#define USART_STOP_0_5  1U
#define USART_STOP_2    2U
#define USART_STOP_1_5  3U

//@ operating mode
#define USART_Rx    1U
#define USART_Tx    2U
#define USART_Tx_Rx 3U

//@ hardware flow control
#define USART_FCTRL_NONE    0U
#define USART_FCTRL_RTS     1U
#define USART_FCTRL_CTS     2U
#define USART_FCTRL_RTS_CTS 3U

//@ USART INIT DEINIT FUNC
void usart_init(usart_handleTypedef *handle);
void usart_deinit(usart_handleTypedef *handle);

#endif
