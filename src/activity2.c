#include "activity2.h"

int readValues()
{
    setupAdc();
    return setValue;
}
void setupAdc()
{
    ADMUX = (1<<REFS0) | (1 << MUX0) | (1 << MUX2);
    ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
    startConversion();
}

void startConversion()
{
    ADCSRA |= (1 << ADSC);
    while(!(ADCSRA & (1<<ADIF)))
    ADCSRA|=(1<<ADIF);
    setValue=ADC;
}