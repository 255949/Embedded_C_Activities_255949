#include <avr/io.h>
#include "activity1.h"

button_state check_status()
{
    DDRB|= (1<<PB0);
    PORTB|=(1<<PB2) | (1<<PB1);
    if(!(PINB&(1<<PB2)))
    {
        if(!(PINB&(1<<PB1)))
        {
            PORTB|=(1<<PB0);
            return BOTH_ON;
        }
        else
        {
            PORTB&=~(1<<PB0);
            return ONE_ON;
        }
    }
    else
    {
         PORTB&=~(1<<PB0);
         return BOTH_OFF;
    }
}