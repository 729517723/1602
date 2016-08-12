#include "stm32f10x.h"
#include "LCD1602.h"

int main(void)

{

	char ch[]={'T','e','m','p',':','0','1','2','3','4','5','6','7','8','9'};
	//char num[]={'0','1','2','3','4','5','6','7','8','9'};
	char num[]={'0','1','2','3','4','5','6','7','8','9'};
	int i;
	RCC_APB2PeriphReadtempyCmd();
	
	GPIO_InitStructReadtempCmd();
	
	Init_LCD1602();
	
	while(1)
	{
		for(i=0;i<15;i++)
		{
			LCD_Write(0,i,ch[i])  ;
			Delay_us(340);
		} 

		for(i=9;i>=0;i--)
		{
			LCD_Write(1,9-i,num[i])  ;
			Delay_us(340);
		}
		Delay_us(5000);
	}

}
