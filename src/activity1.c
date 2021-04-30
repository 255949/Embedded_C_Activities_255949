#include <avr/io.h>
#include "activity1.h"


void check_buttonstate()
{
    while(1) 
    {
        button_state current_status=check_status();
        if(current_status==BOTH_ON)
        break;                                              //Loop runs till status is BOTH_ON
    }
}
button_state check_status()
{
    DDRB|= (1<<PB0);                                        // Setup B0 as an Output
    PORTB|=(1<<PB2) | (1<<PB1);                             // Set Internal Pullups for B1 and B2
    if(!(PINB&(1<<PB2)))                                    // Check Input from button connected to B2
    {
        if(!(PINB&(1<<PB1)))                                // Check Input from button connected to B1
        {
            PORTB|=(1<<PB0);                                // Turn on LED
            return BOTH_ON;                                 // Return Value to terminate loop 
        }
        else
        {
            PORTB&=~(1<<PB0);                               // Turn off LED
            return ONE_ON;
        }
    }
    else
    {
         PORTB&=~(1<<PB0);                                  // Turn off LED
         return BOTH_OFF;
    }
}