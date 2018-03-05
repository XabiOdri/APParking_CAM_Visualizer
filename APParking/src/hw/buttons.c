/*****************************************************************************************
*                                      buttons.c                                         *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	buttons.c
*	@brief 	Driver para controlar los botones de la zybo
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <xparameters.h>
#include <xgpio.h>
#include <xgpiops.h>

#include "buttons.h"

#define MAX_AXI_BUTTONS	4

static XGpioPs Gpio;
static XGpio axi_gpio;

/**
* 	@brief 		Inicializa los botones de la PS y PL
*/
void initButtons(void)
{
	//Inicializar botones PS
	XGpioPs_Config *ConfigPtr;

	ConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);

	//Inicializar botones PL
	XGpio_Initialize(&axi_gpio, XPAR_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&axi_gpio, 1, IN_PL);
}

/**
* 	@brief 		Funcion para leer el estado del boton
*	@param		Numero de boton
*	@return 	Estado del boton
*/
unsigned long getButtonStatus(int btn)
{
	unsigned long state;
	if ( btn < MAX_AXI_BUTTONS )
	{
		state = XGpio_DiscreteRead(&axi_gpio, 1);
		return (unsigned long)((state & (1<<btn))>>btn);
	}
	else
	{
		return (unsigned long)XGpioPs_ReadPin(&Gpio,btn);
	}
}
