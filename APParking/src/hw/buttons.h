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
* 	@file 	buttons.c
*	@brief 	Driver para controlar los botones de la zybo
*/

#ifndef BUTTONS_H
#define BUTTONS_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

#define BTN0	0
#define BTN1	1
#define BTN2	2
#define BTN3	3

#define BTN4	50
#define BTN5	51

#define IN_PL	1 //AXI config

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */
/*---------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa los botones de la PS y PL
*/
void initButtons(void);

/**
* 	@brief 		Funcion para leer el estado del boton
*	@param		Numero de boton
*	@return 	Estado del boton
*/
unsigned long getButtonStatus(int btn);

#endif /* BUTTONS_H_ */
/**********************************************************************/
/*                               buttons.h                            */
/**********************************************************************/
