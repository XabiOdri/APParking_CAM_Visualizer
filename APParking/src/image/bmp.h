/***********************************************************************
*                          		 bmp.h  		          		  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	bmp.c
*	@brief 	Implementacion de lectura de ficheros BMP desde la SD
*/


#ifndef SRC_IMAGE_BMP_H
#define SRC_IMAGE_BMP_H

#include <ff.h>

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

#define X_pixels	800
#define Y_pixels	600

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */
/*---------------------------------------------------------------------*/

/**
* 	@brief 		Abre el fichero BMP desde la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero BMP
*	@return 	0 = OK, !0 = NOK
*/
int Open_BMP_File(FIL *File, char *Filename);

/**
* 	@brief 		Se lee el contenido del fichero BMP con resolucion 800 * 600
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos leidos
*/
void Read_BMP_file(FIL *File, u32 *readedData);

/**
* 	@brief 		Cierra el fichero BMP
*	@param		Puntero a la estructura del fichero
*/
void Close_BMP_File(FIL *File);

#endif /* SRC_IMAGE_BMP_H_ */
/**********************************************************************/
/*                                bmp.h	                              */
/**********************************************************************/
