/*
 * timer0_ctc.c
 *
 * Created: 06-12-2021 08:38:09
 * Author : aksha
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB=~0;
	TCCR0=(1<<WGM01)|(1<<CS00)|(1<<CS02)|(1<<COM00);
	OCR0=100;
    while (1) 
    {
		
    }
}

