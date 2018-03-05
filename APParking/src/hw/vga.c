/*****************************************************************************************
*                                      	vga.c                                            *
******************************************************************************************
*	@author Xabier Odriozola
* 	@file 	vga.c
*	@brief 	Driver para controlar el puerto VGA y HDMI
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/


#include <xil_types.h>
#include <vga_modes.h>
#include <display_ctrl.h>
#include "vga.h"

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

#define resolucionX		800
#define resolucionY		600

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

DisplayCtrl driver;
u32 vga_buffer[DISPLAY_NUM_FRAMES][resolucionX * resolucionY];
int nextBuffer = 0;
int actual_frame = 0;

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

/**
* 	@brief 		Inicializa el controlador
*/
int init_vga(void)
{
	u32 *vgaPtr[DISPLAY_NUM_FRAMES];
	for (int i = 0; i < DISPLAY_NUM_FRAMES; i++) vgaPtr[i] = vga_buffer[i];
	int status = DisplayInitialize(&driver, XPAR_AXIVDMA_1_DEVICE_ID, XPAR_AXI_DISPCTRL_1_S_AXI_BASEADDR, DISPLAY_HDMI, vgaPtr, resolucionX * sizeof(u32));
	status = DisplaySetMode(&driver, &VMODE_800x600);
	status = DisplayStart(&driver);
	return status;
}

/**
* 	@brief 		Hace referencia al siguiente buffer frame
*	@return 	Puntero al siguiente buffer
*/
u32* Get_VGA_buffer(void)
{
	return vga_buffer[nextBuffer];
}

/**
* 	@brief 		Cambia de frame del buufer
*/
void Set_Buffer_Active(void)
{
	DisplayChangeFrame(&driver, nextBuffer);
	actual_frame = nextBuffer;
	nextBuffer = (nextBuffer + 1) % DISPLAY_NUM_FRAMES;

}

/**
* 	@brief 		Abre el fichero BMP desde la SD
*	@param 		Imagen para mostrar con resolucion 800 * 600
*/
void PrintVGA_bmp(u32 *data2print)
{
	memcpy(Get_VGA_buffer(), data2print, sizeof(u32)*800*600);
	Set_Buffer_Active();
}

/****************************************************************************************/
/*                                      vga.c 	                                        */
/****************************************************************************************/
