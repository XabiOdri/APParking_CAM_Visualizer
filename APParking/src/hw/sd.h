/***********************************************************************
*                            sd.h   		          			  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	sd.c
*	@brief 	Driver para controlar el de la SD
*/

#ifndef SD_H
#define SD_H

#include <stddef.h>
#include <ff.h>

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */
/*---------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa el driver de la SD
*/
void init_sd(void);

/**
* 	@brief 		Abre el fichero desde la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero
*	@return 	0 = OK, !0 = NOK
*/
int open_file(FIL *file, char *filename);

/**
* 	@brief 		Crea un fichero en la SD
*	@param		Puntero a la estructura del fichero
*	@param		Nombre del fichero
*	@return 	0 = OK, !0 = NOK
*/
int create_file(FIL *file, char *filename);

/**
* 	@brief 		Lee los datos del fichero de la SD
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos a leer del fichero
*	@param		Numero de bytes a leer
*	@return 	0 = OK, !0 = NOK
*/
size_t read_file(FIL *file, char *str, size_t size);

/**
* 	@brief 		Lee los datos del fichero de la SD
*	@param		Puntero a la estructura del fichero
*	@param		Puntero a los datos a escribir en el fichero
*	@param		Numero de bytes a escribir
*	@return 	0 = OK, !0 = NOK
*/
size_t write_file(FIL *file, char *str, size_t size);

/**
* 	@brief 		Realiza el flush en el fichero
*	@param		Puntero a la estructura del fichero
*/
void flush_file(FIL *file);

/**
* 	@brief 		Cierra el fichero de la SD
*	@param		Puntero a la estructura del fichero
*/
void close_file(FIL *file);

#endif /* MODULE_H */
/**********************************************************************/
/*                                module.h                            */
/**********************************************************************/
