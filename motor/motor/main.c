/*
 * motor.c
 *
 * Created: 26-11-2021 08:21:08
 * Author : SMEC
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
   DDRC&=~(1<<0);//push button
   DDRC|=0x06;//DDRC|=((1<<1)|(1<<2)); motor
   DDRC|=((1<<3)|(1<<4));//lcd rs & e
   DDRD=0xff;
   PORTD=0x00;
   PORTC=0x00;
   cmd(0x38);
   cmd(0x01);
   cmd(0x0C);
   
    while (1) 
    {
		cmd(0x80);
		if((PINC&(1<<0))==(1<<0))
		{
			PORTC|=(1<<1);
			PORTC&=~(1<<2);
			display("Clockwise      ");
		}
		else
		{
			PORTC|=(1<<2);
			PORTC&=~(1<<1);
			display("Anti-clockwise");
		}
    }
}

