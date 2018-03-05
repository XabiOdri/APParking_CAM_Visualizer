APParking_CAM_Visualizer

Objetivos:
	-Generar ficheros bmp mediante software
	-Guardar los ficheros generados mediante software en la SD
	-Leer ficheros de la SD (bmp, txt)
	-Visualizar los ficheros bmp mediante VGA y HDMI

Implementado actualmente:
	Drivers para controlar hardware de la zybo (botones, switches y leds)
		-botones
		-leds
		-switches
	Maquina de estados que permite interactuar entre estados mediante botones y este estado se muestra mediante leds
	Driver de VGA que permita visualizar archivos bmp
	Driver para leer ficheros en la sd
	Estados de la state machine relacionadas con ficheros y vga


Estructura de carpetas:
	/domain -> funciones que se utilizan en la maquina de estados
	/hw 	-> implementaciones para controlar en hw de la zybo
	/image 	-> implementaciones para controlar archivos bmp
	/io 	-> implementaciones que permiten realizar un output

Documentacion Doxigen:
	Se ha documentado toda funcion que es necesaria para el correcto funcionamiento del APParking_CAM_Visualizer
	Los siguientes ficheros no se han documentado puesto que no han sido utilizados en este proyecto
		- serial .c .h
		- switches .c .h
		- timer .c .h
	Los siguientes ficheros tampoco se han documentado puesto que solo contienen deficiones.
		- globalvars.h
		- model.h
	En el resto de ficheros se ha realizado la descripcion brevia de cada modulo. Cada funcion implementado en estos 
	modulos tambien tiene una descripcion brevia, la descripcion de cada parametro y los posibles valores de retorno
	que puede tener

	Se ha creado una imagen de la maquina de estados para facilitar la tarea de comprender su funcionamiento