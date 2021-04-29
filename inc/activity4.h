#ifndef _ACTIVITY4_H_
#define _ACTIVITY4_H_
#include <avr/io.h>
#include <stdlib.h>
//#define F_CPU 16000000UL
//#define BAUD 9600
//#define BAUD_RATE ((F_CPU/BAUD * 16UL)-1)
#define BAUD_RATE 103
void send_temp_value(int);
void init_communication();
void write_char(char);
void send_temperature(int);

#endif