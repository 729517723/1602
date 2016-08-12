#include"LCD1602.h"

void Delay_us(uint32 CountLing)

{

signed char i;

while(CountLing--)

{

i = 10;

while(i--);

}

}

/**************************************************************

* 函数名：GPIO_InitStructReadtempCmd(void)

* 功能  ：设置GPIO输出

* 输入数据：无

* 输出数据：     无

* 被调用函数  ： main()；

***************************************************************/

void GPIO_InitStructReadtempCmd(void)

{

GPIOE->CRL = 0x33333333;

GPIOE->CRH = 0x33333333;

GPIOD->CRL = 0x33333333;

}

/**************************************************************

* 函数名：RCC_APB2PeriphReadtempyCom(void)

* 功能  ：配置外设时钟

* 输入数据：无

* 输出数据：     无

* 被调用函数  ： main()；

***************************************************************/

void RCC_APB2PeriphReadtempyCmd(void)

{

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

}

/**************************************************************

* 函数名：Wrint_LCD1602_BOOCK_Com(unsigned char Com)

* 功能  ：写指令

* 输入数据：无

* 输出数据：     无

* 被调用函数  ： Write_LCD1602_BOOCK_Com_Data();

***************************************************************/

void Write_LCD1602_Com(unsigned char Com)

{

LCD1602_RS0;

LCD1602_RW0;

LCD1602_EN0;

GPIOD->ODR = Com;

Delay_us(340);

LCD1602_EN1;

Delay_us(340);

LCD1602_EN0;

}

/**************************************************************

* 函数名：Write_LCD1602_BOOCK_Data(unsigned char Date)

* 功能  ：写数据

* 输入数据：无

* 输出数据：     无

* 被调用函数  ： Write_LCD1602_BOOCK_Com_Data();

***************************************************************/

void Write_LCD1602_Data(unsigned char Date)

{

LCD1602_RS1;

LCD1602_RW0;

LCD1602_EN0;

GPIOD->ODR = Date;

Delay_us(340);

LCD1602_EN1;

Delay_us(340);

LCD1602_EN0;

}

void LCD_Write(int x,int y,char ch)
{
	if(x==0)
	{
	Write_LCD1602_Com(0x80+y);
	Write_LCD1602_Data(ch);
	}
	else
	{
	Write_LCD1602_Com(0xc0+y);
	Write_LCD1602_Data(ch);
	}
}

/**************************************************************

* 函数名：Init_LCD1602(void)

* 功能  ：指令初始化

* 输入数据：无

* 输出数据：     无

* 被调用函数  ： main()；

***************************************************************/

void Init_LCD1602(void)

{

Write_LCD1602_Com(0x38);

Delay_us(6);

Write_LCD1602_Com(0x0C);

Delay_us(6);

Write_LCD1602_Com(0x06);

Delay_us(6);

Write_LCD1602_Com(0x01);

Delay_us(6);

}
