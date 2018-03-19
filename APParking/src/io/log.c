/*****************************************************************************************
*                                 		   log.c                                         *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	log.c
*	@brief 	Implementacion para crear el fichero log en la SD
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

#include <ff.h>
#include <sd.h>
#include <serial.h>

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Abre el fichero de log de la SD
*	@return 	0 = OK, !0 = NOK
*/
FRESULT _Open_Log_File(void);

/**
* 	@brief 		Crea el fichero log en la SD
*	@return 	0 = OK, !0 = NOK
*/
FRESULT _Create_Log_File(void);

/**
* 	@brief 		Crea el fichero log en la SD
*/
void _Close_Log_File(void);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

FIL log_file;
static char log_file_name[32] = "apparking_log.txt";

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Abre el fichero de log de la SD
*	@return 	0 = OK, !0 = NOK
*/
FRESULT _Open_Log_File(void)
{
	FRESULT result;
	result = open_file(&log_file, log_file_name);
	return result;
}

/**
* 	@brief 		Crea el fichero log en la SD
*	@return 	0 = OK, !0 = NOK
*/
FRESULT _Create_Log_File(void)
{
	FRESULT result;
	result = create_file(&log_file, log_file_name);
	return result;
}

/**
* 	@brief 		Crea el fichero log en la SD
*/
void _Close_Log_File(void)
{
	close_file(&log_file);
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Crea el fichero log en la SD
*	@param 		Puntero a datos a escribir en el log
*/
void Write_Log(char *pData)
{
	FRESULT result;
	result = _Open_Log_File();

	if (result != FR_OK) _Create_Log_File();

	write_file(&log_file, pData, sizeof(pData));

	_Close_Log_File();
}

/**
* 	@brief 		Imprime el log en la terminal de linea serie
*/
void Write_Log_Serial(char *pData)
{
	printSerial(pData);
}


/****************************************************************************************/
/*                                      module.c                                        */
/****************************************************************************************/
