/***********************************************************************
*                            	vga.h   		          		  	   *
************************************************************************
* AUTHOR: Xabier Odriozola
*
* DESCRIPTION:
*
***********************************************************************/
/**
*	@author Xabier Odriozola
* 	@file 	vga.c
*	@brief 	Driver para controlar el puerto VGA y HDMI
*/


#ifndef VGA_H
#define VGA_H

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
* 	@brief 		Inicializa el controlador
*/
int init_vga(void);

/**
* 	@brief 		Hace referencia al siguiente buffer frame
*	@return 	Puntero al siguiente buffer
*/
u32* GetVGA_buffer(void);

/**
* 	@brief 		Cambia de frame del buufer
*/
void Set_Buffer_Active(void);

/**
* 	@brief 		Abre el fichero BMP desde la SD
*	@param 		Imagen para mostrar con resolucion 800 * 600
*/
void PrintVGA_bmp(u32 *data2print);

#endif /* VGA_H */
/**********************************************************************/
/*                                module.h                            */
/**********************************************************************/

