#ifndef _ACTIVITY2_H
#define _ACTIVITY2_H

#include <avr/io.h>
#include <avr/interrupt.h>

int setValue;

int readValues();

void setupAdc();

void startConversion();

#endif