#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRC=0xFF;
	DDRD=0xFE;
	DDRB=0xFF;
	unsigned char SWITCH, state, TEMP1, TEMP2, i, DISP;
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
	state = 0;
							   
    while(1){
		SWITCH = PIND;
		SWITCH &= 0x01;
		
		if(SWITCH == 0){
			//_delay_ms(1000);
			state = 1;
			
		}
		
		while(state){
			TEMP1 = 0b00000010;
			PORTD = TEMP1;
			TEMP1 = 0b01011100;
			PORTB = TEMP1;
			TEMP2 = 0b01010100;
			PORTC = TEMP2;
			_delay_ms(1000);
			TEMP1 = 0b00000000;
			PORTB = TEMP1;
			PORTC = TEMP1;
			_delay_ms(1000);
			SWITCH = PIND;
			SWITCH &= 0x01;
			if(SWITCH == 0){
				//_delay_ms(1000);
				state = 0;
				TEMP1 = 2;
				TEMP2 = 1;
				i = 0;
				while(i < 20){
					TEMP2--;
					DISP = LOOKUPTB[TEMP1];
					PORTB = DISP;
					DISP = LOOKUPTB[TEMP2];
					PORTC = DISP;
					if(TEMP2 == 0){
						TEMP2 = 10;
						TEMP1--;
					}					
					
					i++;
					_delay_ms(1000);
				}			
				TEMP1 = 0b00000000;
				PORTD = TEMP1;
			}
		}
		
		TEMP1 = 0b01011100;
		PORTB = TEMP1;
		TEMP2 = 0b01110001;
		PORTC = TEMP2;
		_delay_ms(1000);
		TEMP1 = 0b00000000;
		PORTB = TEMP1;
		PORTC = TEMP1;
		_delay_ms(1000);
		
		/*	
		if(SWITCH == 0x01){
			PORTB = 0b01011100;
			PORTC = 0b01110001;
			_delay_ms(1000);
			PORTB = 0b00000000;
			PORTC = 0b00000000;
			_delay_ms(1000);;
		}
		else if(SWITCH == 0x00){
			PORTD = 0x02;
			PORTB = 0b01011100;
			PORTC = 0b01010100;
			_delay_ms(1000);
			PORTB = 0b00000000;
			PORTC = 0b00000000;
			_delay_ms(1000);
			
		}
		*/
	
		
		//DISP = LOOKUPTB[SWITCH_V];
		//PORTB = DISP;
				
        //TODO:: Please write your application code 
			}    
}