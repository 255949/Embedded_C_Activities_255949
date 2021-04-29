#ifndef _ACTIVITY3_H_
#define _ACTIVITY3_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Defining macros for the different Duty cycles to be used
 * depending on the setvalue read by the ADC
 */
#define LOW 20
#define MEDIUM 40
#define HIGH 70
#define VERY_HIGH 95

/**
 * @brief Variable for storing duty cycle
 * 
 */
int duty_cycle;

/**
 * @brief Checks the ADC value received and calls setduty function
 * depending on the range of ADC value
 */
void set_heating_temperature(int);

/**
 * @brief Sets the duty cycle and calls setup_pwm function
 * 
 */
void setduty(int);

/**
 * @brief Function deals with the registers involved for setting up
 * the PWM to work in the desired way
 */
void setup_pwm();

/**
 * @brief Continuously generates the output PWM signal based on the duty cycle
 * 
 */
void generate_signal();

#endif