/**
  *file:   gpio.c
  *author: Vinas 
  *brief:  GPIO driver source file 
  */


#include "conf.h"

static void __clk_enable(gpio_handleTypedef *handle)
{
  switch(handle->reg)
  {
    case GPIOA:
      RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
      break;
    case GPIOB:
      RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
      break;
    case GPIOC:
      RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
      break;
    case GPIOD:
      RCC->AHBENR |= RCC_AHBENR_GPIODEN;
      break;
    case GPIOE:
      RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
      break;
    case GPIOF:
      RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
      break;
    case GPIOG:
      RCC->AHBENR |= RCC_AHBENR_GPIOGEN;
      break;
    case GPIOH:
      RCC->AHBENR |= RCC_AHBENR_GPIOHEN;
      break;
    default:
      break;
  }
}

static void __clk_disable(gpio_handleTypedef *handle)
{
  switch(handle->reg)
  {
    case GPIOA:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOAEN;
      break;
    case GPIOB:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOBEN;
      break;
    case GPIOC:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOCEN;
      break;
    case GPIOD:
      RCC->AHBENR &= ~RCC_AHBENR_GPIODEN;
      break;
    case GPIOE:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOEEN;
      break;
    case GPIOF:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOFEN;
      break;
    case GPIOG:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOGEN;
      break;
    case GPIOH:
      RCC->AHBENR &= ~RCC_AHBENR_GPIOHEN;
      break;
    default:
      break;
  }
}

void gpio_init(gpio_handleTypdef *handle)
{
  uint32_t temp = 0;
  uint32_t pos = handle->config.pin_no;
  uint32_t reg = handle->reg;
  __clk_enable(handle);

  /****** MODER REG CONFIG ******/ 
  temp = GPIO_MODER_MODER0;
  temp &= handle->config.pin_mode;
  temp = temp << pos;
  reg->MODER &= ~(0x3 << pos);
  reg->MODER |= temp;
  
  /****** OTYPER REG CONFIG ******/
  temp = GPIO_OTYPER_OT_0;
  temp &= handle->config.pin_pu_pd;
  temp = temp << pos;
  reg->OTYPER &= ~(0x1 << pos);
  reg->OTYPER |= temp;

  /****** SPEEDR REG CONFIG ******/
  temp = GPIO_OSPEEDER_OSPEEDR0;
  temp &= handle->config.pin_speed;
  temp = temp << pos;
  reg->MODER &= ~(0x3 << pos);
  reg->OSPEEDR |= temp;

  /****** PUPDR REG CONFIG ******/
  temp = GPIO_PUPDR_PUPDR0;
  temp &= handle->config.pin_pu_pd;
  temp = temp << pos;
  reg->PUPDR &= ~(0x3 << pos);
  reg->PUPDR |= temp;

  /****** AFRL REG CONFIG ******/
  temp = GPIO_AFRL_AFRL0;
  temp &= handle->config.pin_alter;
  temp = temp << pos;

  if(pos <= 7){
  reg->AFR[0] &= ~(0xF << pos);
  reg->AFR[0] |= temp;
  }

  if(pos > 7){
  reg->AFR[1] &= ~(0xF << pos);
  reg->AFR[1] |= temp;
  }
}


