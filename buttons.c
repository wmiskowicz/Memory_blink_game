#include "xc.h"
#include "mcc_generated_files/tmr3.h"
#include "mcc_generated_files/pin_manager.h"
#include "buttons.h"
#include "led.h"
#include "fsm.h"

LED_T pressed = 0;
bool end_of_pattern = 0;
bool incorrect_input = 0;
bool start_game = 0;
bool end_game = 0;
bool input_detected = 0;
int16_t input_counter = 0;


void debounce_delay (){
    TMR3_Start();
    while(TMR3_Counter16BitGet() < 0x1500);
    TMR3_Stop();
    TMR3_Counter16BitSet(0);
}

void button_debounce(){
    debounce_delay();
    while(_RB0 + _RB1 + _RA0 + _RA1 < 4);
    debounce_delay();
    input_detected = 1;
}

void ISR_button_RED(void){
    LED_RED_SetLow();
    button_debounce();
    pressed = RED;
    Leds_off();
    
}

void ISR_button_YELLOW(void){
    LED_YELLOW_SetLow();
    button_debounce();
    pressed = YELLOW;
    Leds_off();
}

void ISR_button_GREEN(void){
    LED_GREEN_SetLow();
    button_debounce();
    pressed = GREEN;
    Leds_off();
}

void ISR_button_BLUE(void){
    LED_BLUE_SetLow();
    button_debounce();
    pressed = BLUE;
    Leds_off();
}

void ISR_button_start(void){
    start_game = 1;
    srand(TMR3_Counter16BitGet());
}

void ISR_button_end(void){
    end_game = 1;
    input_detected = 1;
}

void Init_buttons(void){
    BUTTON_RED_SetInterruptHandler(ISR_button_RED);
    BUTTON_YELLOW_SetInterruptHandler(ISR_button_YELLOW);
    BUTTON_GREEN_SetInterruptHandler(ISR_button_GREEN);
    BUTTON_BLUE_SetInterruptHandler(ISR_button_BLUE);
    START_GAME_SetInterruptHandler(ISR_button_start);
    STOP_GAME_SetInterruptHandler(ISR_button_end);
}