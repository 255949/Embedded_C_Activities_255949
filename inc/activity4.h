/**
 * @file activity4.h
 * @author Ayushman Ranu
 * @brief  Header file with function definitions for Activity 4 - Sending value of set
 *  temperature by UART Protocol
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY4_H_
#define _ACTIVITY4_H_
#include <avr/io.h>
#include <stdlib.h>

/**
 * @brief Prior calculation for setting baud rate to 9600
 * 
 */
#define BAUD_RATE 103

/**
 * @brief Checks the value from ADC and decides information to be sent
 * based on the value received
 */
void send_temp_value(int);

/**
 * @brief Sets up the regsters for Serial communication
 * 
 */
void init_communication();

/**
 * @brief Writes one character to UDR to be sent through Serial Communuication
 * 
 */
void write_char(char);

/**
 * @brief Converts the Temperature value to character and send each character
 * to write_char to be sent through Serial Communication one by one
 */
void send_temperature(int);

#endif