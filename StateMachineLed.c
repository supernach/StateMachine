#include <statemachineled.h>

const enum StateNames
{
	INIT,
	BLINK100,
	BLINK300,
	BLINK500
};

const enum ResultCodes
{
	CODE_EXECUTING,
	CODE_OK,
	CODE_FAIL,
	CODE_TIMEOUT
};

const StateMachineTransitionRule_t FSM_LedTransiciones_INIT[] = {
																												{ INIT },
																												{ BLINK100 },
																												{ INIT },
																												{ BLINK100 }
																											};

const StateMachineTransitionRule_t FSM_LedTransiciones_BLINK100[] = {
																												{ BLINK100 },
																												{ BLINK300 },
																												{ INIT },
																												{ BLINK300 }
																											};

const StateMachineTransitionRule_t FSM_LedTransiciones_BLINK300[] = {
																												{ BLINK300 },
																												{ BLINK500 },
																												{ INIT },
																												{ BLINK500 }
																											};

const StateMachineTransitionRule_t FSM_LedTransiciones_BLINK500[] = {
																												{ BLINK500 },
																												{ INIT },
																												{ INIT },
																												{ INIT }
																											};


const StateMachineConfig_t FSM_LedEstados[] = {
																					{ INIT, &FSM_LedTransiciones_INIT[0], NULL, &Init_Run, NULL },
																					{ BLINK100, &FSM_LedTransiciones_BLINK100[0], NULL, &Blink100_Run, NULL },
																					{ BLINK300, &FSM_LedTransiciones_BLINK300[0], NULL, &Blink300_Run, NULL },
																					{ BLINK500, &FSM_LedTransiciones_BLINK500[0], NULL, &Blink500_Run, NULL }
																				};



void FSM_LedInit( void )
{
	StateMachine_Init( &FSM_Led, &FSM_LedEstados[0], INIT );
	
	IO_Init( &Led );
}

/*void FSM_LedRun( void )
{
	StateMachine_Run( &FSM_Led );
}*/

uint8_t Init_Run( void* data )
{
	// SETUP TIMER 2: BLINK
	/*CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, ENABLE);
	TIM2_ITConfig( TIM2_IT_UPDATE, DISABLE );
	TIM2_Cmd( DISABLE );
	
	TIM2_TimeBaseInit( TIM2_PRESCALER_16, timer->Config.Tiempo);*/
		
	//TIM2_ITConfig( TIM2_IT_UPDATE, ENABLE );
	//enableInterrupts();
	
	//TIM2_Cmd( ENABLE );
	// SETUP TIMER 4: TIMEOUT
	
	IO_Write( &Led, 1 );
	_delay_ms( 1000 );
	return CODE_OK;
}

uint8_t Blink100_Run( void* data )
{
	// START TIMEOUT = 1S
	// START BLINK = 100MS
	// CONSULTAR ISR BLINK Y CONMUTAR LED
	// CONSULTAR ISR TIMEOUT Y CONMUTAR RESULTADO
	// RESET TIMEOUT Y BLINK
	
	IO_Write( &Led, 0 );
	_delay_ms( 1000 );
	return CODE_OK;
}

uint8_t Blink300_Run( void* data )
{
	// START TIMEOUT = 1S
	// START BLINK = 100MS
	// CONSULTAR ISR BLINK Y CONMUTAR LED
	// CONSULTAR ISR TIMEOUT Y CONMUTAR RESULTADO
	// RESET TIMEOUT Y BLINK
	
	IO_Write( &Led, 1 );
	_delay_ms( 1000 );
	return CODE_OK;
}

uint8_t Blink500_Run( void* data )
{
	// START TIMEOUT = 1S
	// START BLINK = 100MS
	// CONSULTAR ISR BLINK Y CONMUTAR LED
	// CONSULTAR ISR TIMEOUT Y CONMUTAR RESULTADO
	// RESET TIMEOUT Y BLINK
	
	IO_Write( &Led, 0 );
	_delay_ms( 1000 );
	return CODE_OK;
}