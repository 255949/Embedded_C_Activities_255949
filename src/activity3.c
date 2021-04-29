#include "activity3.h"

void setHeatingTemperature(int value)
{
    duty_cycle=value;
    setup_pwm();
}

void setup_pwm()
{
    DDRD |= (1<<PD6);
    TCCR0A|= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);
	TIMSK0=(1<<TOIE0);
	TCCR0B|= (1<<CS01) | (1<<CS00);
}

void generate_signal()
{
    while(1)
    OCR0A=(duty_cycle/100.0)*255;
}