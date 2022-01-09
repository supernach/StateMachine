#ifndef STATEMACHINEVALUES_H
#define STATEMACHINEVALUES_H


/**
*
* @brief Definicion de los 3 puntos de entrada de un estado
*
*
*
*/
typedef enum
{
	ENTRY,
	RUN,
	EXIT
}StatesPoint_t;

/**
*
* @brief Valores actuales usados en la maquina de estado para
* 			 llevar el tracking de su estado. Tanto el estado actual
*				 como el punto de entrada donde se encuentra el estado
*
*
*
*/
typedef struct
{
	uint8_t CurrentState;
	uint8_t CurrentStatePoint; // Almacena si el estado esta en entry, run o exit
	uint8_t ResultCode; 			 // Almacena el resultado de ejecucion de run
	uint8_t InitState;
}StateMachineValues_t;




#endif
