/*****************************************************************************************
*                                 		camera.c                                         *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	camera.c
*	@brief 	Driver para controlar las camaras 1, 2, 3
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <string.h>
#include <ff.h>
#include <bmp.h>
#include <model.h>
#include "camera.h"


/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

void _Delay(unsigned int delay_value);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

#ifdef USE_BMP
FIL file;
//static char camara1_frame1[32] = "Camara1_frame1.bmp";
static char camara1_frame1[] = "11.bmp";
static char camara1_frame2[] = "12.bmp";
static char camara2_frame1[] = "21.bmp";
static char camara2_frame2[] = "22.bmp";
static char camara3_frame1[] = "31.bmp";
static char camara3_frame2[] = "32.bmp";
static char *filename;
#endif	//USE_BMP

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 	Captura una imagen con Camera 1
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera1_Data(u32 *pReadedData)
{
	static int frame_counter = 0;

	if (frame_counter < 10)
	{
		filename = camara1_frame1;
	}
	else
	{
		filename = camara1_frame2;
	}

	frame_counter = (frame_counter + 1) % 20;


		Open_BMP_File(&file, filename);
		Read_BMP_file(&file, pReadedData);
		Close_BMP_File(&file);

}

/**
* 	@brief 	Captura una imagen con Camera 2
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera2_Data(u32 *pReadedData)
{
	static int frame_counter = 0;

		if (frame_counter < 10)
		{
			filename = camara2_frame1;
		}
		else
		{
			filename = camara2_frame2;
		}

		frame_counter = (frame_counter + 1) % 20;

			Open_BMP_File(&file, filename);
			Read_BMP_file(&file, pReadedData);
			Close_BMP_File(&file);

}

/**
* 	@brief 	Captura una imagen con Camera 3
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera3_Data(u32 *pReadedData)
{
	static int frame_counter = 0;

		if (frame_counter < 10)
		{
			filename = camara3_frame1;
		}
		else
		{
			filename = camara3_frame2;
		}

		frame_counter = (frame_counter + 1) % 20;


			Open_BMP_File(&file, filename);
			Read_BMP_file(&file, pReadedData);
			Close_BMP_File(&file);

}

/**
* 	@brief 	Muestra que camara se muestra mediante VGA en los leds
*	@param	ID camara
*/
void Show_Camara_State(int id_camara)
{
	if (id_camara == CAMARA1_ID)
	{
		turnOFF_led(CAMARA2_LED);
		turnOFF_led(CAMARA3_LED);
		turnON_led(CAMARA1_LED);
	}
	else if (id_camara == CAMARA2_ID)
	{
		turnOFF_led(CAMARA1_LED);
		turnOFF_led(CAMARA3_LED);
		turnON_led(CAMARA2_LED);
	}
	else if (id_camara == CAMARA3_ID)
	{
		turnOFF_led(CAMARA1_LED);
		turnOFF_led(CAMARA2_LED);
		turnON_led(CAMARA3_LED);
	}
}
/****************************************************************************************/
/*                                      camera.c                                        */
/****************************************************************************************/
