/*
 * inro2.c
 *
 * Created: 24-11-2021 08:34:31
 * Author : aksha
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
    DDRA=0xff;
    while (1) 
    {
		for (int i=7;i>=0;i--)
		{
			PORTA=1<<i;
			_delay_ms(1000);
		}
		
    }
}

