/**
  *file:   gpio.c
  *author: Vinas 
  *brief:  GPIO driver source file 
  */


#include "conf.h"

static void peri_clk_enable(gpio_handleTypedef *handle)
{
  switch(handle->reg)
  {
    case GPIOA:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
      }while(0)
      break;

    case GPIOB:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
      }while(0)  
      break;
      
    case GPIOC:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
      }while(0)  
      break;
      
    case GPIOD:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIODEN;
      }while(0)  
      break;
      
    case GPIOE:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
      }while(0)  
      break;
      
    case GPIOF:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
      }while(0)  
      break;

    case GPIOG:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOGEN;
      }while(0)  
      break;

    case GPIOH:
      do{
        RCC->AHBENR |= RCC_AHBENR_GPIOHEN;
      }while(0)  
      break;

    default:
      break;
  }
}

static void peri_clk_disable(gpio_handleTypedef *handle)
{
  switch(handle->reg)
  {
    case GPIOA:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOAEN;
      }while(0)
      break;

    case GPIOB:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOBEN;
      }while(0)
      break;

    case GPIOC:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOCEN;
      }while(0)
      break;

    case GPIOD:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIODEN;
      }while(0)
      break;

    case GPIOE:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOEEN;
      }while(0)
      break;

    case GPIOF:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOFEN;
      }while(0)
      break;

    case GPIOG:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOGEN;
      }while(0)
      break;

    case GPIOH:
      do{
        RCC->AHBENR &= ~RCC_AHBENR_GPIOHEN;
      }while(0)
      break;

    default:
      break;
  }
}

static void peri_reset(gpio_handleTypedef *handle)
{
  switch (handle->reg)
  {
  case GPIOA:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;
    }while(0)
    break;

  case GPIOB:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST;
    }while(0)
    break;

  case GPIOC:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOCRST;
    }while(0)
    break;
    
  case GPIOD:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIODRST;
    }while(0)
    break;

  case GPIOE:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOERST;
    }while(0)
    break;

  case GPIOF:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOFRST;
    }while(0)
    break;

  case GPIOG:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOGRST;
    }while(0)
    break;

  case GPIOH:
    do{
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOHRST;
    }while(0)
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
  peri_clk_enable(handle);

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

void gpio_deinit(gpio_handleTypedef *handle)
{ 
 peri_reset(handle);
 peri_disable(handle);
}

