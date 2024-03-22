/*
 * File:   led.c
 * Author: Radoslaw Wilinski
 *
 * Last revision on January 26, 2024, 8:30 PM
 */


#include "xc.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/pin_manager.h"
#include "buttons.h"
#include "led.h"

int16_t pattern_length = 0;
LED_T   led_pattern[100] = {0};

void Wait(void){
    TMR2_Start();
    while(TMR2_Counter16BitGet() < TMR2_Period16BitGet());
    TMR2_Stop();
    TMR2_Counter16BitSet(0);
}

void Leds_off(void){
    LED_RED_SetHigh();
    LED_YELLOW_SetHigh();
    LED_GREEN_SetHigh();
    LED_BLUE_SetHigh();
}

void Blink(LED_T led){
    Leds_off();
    switch(led){
        case RED:    LED_RED_SetLow();    break; 
        case YELLOW: LED_YELLOW_SetLow(); break;
        case GREEN:  LED_GREEN_SetLow();  break;
        case BLUE:   LED_BLUE_SetLow();   break;
        case NONE:   break;
    }
    Wait();
    Leds_off();
}


void Idle_blink(void){
    Leds_off();
    LED_YELLOW_SetLow();
    LED_GREEN_SetLow();
    Wait();
    Leds_off();
    LED_RED_SetLow();
    LED_BLUE_SetLow();
    Wait();
    Leds_off();
}

void Game_over_blink(void){
    for(int i = 0; i < 4; i++){
        Leds_off();
        LED_RED_SetLow();
        LED_YELLOW_SetLow();
        LED_GREEN_SetLow();
        LED_BLUE_SetLow();
        Wait();
        Leds_off();
        Wait();
        Leds_off();
    }
}

void Blink_pattern(void){
    for(int i = 0; i <= pattern_length - 1; i++){
        Wait();
        Blink(led_pattern[i]);
    }

}

void Generate_pattern(){
    pattern_length += 1;
    
    for(int i = 0; i <= pattern_length - 1; i++){
        led_pattern[i] = (rand() % 4 + 1);   
    }
}
