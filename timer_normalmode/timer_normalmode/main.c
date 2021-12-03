/*
 * timer_normalmode.c
 *
 * Created: 03-12-2021 08:34:30
 * Author : aksha
 */ 

#include <avr/io.h>


int main(void)
{
	TCCR0=(1<<CS00)|(1<<CS02);
	DDRC=~0;
	
    /* Replace with your application code */
    while (1) 
    {
		
		PORTC=~PINC;
		while((TIFR&(1<<TOV0))==0);
		TIFR=1<<TOV0;
    }
}

