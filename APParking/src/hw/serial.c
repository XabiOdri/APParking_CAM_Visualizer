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

void printSerial(char *str)
{
	setCursorLeft;
	clear_terminal;
	printf("%s", str);
}

void readSerial(void)
{

}
