// Blink Test
#included <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/18F4520ptr.h"

#INT_EXT
void int_ext_isr(){
	*PORT^=0X80;
}

#INT_EXT1
void int_ext_isr(){
}

#INT_EXT2
void int_ext_isr(){
}

main(){
	*ADCON1 = 0x0f;
	*TRISB = 0x01; // B0 Input
	INTCON -> GIE = 1;
	INTCON -> PEIE = 1;
	INTCON -> INT0IE = 1;
	
	while(1){
		*PORTB ^= 0x40;
		delay_ms(300);
		}
}

b