/*****************************************************************************************
*                                 		   bmp.c                                         *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	bmp.c
*	@brief 	Implementacion de lectura de ficheros BMP desde la SD
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <ff.h>
#include <globalvars.h>
#include "bmp.h"
#include "sd.h"

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

#define offset_BMP	54
u32 imagen[X_pixels*Y_pixels];

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Abre el fichero BMP desde la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero BMP
*	@return 	0 = OK, !0 = NOK
*/
int Open_BMP_File(FIL *File, char *Filename)
{
	int status;
	status = open_file(File, Filename);
	return status;
}

/**
* 	@brief 		Se lee el contenido del fichero BMP con resolucion 800 * 600
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos leidos
*/
void Read_BMP_file(FIL *File, u32 *readedData)
{
	char header[offset_BMP];
	read_file(File, header, offset_BMP);
	for (int y = Y_pixels-1; y >= 0; y--)
	{
		for (int x = 0; x < X_pixels; x++)
		{
			read_file(File, (char *)&readedData[(y*X_pixels) + x], 3);
		}
	}

}

/**
* 	@brief 		Cierra el fichero BMP
*	@param		Puntero a la estructura del fichero
*/
void Close_BMP_File(FIL *File)
{
	close_file(File);
}

/****************************************************************************************/
/*                                         bmp.c                                        */
/****************************************************************************************/
