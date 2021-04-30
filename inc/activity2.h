/**
 * @file activity2.h
 * @author Ayushman Ranu
 * @brief Header file including function definitions for Activity 2 - Reading values
 *  from a potentiometer into the ADC
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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