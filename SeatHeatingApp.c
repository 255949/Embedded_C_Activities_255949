#include <avr/io.h>
//#include <util/delay.h>
#include "activity1.h"

int main()
{
    while(1)
    {
        button_state a=check_status();
        if(a==BOTH_ON)
        break;
    }
}