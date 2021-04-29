#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

int main()
{
    check_buttonstate();
    int set_temp_value= readValues();
    set_heating_temperature(set_temp_value);
    init_communication();
    send_temp_value(set_temp_value);
    generate_signal();
}