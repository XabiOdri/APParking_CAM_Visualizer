/*
 * serial.c
 *
 *  Created on: 29 oct. 2017
 *      Author: xabie
 */


#include <stdio.h>
#include "xil_printf.h"

#include "serial.h"

#define clear_terminal	printf("\x1B[2J"); 		//Clear terminal
#define setCursorLeft	printf("\x1B[H"); 		//Set cursor to top left of terminal

/**
* 	@brief 		Limpia la terminal de linea serie
*/
void clearSerialTerminal(void)
{
	setCursorLeft;
	clear_terminal;
}

/**
* 	@brief 		Envia un array de datos mediante linea serie
*/
void printSerial(char *str)
{
	printf("%s", str);
}

void readSerial(void)
{

}
