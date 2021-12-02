/*
 * uart.c
 *
 * Created: 02-12-2021 08:35:23
 * Author : aksha
 */ 

#include <avr/io.h>


int main(void)
{
	UCSRC=0x86;
	UCSRA=0;
	UCSRB=(1<<RXEN)|(1<<TXEN);
	UBRRL=51;
	UBRRH=0;
	
	
    /* Replace with your application code */
    while (1) 
    {
		char a;
		while((UCSRA&(1<<RXC))==0);
		a=UDR;
		while((UCSRA&(1<<UDRE))==0);
		UDR=a;
    }
}

