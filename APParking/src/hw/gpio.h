/***********************************************************************
*                            buttons.h   		          		  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	gpio.c
*	@brief 	Driver para controlar los GPIOs de la PS de la zybo
*/

#ifndef GPIO_H
#define GPIO_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

//GPIO pins
#define JF1		13
#define JF2		10
#define JF3		11
#define JF4		12
#define JF7		0
#define JF8		9
#define JF9		14
#define JF10	15

//GPIO mode
#define OUT_PS	0
#define IN_PS	1

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */
/*---------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa los botones de la PS y PL
*/
void initGPIOs(void);

/**
* 	@brief 		Funcion poner el GPIO como entrada o salida
*	@param		Numero del pin
*	@param		Modo de funcionamiento ( IN / OUT )
*/
void setGPIO_mode(int pin, int mode);

/**
* 	@brief 		Funcion para modificar el valor de salida del pin (modo salida)
*	@param		Numero del pin
*	@param		Nivel de tension de salida
*/
void setGPIO_level(int pin, int level);

/**
* 	@brief 		Funcion para leer el estado del pin (modo entrada)
*	@param		Numero del pin
*	@return		Estado del pin
*/
u32 getGPIO_status(int pin);

#endif /* GPIO_H */
/**********************************************************************/
/*                               buttons.h                            */
/**********************************************************************/

