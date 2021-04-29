#ifndef _ACTIVITY1_H
#define _ACTIVITY1_H
#define BUTTON_PORT (DDRB)

#include <avr/io.h>

/**
 * @brief Enum to reflect current state of buttons
 * BOTH_ON refers to a person present on the seat and the heat button ON
 * ONE_ON refers to the fact that only one condition is met
 * BOTH_OFF means that none of the conditions are met
 */
typedef enum button_state
{
    BOTH_ON=0,
    ONE_ON=1,
    BOTH_OFF=2
}button_state;

/**
 * @brief Function waits for favourable condition for starting adc conversion
 * when a person is present on the seat and heat button is switched on
 */
void check_buttonstate();

/**
 * @brief The function deals with the registers involved with checking the status of
 * the switches
 * @return button_state The function returns BOTH_ON, ONE_ON, or BOTH_OFF
 * depending on the switch status
 */
button_state check_status();

#endif