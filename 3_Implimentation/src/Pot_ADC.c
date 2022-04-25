#include "Pot_ADC.h"
void initADC(void) {
	// Configure the ADC module
	ADMUX = 0b11000010; //Set channel 2
	ADCSRA = 0b10000111;
}

uint16_t doConversion(void){
	uint16_t result;
	// Start conversion by setting flag ADSC
	ADCSRA |= (1 << ADSC);
	// Wait until conversion is  completed
	while(ADCSRA & (1 << ADSC));
	// Read the all bits, output to PORTB
	result= ADC;
	return result;
}

void pwm_init(void){

    DDRD = 0b11111111;
		PORTD |= (1 << DDD6);
		// PD6 is now an output

		TCCR0A |= (1 << COM0A1);
		// set none-inverting mode

		TCCR0A |= (1 << WGM01) | (1 << WGM00);
		// set fast PWM Mode

		TCCR0B |= (1 << CS01) | (1 << CS00);
		// set pre-scaler to 8 and starts PWM
}

void set_OCR(uint16_t value1){

    if(value1 <= 255){
				OCR0A = 1;
				
				// set PWM for 50% duty cycle at 128 OCR0A

				}else if(value1 > 255 && value1<=650){
				OCR0A = 100;

				}else if(value1 > 650 && value1<=1024){
				OCR0A = 180;

			}
}