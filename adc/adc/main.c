
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

void dispnum(signed int i)
{
	signed int j=0;
	char a[5];
	do
	{
		a[j++]=(i%10+48);//526 i=52
		i=i/10;
	}while(i>0);
	for(j--;j>=0;j--)
	{
		data(a[j]);
	}
	display("   ");
	
}

int main(void)
{
	DDRD=~0;
	DDRC|=((1<<3)|(1<<4));
	DDRA=0;
	ADMUX=0;
	ADCSRA=0xC0;
	cmd(0x0f);
	cmd(0x38);
	cmd(0x01);
	
    while (1) 
    {
		_delay_ms(1);
		ADCSRA|=(1<<ADSC);
		while ((ADCSRA&(1<<ADIF))==0);
		cmd(0x80);
		dispnum((ADCH<<8)|ADCL);
	
    }
}
