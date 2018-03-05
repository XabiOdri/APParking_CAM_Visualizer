/***********************************************************************
*                               leds.h   		          		  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	leds.c
*	@brief 	Driver para controlar los leds de la zybo
*/

#ifndef SRC_LEDS_H_
#define SRC_LEDS_H_

#define LED0	0
#define LED1	1
#define LED2	2
#define LED3	3

#define LED4	7

#define OUT_PS	1
#define IN_PS	0

#define OUT_PL	0 //AXI config
#define IN_PL	1 //AXI config

/**
* 	@brief 		Inicializa los leds de la PS y PL
*/
void init_led(void);

/**
* 	@brief 		Funcion para encender un led
*	@param		Numero del led
*/
void turnON_led(int led);

/**
* 	@brief 		Funcion para apagar un led
*	@param		Numero del led
*/
void turnOFF_led(int led);


#endif /* SRC_LEDS_H_ */
