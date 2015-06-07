#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<rakesh/tiny13dbg.h>

#define TSOP_PIN 4
#define LED_PIN	 3

#define PREMBLE			154

unsigned int pulseWidth(uint8_t HL);
uint16_t getMessage();
void blink();
unsigned int waitFor(uint8_t HL);
uint16_t receivedMessage();

int main(void){
	uint16_t message;
	DDRB=(1<<pin)|(1<<LED_PIN);	
	send('\n');
	
	
	blink();
	
	
	while(1){
		//printInt(pulseWidth(0));
		//blink();
		message=getMessage();
		printHex((unsigned char)(message>>8));
		printHex((unsigned char)message);
		send('\n');
	 }
	return 0;
}

void blink(){
	PORTB|=(1<<LED_PIN);
	_delay_us(1500);
	PORTB&=~(1<<LED_PIN);
}

uint16_t getMessage(){
	waitFor(0);
	waitFor(1);
	uint8_t i[33];
	uint8_t j=0;
	uint32_t result=0;
	i[0]=pulseWidth(1);
	if(i[0]>=PREMBLE){
		for(j=1;j<=32;j++){
			i[j]=pulseWidth(1);
		}
		for(j=32;j>=1;j--){
			result=result<<1;
			result|=(((i[j])>i[0]/4)?1:0);
		}
		return (uint16_t)((0x00ff0000&result)>>8)|(0x000000ff&result);
	}
	else return 0;
}
unsigned int waitFor(uint8_t HL){
unsigned int i=0;
	while(HL?(!(PINB&(1<<TSOP_PIN))):(PINB&(1<<TSOP_PIN))){
		_delay_us(1);
		i++;
	}
	return i;
}

unsigned int pulseWidth(uint8_t HL){
			HL?waitFor(1):waitFor(0);
	return	HL?waitFor(0):waitFor(1);
}