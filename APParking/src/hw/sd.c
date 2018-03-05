/*****************************************************************************************
*                                      sd.c           	                                 *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	sd.c
*	@brief 	Driver para controlar el de la SD
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <string.h>
#include <ff.h>
#include "sd.h"

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

#define NOT_MOUNTED		0
#define MOUNTED			1

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

FATFS fatfs;
static unsigned char file_system_status = NOT_MOUNTED;

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa el driver de la SD
*/
void init_sd(void)
{
	TCHAR *Path = "";
	f_mount(&fatfs, Path, 0);
	file_system_status = MOUNTED;
}

/**
* 	@brief 		Abre el fichero desde la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero
*	@return 	0 = OK, !0 = NOK
*/
int open_file(FIL *file, char *filename)
{
	FRESULT result;
	result = f_open(file, filename, FA_READ | FA_OPEN_EXISTING );
	return result;
}

/**
* 	@brief 		Crea un fichero en la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero
*	@return 	0 = OK, !0 = NOK
*/
int create_file(FIL *file, char *filename)
{
	FRESULT result;
	result = f_open(file, filename, FA_WRITE | FA_CREATE_ALWAYS);
	return result;
}

/**
* 	@brief 		Lee los datos del fichero de la SD
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos a leer del fichero
*	@param		Numero de bytes a leer
*	@return 	0 = OK, !0 = NOK
*/
size_t read_file(FIL *file, char *str, size_t size)
{
	size_t num_bytes_read;
	f_read(file, str, size, &num_bytes_read);
	return num_bytes_read;
}

/**
* 	@brief 		Lee los datos del fichero de la SD
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos a escribir en el fichero
*	@param		Numero de bytes a escribir
*	@return 	0 = OK, !0 = NOK
*/
size_t write_file(FIL *file, char *str, size_t size)
{
	size_t num_bytes_written;
	f_write(file, str,  strlen(str), &num_bytes_written);

	return num_bytes_written;
}

/**
* 	@brief 		Realiza el flush en el fichero
*	@param		Puntero a la estructura del fichero
*/
void flush_file(FIL *file)
{
	f_sync(file);
}

/**
* 	@brief 		Cierra el fichero de la SD
*	@param		Puntero a la estructura del fichero
*/
void close_file(FIL *file)
{
	f_sync(file);
	f_close(file);
}


/****************************************************************************************/
/*                                      sd.c            		                         */
/****************************************************************************************/
