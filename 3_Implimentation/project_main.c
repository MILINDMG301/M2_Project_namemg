
#include "inc/Pot_ADC.h"


int main(void)
{		
		initADC();
		pwm_init();

	while (1);
	{
			uint16_t value = doConversion();

			set_OCR(value);
	}
}



