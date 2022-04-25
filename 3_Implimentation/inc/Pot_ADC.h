#ifndef __POT_ADC_H_
#define __POT_ADC_H_
/**
 * @file Pot_ADC.h
 * @author Milind.G ()
 * @brief Project to control an servo motor connected to AVR328 MCU GPIO Pin using potentiometer
 * @version 0.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define F_CPU 16000000   /**< CPU frequency = 16MHz */

/**
 * Include files
 */ 
#ifndef __AVR_ATmega328__
	#define __AVR_ATmega328__
#endif
#include <avr/io.h>
#include <util/delay.h>
/**
 * Function Definitions
 */

/**
 * @brief initialize the ADC Pins and registers 
 * 
 */
void initADC();


/**
 * @brief convert the value read by the ADC Pin 
 * 
 */
uint16_t doConversion(void);

/**
 * @brief initialize the pwm Pins and registers
 * 
 */
void pwm_init(void);

/**
 * @brief Set the value of the output Pin according to the value read by the ADC input
 * 
 * @param state value for which the output value should be set.
 */
void set_OCR(uint16_t value1);

#endif /** __POT_ADC_H_ */