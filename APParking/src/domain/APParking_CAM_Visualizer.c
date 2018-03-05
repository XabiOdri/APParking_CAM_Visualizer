/*****************************************************************************************
*                                APParking_CAM_Visualizer.c                              *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	buttons.c
*	@brief 	Implementacion de la maquina de estados del CAM visualizer
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <xil_types.h>
#include <buttons.h>
#include <leds.h>
#include <sd.h>
#include <vga.h>
#include <bmp.h>
#include "camera.h"

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa el HW necesario de la zybo
*/
void _Initialize_Hardware(void);

/**
* 	@brief 		Inicializa el HW necesario de la zybo
* 	@param		Mira el estado del boton para cambiar la camera en el visualizador
* 	@return		Estado del boton
*/
int _Check_State_Change(int input);

/**
* 	@brief 		Inicializa la maquina de estados
*/
void _Initialize_APParking_CAM_Visualizer(void);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

u32 image[X_pixels*Y_pixels];
enum { CAMERA1, CAMERA2, CAMERA3 }state;

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa el HW necesario de la zybo
*/
void _Initialize_Hardware(void)
{
	init_led();
	initButtons();
	init_sd();
	init_vga();
}

/**
* 	@brief 		Inicializa el HW necesario de la zybo
* 	@param		Mira el estado del boton para cambiar la camera en el visualizador
* 	@return		Estado del boton
*/
int _Check_State_Change(int input)
{
	input = getButtonStatus(input);
	return input;
}

/**
* 	@brief 		Inicializa la maquina de estados
*/
void _Initialize_APParking_CAM_Visualizer(void)
{
	_Initialize_Hardware();

	FIL file;
	Open_BMP_File(&file, "mu.bmp");
	Read_BMP_file(&file, image);
	Close_BMP_File(&file);

	for (int i = 0; i < 1000; i++)
	{
		PrintVGA_bmp(image);
	}

	//Initialize State Machine
	state = CAMERA1;
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 			Inicializa la maquina de estados
* 	@image html		stm.png
*/
void APParking_CAM_Visualizer(void)
{
	_Initialize_APParking_CAM_Visualizer();

	while(1)
	{
		switch(state)
		{
			case CAMERA1:
				Show_Camara_State(CAMARA1_ID);
				Get_Camera1_Data(image);
				PrintVGA_bmp(image);
				if 		( _Check_State_Change(STATE_UP_BTN) )		state = CAMERA2;
				else if ( _Check_State_Change(STATE_DOWN_BTN) )		state = CAMERA3;
				break;
			case CAMERA2:
				Show_Camara_State(CAMARA2_ID);
				Get_Camera2_Data(image);
				PrintVGA_bmp(image);
				if 		( _Check_State_Change(STATE_UP_BTN) )		state = CAMERA3;
				else if ( _Check_State_Change(STATE_DOWN_BTN) )		state = CAMERA1;
				break;
			case CAMERA3:
				Show_Camara_State(CAMARA3_ID);
				Get_Camera3_Data(image);
				PrintVGA_bmp(image);
				if 		( _Check_State_Change(STATE_UP_BTN) )		state = CAMERA1;
				else if ( _Check_State_Change(STATE_DOWN_BTN) )		state = CAMERA2;
				break;
		}
	}
}
/****************************************************************************************/
/*                             APParking_CAM_Visualizer.c                               */
/****************************************************************************************/
