/*
 * timer_normalmode.c
 *
 * Created: 03-12-2021 08:34:30
 * Author : aksha
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	int x=3;
	TCCR0=(1<<CS00)|(1<<CS02)|(1<<COM00);
	DDRB=~0;
	
    /* Replace with your application code */
    while (1) 
    {
	
    }
}

