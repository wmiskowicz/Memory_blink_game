#ifndef LED_H
#define	LED_H

#include <xc.h> 

typedef enum led{
        NONE,
        RED,
        YELLOW, 
        GREEN, 
        BLUE
} LED_T;

extern LED_T   current_led;
extern int16_t pattern_length;
extern LED_T   led_pattern[100];

void Wait(void);
void Leds_off(void);
void Idle_blink(void);
void Game_over_blink(void);
void Blink_pattern(void);
void Generate_pattern(void);


#endif	

