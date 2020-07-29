/**
  *file:   gpio.h 
  *author: Vinas 
  *brief:  GPIO driver header file 
  */


#ifndef __GPIO_H
#define __GPIO_H

#include "def.h"

typedef struct{
  uint32_t pin_no;
  uint32_t pin_mode;
  uint32_t pin_pu_pd;
  uint32_t pin_pp_od;
  uint32_t pin_speed;
  uint32_t pin_alter;
}gpio_configTypdef

typdef struct{
  gpio_configTypdef config;
  GPIO_Typdef reg;
}gpio_handleTypdef;

//@ GPIO PINS
#define GPIO_PIN_0    0
#define GPIO_PIN_1    1
#define GPIO_PIN_2    2
#define GPIO_PIN_3    3
#define GPIO_PIN_4    4
#define GPIO_PIN_5    5
#define GPIO_PIN_6    6
#define GPIO_PIN_7    7
#define GPIO_PIN_8    8
#define GPIO_PIN_9    9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15

//@ GPIO PIN MODE
#define GPIO_IN   0
#define GPIO_OUT  1
#define GPIO_AF   2
#define GPIO_AN   3

//@ GPIO  PULLUP/PULLDOWN
#define GPIO_NO   0
#define GPIO_PUP  1
#define GPIO_PDW  2

//@ GPIO PIN PUSH PULL/OPEN DRAIN 
#define GPIO_PP  0
#define GPIO_OD  1

//@ GPIO PIN FREQ
#define GPIO_LOW  0
#define GPIO_MED  1
#define GPIO_HIGH 2

//@ GPIO ALTERNATE FUNC MUX
#define GPIO_AF_0     0
#define GPIO_AF_1     1
#define GPIO_AF_2     2
#define GPIO_AF_3     3
#define GPIO_AF_4     4
#define GPIO_AF_5     5
#define GPIO_AF_6     6
#define GPIO_AF_7     7
#define GPIO_AF_8     8
#define GPIO_AF_9     9
#define GPIO_AF_10   10
#define GPIO_AF_11   11
#define GPIO_AF_12   12
#define GPIO_AF_13   13
#define GPIO_AF_14   14
#define GPIO_AF_15   15
#endif