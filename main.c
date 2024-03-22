#include "mcc_generated_files/system.h"
#include <stdbool.h>
#include "buttons.h"
#include "led.h"
#include "fsm.h"

void main(void)
{
    SYSTEM_Initialize();
    STATE_T state = INIT;
    
    while (1)
    {
        switch(state){
            case INIT:          {
                                Init_buttons(); 
                                state = IDLE;
                                break;
                                }
            
            case IDLE:          {
                                Idle_blink();
                                state = start_game ? PREPARE_ROUND : IDLE;
                                break;
                                }
            
            case PREPARE_ROUND: {
                                Leds_off();
                                Wait();
                                Idle_blink();
                                Generate_pattern();
                                input_counter = 0;
                                state = BLINK;
                                Wait();
                                break;
                                }
            
            case BLINK:         {
                                Blink_pattern();
                                state = PLAYER_INPUT;
                                break;
                                }
            
            case PLAYER_INPUT:  {
                                if(input_detected){

                                    incorrect_input = led_pattern[input_counter] != pressed ? 1 : 0;
                                    
                                    if(incorrect_input || end_game){
                                        state = GAME_OVER;
                                    } else{
                                        if(input_counter == pattern_length - 1){
                                            state = PREPARE_ROUND;
                                        } else {
                                            input_counter += 1;
                                            state = PLAYER_INPUT;
                                    }
        
                                    }
                                
                                    input_detected = 0;
                                } else{
                                    state = PLAYER_INPUT;
                                }
                                
                                break;
                                }
            
            case GAME_OVER:     {
                                Game_over_blink();
                                start_game = 0;
                                end_game = 0;
                                incorrect_input = 0;
                                input_detected = 0;
                                pattern_length = 0;
                                input_counter = 0;
                                state = IDLE;
                                break;
                                }
        }
        
    }
}

