#ifndef _ACTIVITY2_H
#define _ACTIVITY2_H

#include <avr/io.h>

/**
 * @brief Variable used for storing final ADC value
 * 
 */
int setValue;

/**
 * @brief Calls the setupADC function and once the conversion is done, returns
 * value of ADC to main function
 * @return int 
 */
int readValues();

/**
 * @brief Sets up the ADC to work in the specified modes and starts ADC conversion
 * once the setup is done
 */
void setupAdc();

/**
 * @brief Starts ADC conversion, waits for it to complete and then stores the final
 * value in setValue
 */
void startConversion();

#endif