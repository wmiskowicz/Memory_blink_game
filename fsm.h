/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef FSM_H
#define	FSM_H

#include <xc.h>  

typedef enum state {INIT, IDLE, PREPARE_ROUND, BLINK, PLAYER_INPUT, GAME_OVER} STATE_T;
extern STATE_T state;

#endif

