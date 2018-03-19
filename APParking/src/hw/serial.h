/*
 * serial.h
 *
 *  Created on: 29 oct. 2017
 *      Author: xabie
 */

#ifndef SRC_SERIAL_H_
#define SRC_SERIAL_H_

/**
* 	@brief 		Limpia la terminal de linea serie
*/
void clearSerialTerminal(void);

/**
* 	@brief 		Envia un array de datos mediante linea serie
*/
void printSerial(char str[]);
void readSerial(void);

#endif /* SRC_SERIAL_H_ */
