#define F_CPU 1.2E6
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
 unsigned char LOOKUPTB[] = { 0b00111111, 0b00000110,
 0b01011011, 0b01001111,
 0b01100110, 0b01101101,
 0b01111101, 0b00000111,
 0b01111111, 0b01101111,
 0b01110111, 0b01111100,
 0b00111001, 0b01011110,
 0b01111001, 0b01110001 };

 unsigned char DISPLY, SWITCH_V,COUNTER,SW;
 DDRB = 0xFF; //port B = output
 DDRC = 0x00; //port C = input
 DDRD = 0x00;
 while(1)
 {
	 SW = PIND;
	 SW &= 0x0F;
	SWITCH_V = PINC;
	SWITCH_V &= 0x0F;
	if (SW == 0)
	{
		_delay_ms(2000);
		SW = PIND;
		SW &= 0x0F;
			for (int i =0 ; i<16 ; i++)
			{
				DISPLY = LOOKUPTB[i];
				
				PORTB = DISPLY^0xFF;
				_delay_ms(100);
			}
	}
	DISPLY = LOOKUPTB[SWITCH_V];
	PORTB = DISPLY^0xFF;
 }
 }