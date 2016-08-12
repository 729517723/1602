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

* ��������GPIO_InitStructReadtempCmd(void)

* ����  ������GPIO���

* �������ݣ���

* ������ݣ�     ��

* �����ú���  �� main()��

***************************************************************/

void GPIO_InitStructReadtempCmd(void)

{

GPIOE->CRL = 0x33333333;

GPIOE->CRH = 0x33333333;

GPIOD->CRL = 0x33333333;

}

/**************************************************************

* ��������RCC_APB2PeriphReadtempyCom(void)

* ����  ����������ʱ��

* �������ݣ���

* ������ݣ�     ��

* �����ú���  �� main()��

***************************************************************/

void RCC_APB2PeriphReadtempyCmd(void)

{

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

}

/**************************************************************

* ��������Wrint_LCD1602_BOOCK_Com(unsigned char Com)

* ����  ��дָ��

* �������ݣ���

* ������ݣ�     ��

* �����ú���  �� Write_LCD1602_BOOCK_Com_Data();

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

* ��������Write_LCD1602_BOOCK_Data(unsigned char Date)

* ����  ��д����

* �������ݣ���

* ������ݣ�     ��

* �����ú���  �� Write_LCD1602_BOOCK_Com_Data();

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

* ��������Init_LCD1602(void)

* ����  ��ָ���ʼ��

* �������ݣ���

* ������ݣ�     ��

* �����ú���  �� main()��

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
