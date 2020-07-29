/**
  *file:   uart.c
  *author: Vinas 
  *brief:  UART driver file 
  */  

#ifndef __UART_H
#define __UART_H

#include "def.h"

typedef struct{
  uint32_t baudrate;
  uint32_t word_len;
  uint32_t parity_bit;
  uint32_t stop_bit;
  uint32_t mode;
  uint32_t hw_fctrl;
}uart_configTypedef;

typdef struct{
  uart_configTypedef config;
  USART_TypeDef reg;
  uint8_t *txBuf;
  uint8_t *rxBuf;
  uint32_t txState;
  uint32_t rxState; 
}uart_handleTypedef;

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

uint32_t uart_init(uart_handleTypedef *handle);
uint32_t uart_transmit(uint8_t *data);

#endif
