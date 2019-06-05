/*
 * attiny2313_console.c
 *
 * Created: 21.01.2018 14:40:41
 * Author:  sboldenko
 */ 

#define F_CPU 20000000UL // 20 MHz
#define B0    0

#include <avr/io.h>

void init_portb()
{
	PORTB = 0x00;
	DDRB = 0x01; // B0 - out
}

void init_timer0()
{
	TCCR0B |= (1 << CS02)|~(1 << CS01)|(1 << CS00); // div = 1024
	TCNT0 = 0x00;
}

int main(void)
{	
	init_portb();
	init_timer0();
	
    while(1)
    {
        if (TCNT0 <= 127)
        {
	        PORTB |= (1 << B0);
        }
        else
        {
	        PORTB &= ~(1 << B0);
        }
    }
}