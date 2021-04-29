#include "activity4.h"

void send_temp_value(int set_temp_value)
{
    if(set_temp_value >=0 && set_temp_value<200)
        send_temperature(20);
    else if(set_temp_value >=201 && set_temp_value<500)
        send_temperature(25);
    else if(set_temp_value >=501 && set_temp_value<700)
        send_temperature(29);
    else if(set_temp_value >=701 && set_temp_value<1024)
        send_temperature(33);
}
void init_communication()
{
    UBRR0H = (BAUD_RATE >> 8);
    UBRR0L = BAUD_RATE ;
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
    UCSR0B |= (1<<TXEN0);
}

void write_char(char c)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0 = c;
}

void send_temperature(int temp)
{
    char str[5];
    itoa(temp,str,10);
    uint8_t i=0;
    char tempa[]="Temperature : ";
    for(i=0; tempa[i] != '\0'; i++)
    {
        write_char(tempa[i]);
    }
    for(i=0; str[i] != '\0'; i++)
    {
        write_char(str[i]);
    }
}