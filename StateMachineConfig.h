#ifndef STATEMACHINECONFIG_H
#define STATEMACHINECONFIG_H

#ifndef USING_C_STANDARD 
#include <stm8s.h>
#else
#include <stdint.h>
#endif

//#include <stdint.h>


typedef struct
{
	uint8_t NewState;
}StateMachineTransitionRule_t;
/**
*
* @brief Estructura que tiene cada estado. Se define el
*				 nombre del estado( definido por la maquina de estados ),
*				 y los 3 puntos de entrada del estado:
*				 EntryFunction: Ordenes a ejecutar al entrar en el estado
*			   RunFunction: Acciones a realizar en el estado
*				 ExitFunction: Ordenes a ejecutar al salir del estado
*
*
*/
typedef struct
{
	const uint8_t State;
	
	const StateMachineTransitionRule_t* TransitionRules;
	
	void ( *EntryFunction )( void* data );
	uint8_t ( *RunFunction )( void* data );
	void ( *ExitFunction )( void* data );
}StateMachineConfig_t;







#endif