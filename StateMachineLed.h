#ifndef STATEMACHINELED_H
#define STATEMACHINELED_H


#include <statemachine.h>
#include <gpio.h>


extern StateMachine_t FSM_Led;
extern Gpio_Config_t Led;


void FSM_LedInit( void );
//void FSM_LedRun( void );

uint8_t Init_Run( void* data );
uint8_t Blink100_Run( void* data );
uint8_t Blink300_Run( void* data );
uint8_t Blink500_Run( void* data );


#endif