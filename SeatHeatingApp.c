#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"

int main()
{
    while(1)
    {
        button_state current_status=check_status();
        if(current_status==BOTH_ON)
        break;
    }
    int set_temp_value= readValues();
    if(set_temp_value >=0 && set_temp_value<200)
        setHeatingTemperature(LOW);
    else if(set_temp_value >=201 && set_temp_value<500)
        setHeatingTemperature(MEDIUM);
    else if(set_temp_value >=501 && set_temp_value<700)
        setHeatingTemperature(HIGH);
    else if(set_temp_value >=701 && set_temp_value<1024)
        setHeatingTemperature(VERY_HIGH);
    generate_signal();
}