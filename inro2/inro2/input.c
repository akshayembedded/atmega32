/*
 * input.c
 *
 * Created: 24-11-2021 09:05:53
 *  Author: aksha
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	char i=0;
	DDRA=0xff;
	DDRC=0x00;
	while((PINC&(1<<0))==0);	
	while (1)
	{
		if((PINC&(1<<0))==(1<<0))// 0000 1000<<0
		{
			
			
			i++;
		while((PINC&(1<<0))==(1<<0));	
		}
		if(i%3==0)
		{
			PORTA=0xff;
		}
		else if(i%3==1)
		{
			PORTA=0x00;
		}
		else 
		{
			PORTA=0x00;
			_delay_ms(1000);
			PORTA=0xff;
			_delay_ms(1000);
		}
		
	}
}

