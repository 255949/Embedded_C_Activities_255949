/**
 * @file activity3.c
 * @author Ayushman Ranu
 * @brief  Source code for activity 3 - Functions set up PWM in non-inverting mode
 *  and output the PWM to a pin based on ADC read value
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity3.h"

void set_heating_temperature(int value)                             // Function sets PWM value based on ADC input
{
    if(value >=0 && value<200)
        setduty(LOW);
    else if(value >=201 && value<500)
        setduty(MEDIUM);
    else if(value >=501 && value<700)
        setduty(HIGH);
    else if(value >=701 && value<1024)
        setduty(VERY_HIGH);
}
void setduty(int value)
{
    duty_cycle=value;
    setup_pwm();
}

void setup_pwm()                                                    
{
    DDRD |= (1<<PD6);                                               // Set D6 as output
    TCCR0A|= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);                 // Setup PWM with Non-inverted mode of operation
    TIMSK0=(1<<TOIE0);                                              // Enable overflow interrupt
    TCCR0B|= (1<<CS01) | (1<<CS00);                                 // Set 64 prescaler
}

void generate_signal()
{
    while(1)
    OCR0A=(duty_cycle/100.0)*255;                                   // Output PWM based on Duty Cycle to D6
}
