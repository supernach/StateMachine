#ifndef STATEMACHINE_H
#define STATEMACHINE_H

//#define USING_C_STANDARD 0

#ifndef USING_C_STANDARD 
#include <stm8s.h>
#else
#include <stdint.h>
#endif

#include <stdlib.h>
#include <utils.h>


#include <statemachineconfig.h>
#include <statemachinevalues.h>



typedef struct StateMachine StateMachine_t;
typedef void ( *Run_fPtr )( StateMachine_t* );


struct StateMachine
{
	StateMachineConfig_t* Config;
	StateMachineValues_t Actual;
	Run_fPtr Run;
};


void StateMachine_Init( StateMachine_t* mFsm,  StateMachineConfig_t* mConfig, uint8_t mInitState );
void StateMachine_Run( StateMachine_t* mFsm );




#endif