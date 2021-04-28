#ifndef _ACTIVITY1_H
#define _ACTIVITY1_H
#define BUTTON_PORT (DDRB)

#include <avr/io.h>

typedef enum button_state
{
    BOTH_ON=0,
    ONE_ON=1,
    BOTH_OFF=2
}button_state;

button_state check_status();

#endif