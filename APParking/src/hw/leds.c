/*****************************************************************************************
*                                      	leds.c      	                                 *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	leds.c
*	@brief 	Driver para controlar los leds de la zybo
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/
#include <xparameters.h>
#include <xgpiops.h>
#include <xgpio.h>

#include "leds.h"

static XGpioPs Gpio;
static XGpio axi_gpio;

static u32 mask = 0;

/**
* 	@brief 		Inicializa los leds de la PS y PL
*/
void init_led(void)
{
	//Init ps LEDs
	XGpioPs_Config *ConfigPtr;
	ConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);
	XGpioPs_SetOutputEnablePin(&Gpio,LED4,OUT_PS);
	XGpioPs_SetDirectionPin(&Gpio,LED4,OUT_PS);

	//Init pl LEDs
	XGpio_Initialize(&axi_gpio, XPAR_GPIO_1_DEVICE_ID);
}

/**
* 	@brief 		Funcion para encender un led
*	@param		Numero del led
*/
void turnON_led(int led)
{
	if (led<4)
	{
		mask |= (1<<led);
		XGpio_DiscreteWrite(&axi_gpio, 1, mask);
	}
	else
	{
		XGpioPs_WritePin(&Gpio,led,1);
	}
}

/**
* 	@brief 		Funcion para apagar un led
*	@param		Numero del led
*/
void turnOFF_led(int led)
{
	if (led<4)
	{
		mask &= ~(1<<led);
		XGpio_DiscreteWrite(&axi_gpio, 1, mask);
	}
	else
	{
		XGpioPs_WritePin(&Gpio,led,0);
	}
}
