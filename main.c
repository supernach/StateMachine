/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */

/****************************************************************************
* Title                 :   MAIN
* Filename              :   main.c
* Author                :   SuperNach
* Origin Date           :   20/08/2021
* Version               :   1.0.0
* Compiler              :   Cosmic C
* Target                :   STM8
* Copyright             :   
* All Rights Reserved
*
* AQUI VA DECLARACIONES DERECHOS
*
*******************************************************************************/
/****************************************************************************
* Doxygen C Template
* Copyright (c) 2013 - Jacob Beningo - All Rights Reserved
*
* Feel free to use this Doxygen Code Template at your own risk for your own
* purposes.  The latest license and updates for this Doxygen C template can be
* found at www.beningo.com or by contacting Jacob at jacob@beningo.com.
*
* For updates, free software, training and to stay up to date on the latest
* embedded software techniques sign-up for Jacobs newsletter at
* http://www.beningo.com/814-2/
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template.
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
*  20/08/21   1.0.0   SuperNach       Initial Release.
*  
*
*******************************************************************************/
/** @file main.c
 * @brief Ejecucion del trabajo a realizar
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stm8s.h>

#include <stdlib.h>

#include <clock.h>

#include <statemachineled.h>


StateMachine_t FSM_Led;
Gpio_Config_t Led;

/*uint32_t* pruebaHeap;
uint32_t* pruebaHeap2;
uint32_t* pruebaHeap3;*

/******************************************************************************
* Function : DeInitAllGPIO()
*//**
* \b Description: 
*
* Pone en estado de fabrica los puertos
*
* POST-CONDITION: Los puertos estan incializados de fabrica
* 
* @param	void				
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		DeInitAllGPIO( );
* @endcode
* 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SuperNach  </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void DeInitAllGPIO(void)
{
	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOC);
	GPIO_DeInit(GPIOD);
}

/******************************************************************************
* Function : Pin_Init()
*//**
* \b Description:
*
* Asignamos las direcciones fisicas de los puertos a los dispositivos
* utilizados en el sistema
*
*
* PRE-CONDITION: Saber que pines hay que inicializar
*
* POST-CONDITION: Los dispositivos pueden inicializar su parte fisica
* 
*			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		Pin_Init( );
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SuperNach      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void Pin_Init(void)
{
	Led.Puerto = GPIOB;
	Led.Pin = GPIO_PIN_5;
	Led.Tipo = GPIO_MODE_OUT_PP_LOW_SLOW;
}

/******************************************************************************
* Function : InicializacionGPIO()
*//**
* \b Description:
*
* Ejecuta la inicializacion fisica de los pines
*
* PRE-CONDITION: Pin_Init( ) configurado
*
*
*
* 
*			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		InicializacionGPIO( );
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SuperNach      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void InicializacionGPIO(void)
{
	Pin_Init();
}

/******************************************************************************
* Function : InicializacionCLK()
*//**
* \b Description:
*
* Ejecuto la inicializacion del reloj de la cpu
*
* 
*
* POST-CONDITION: El reloj ha sido configurado a la velocidad elegida
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void InicializacionCLK(void)
{
	Clock_HSI_Init(CLK_PRESCALER_HSIDIV1, CLK_PRESCALER_CPUDIV1);
}

/******************************************************************************
* Function : plantilla()
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void InicializacionComponentes(void)
{
	FSM_LedInit( /*&FSM_Led, &Led*/ );
}

/******************************************************************************
* Function : plantilla()
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void Inicializacion_Total(void)
{
	DeInitAllGPIO();
	InicializacionCLK();
	InicializacionGPIO();
	
	InicializacionComponentes();
}


/**
/*
/* @brief Rutina principal
/*
/*
*/
//extern void* sbreak(int size);

main()
{
	Inicializacion_Total( );
	
	/*pruebaHeap = (uint32_t*)sbreak( sizeof( uint32_t ) );
	*pruebaHeap = 0x11111111;*/
	//*pruebaHeap = 0xC0DE;
	
	/*pruebaHeap2 = (uint32_t*)sbreak( sizeof( uint32_t ) );
	*pruebaHeap2 = 0x22222222;
	
	pruebaHeap3 = (uint32_t*)malloc( sizeof( uint32_t ) );
	*pruebaHeap3 = 0xD0CE;*/
	
	
	while (1)
	{
		FSM_LedRun( );
	}
}