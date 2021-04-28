#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"

int main()
{
    while(1)
    {
        button_state a=check_status();
        if(a==BOTH_ON)
        break;
    }
    int set_temp_value= readValues();
}