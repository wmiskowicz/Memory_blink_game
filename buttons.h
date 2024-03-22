#ifndef BUTTONS_H
#define	BUTTONS_H

#include <xc.h> 
#include "led.h"

extern bool     incorrect_input;
extern bool     start_game;
extern bool     end_game;
extern bool     input_detected;
extern bool     end_of_pattern;
extern int16_t  input_counter;
extern LED_T    pressed;

void Init_buttons(void);

#endif