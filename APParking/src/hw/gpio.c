/*****************************************************************************************
*                                      gpio.c	                                         *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	gpio.c
*	@brief 	Driver para controlar los GPIOs de la PS de la zybo
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <xgpiops.h>

#include "gpio.h"

static XGpioPs Gpio;

/**
* 	@brief 		Inicializa los botones de la PS y PL
*/
void initGPIOs(void)
{
	//Inicializar GPIOs de la PS (Pmod F)
	XGpioPs_Config *ConfigPtr;

	ConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);
}

/**
* 	@brief 		Funcion poner el GPIO como entrada o salida
*	@param		Numero del pin
*	@param		Modo de funcionamiento ( IN / OUT )
*/
void setGPIO_mode(int pin, int mode)
{
	if ( mode == OUT_PS )
	{
		XGpioPs_SetOutputEnablePin(&Gpio,pin,mode);
		XGpioPs_SetDirectionPin(&Gpio,pin,mode);
	}
	if ( mode == IN_PS )
	{
		XGpioPs_SetDirectionPin(&Gpio,pin,mode);
	}

}

/**
* 	@brief 		Funcion para modificar el valor de salida del pin (modo salida)
*	@param		Numero del pin
*	@param		Nivel de tension de salida
*/
void setGPIO_level(int pin, int level)
{
	XGpioPs_WritePin(&Gpio, pin, level);
}

/**
* 	@brief 		Funcion para leer el estado del pin (modo entrada)
*	@param		Numero del pin
*	@return		Estado del pin
*/
u32 getGPIO_status(int pin)
{
	return XGpioPs_ReadPin(&Gpio,pin);
}

