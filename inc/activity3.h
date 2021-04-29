#ifndef _ACTIVITY3_H_
#define _ACTIVITY3_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define LOW 20
#define MEDIUM 40
#define HIGH 70
#define VERY_HIGH 95

int duty_cycle;
void set_heating_temperature(int);
void setduty(int);
void setup_pwm();
void generate_signal();

#endif