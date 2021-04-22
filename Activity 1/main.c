#include <avr/io.h>
#include<avr/delay.h>

/**
 * @brief Function for simulating a heating element switch for automobiles
 * Pin B0 connected to LED, which simulates turning ON or OFF the heating element
 * Pin B1 connected to a button which enables turning ON the heating element
 * Pin B2 connected to a button which simulates presence of a person on the seats
 * @return int 
 */
int main(void)
{
    DDRB=0x01;
    PORTB=0x06;
    while(1)
    {
        /* Condition checks for B2 input*/
        if(!(PINB & 0x04))
           {
               /*If B2 is pressed, condition checks for B1 input*/
               if(!(PINB & 0x02))
               {
                   /*Turn on LED at B0*/
                   PORTB |=0x01;
               }
               else
               {
                   /*Turn off LED at B0*/
                   PORTB &=0x06;
               }
           }
        else
        {
            /*Turn off LED at B0*/
            PORTB &=0x06;
        }
    }
    return 0;
}