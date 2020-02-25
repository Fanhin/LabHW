/*
 * AVRGCC2.c
 *
 * Created: 18-Mar-19 14:28:30
 *  Author: HW
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0x00;
	DDRD=0x00;
	DDRB=0xFF;
	unsigned char SWITCH_V,DISP, RST, COUNTER, is_press, I;
	unsigned char LOOKUPTB[]={ 0b00111111,
							   0b00000110,
							   0b01011011,
							   0b01001111,
							   0b01100110,
							   0b01101101,
							   0b01111101,
							   0b00000111,
							   0b01111111,
							   0b01101111,
							   0b01110111,
							   0b01111100,
							   0b00111001,
							   0b01011110,
							   0b01111001,
							   0b01110001};
    while(1)
    {
		RST = PIND;
		COUNTER = 0x00;
		RST &= 0x01;
		SWITCH_V = PINC;
		SWITCH_V &= 0x0F;
		is_press = 1;
		I = 0;
		while(I < 20)
		{	
			_delay_ms(100);
			RST = PIND;
			RST &= 0x01;
			if(RST == 1){
				is_press = 0;
				break;
			}
			else 
				I++;
		}
		
		if(is_press == 1){
			while (COUNTER <16){
			DISP = LOOKUPTB[COUNTER];
			PORTB = DISP;
			COUNTER++;
			_delay_ms(100);
			}				
		}
		DISP = LOOKUPTB[SWITCH_V];
		PORTB = DISP;
    }
}

