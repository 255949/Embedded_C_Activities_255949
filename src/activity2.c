#include "activity2.h"

int readValues()
{
    setupAdc();                                                                         
    return setValue;                                                                    // Return final value of ADC
}
void setupAdc()
{
    ADMUX = (1<<REFS0) | (1 << MUX0) | (1 << MUX2);                                     // Setup Reference voltage to 5V and ADC5 to be used
    ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);    // Enables ADC, ADC Interrupt and sets division factor to 128
    startConversion();
}

void startConversion()
{
    ADCSRA |= (1 << ADSC);                                                              // Starts ADC Conversion
    while(!(ADCSRA & (1<<ADIF)))                                                        // Wait for ADC conversion completion
    ADCSRA|=(1<<ADIF);                                                                  // Clear ADIF by writing 1 to it
    setValue=ADC;
}