#ifndef __LCD1602_H
#define	__LCD1602_H

#include "stm32f10x.h"

typedef volatile  unsigned char  uint8;
typedef volatile  unsigned int   uint16;
typedef volatile  unsigned long  uint32;

#define     LCD1602_RS0      GPIOE->BRR  = 0x00000004;

#define     LCD1602_RW0      GPIOE->BRR  = 0x00000010;

#define     LCD1602_EN0		 GPIOE->BRR  = 0x00000040;

#define     LCD1602_RS1      GPIOE->BSRR = 0x00000004;

#define     LCD1602_RW1      GPIOE->BSRR = 0x00000010;

#define     LCD1602_EN1      GPIOE->BSRR = 0x00000040;

void Delay_us(uint32 CountLing);
void GPIO_InitStructReadtempCmd(void);
void RCC_APB2PeriphReadtempyCmd(void);
void Write_LCD1602_Com(unsigned char Com);
void Write_LCD1602_Data(unsigned char Date);
void Init_LCD1602(void);
void LCD_Write(int x,int y,char ch);

#endif
