/*
 * keypad.c
 *
 * Created: 29-11-2021 08:18:32
 * Author : aksha
 */ 

#include <avr/io.h>
#define F_CPU 80000000UL
#include <util/delay.h>
void cmd(char a)
{
	PORTC&=~(1<<3);
	PORTD=a;
	PORTC|=(1<<4);
	_delay_ms(3);
	PORTC&=~(1<<4);
}
void data(char a)
{
	PORTC|=(1<<3);
	PORTD=a;
	PORTC|=(1<<4);
	_delay_ms(3);
	PORTC&=~(1<<4);
	while((PINB&0x0f)!=0x0f);
}
void display(const char *p)
{
	while(*p)
	{
		data(*p++);
	}
}


int main(void)
{
	DDRD=~0;
	DDRC|=((1<<3)|(1<<4));
	DDRB=0xf0;
	PORTB=0x0f;//
	cmd(0x01);
	cmd(0x38);
	cmd(0x0f);
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB=0xef;
		switch(PINB&0x0f)
		{
			case 0x0e: data('0'); break;
			case 0x0D: data('1'); break;
			case 0x0B: data('2'); break;
			case 0x07: data('3'); break;
		}
		PORTB=0xDf;
		switch(PINB&0x0f)
		{
			case 0x0e: data('4'); break;
			case 0x0D: data('5'); break;
			case 0x0B: data('6'); break;
			case 0x07: data('7'); break;
		}
		PORTB=0xbf;
		switch(PINB&0x0f)
		{
			case 0x0e: data('8'); break;
			case 0x0D: data('9'); break;
			case 0x0B: data('A'); break;
			case 0x07: data('B'); break;
		}
		PORTB=0x7f;
		switch(PINB&0x0f)
		{
			case 0x0e: data('C'); break;
			case 0x0D: data('D'); break;
			case 0x0B: data('E'); break;
			case 0x07: data('F'); break;
		}
	}
}

