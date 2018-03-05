/*
 * switches.c
 *
 *  Created on: 27 nov. 2017
 *      Author: Xabi
 */


#include <xparameters.h>
#include <xgpio.h>

#include "switches.h"

static XGpio axi_gpio;

void initSwitches(void)
{
	//Inicializar switches PL
	XGpio_Initialize(&axi_gpio, XPAR_GPIO_2_DEVICE_ID);
	XGpio_SetDataDirection(&axi_gpio, 1, IN_PL);
}

unsigned char getSwitchStatus(int swt)
{
	u32 state;

	state = XGpio_DiscreteRead(&axi_gpio, 1);
	return ((state & (1<<swt))>>swt);
}
