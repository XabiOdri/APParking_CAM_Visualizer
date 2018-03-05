/***********************************************************************
*                          		camera.h  		          		  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	camera.c
*	@brief 	Driver para controlar las camaras 1, 2, 3
*/

#ifndef SRC_DOMAIN_CAMERA_H
#define SRC_DOMAIN_CAMERA_H

#include <leds.h>

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

#define STATE_DOWN_BTN		BTN3
#define STATE_UP_BTN		BTN2

#define CAMARA1_LED		LED3
#define CAMARA2_LED		LED2
#define CAMARA3_LED		LED1

#define CAMARA1_ID		1
#define CAMARA2_ID		2
#define CAMARA3_ID		3


/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */
/*---------------------------------------------------------------------*/

/**
* 	@brief 	Captura una imagen con Camera 1
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera1_Data(u32 *pReadedData);

/**
* 	@brief 	Captura una imagen con Camera 2
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera2_Data(u32 *pReadedData);

/**
* 	@brief 	Captura una imagen con Camera 3
* 	@todo	Se debera leer la imagen desde la camara
*	@param	Puntero a los datos de la imagen leida
*/
void Get_Camera3_Data(u32 *pReadedData);

/**
* 	@brief 	Muestra que camara se muestra mediante VGA en los leds
*	@param	ID camara
*/
void Show_Camara_State(int id_camara);

#endif /* SRC_DOMAIN_CAMERA_H_ */
/**********************************************************************/
/*                                camera.h                            */
/**********************************************************************/
