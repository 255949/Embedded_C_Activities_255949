/**
 * @file SeatHeatingApp.c
 * @author Ayushman Ranu
 * @brief The main function has been simplified to include only the functions required 
 * for setting up the required registers and actions
 * The check_buttonstate function checks for the required parameters before starting ADC conversion or
 * PWM generation. It waits till both buttons are ON, signifying the presence of a person on
 * the seat, and the heating button turned ON.
 * The readValues function sets up all the functions required for the ADC conversion and stores
 * the final value after the ADC conversion is complete into set_temp_value
 * The set_heating_temperature function sets up the PWM registers based on the value of ADC
 * The init_communication function sets up the functions required for sending the set Temperature
 * value through Serial Communication
 * The generate_signal function finally generates the PWM output to the desired pin
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

int main()
{
    check_buttonstate();
    int set_temp_value= readValues();
    set_heating_temperature(set_temp_value);
    init_communication();
    send_temp_value(set_temp_value);
    generate_signal();
}