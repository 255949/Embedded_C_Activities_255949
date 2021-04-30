#include "activity4.h"

void send_temp_value(int set_temp_value)                    // Function to set temperature to be displayed
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
    UBRR0H = (BAUD_RATE >> 8);                              // First 8 bits of Baudrate shifted
    UBRR0L = BAUD_RATE ;                                    // Rest of Baudrate shifted
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);                    // Setup of asynchronous mode
    UCSR0B |= (1<<TXEN0);                                   // Enable transmitter
}

void write_char(char c)
{
    while(!(UCSR0A & (1<<UDRE0)))                           // Wait for transmission
    {

    }
    UDR0 = c;                                               // Write data to UDR0 one character at a time
}

void send_temperature(int temp)
{
    char str[5];                                            // String to store converted integer value
    itoa(temp,str,10);                                      // String to Int conversion (Decimal)
    uint8_t i=0;
    char tempa[]="Temperature : ";
    for(i=0; tempa[i] != '\0'; i++)                         // Loop to write "Temperature :" to Serial Monitor
    {
        write_char(tempa[i]);
    }
    for(i=0; str[i] != '\0'; i++)                           // Write the converted temperature value to Serial monitor
    {
        write_char(str[i]);
    }
}