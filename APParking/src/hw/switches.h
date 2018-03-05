/*
 * switches.h
 *
 *  Created on: 27 nov. 2017
 *      Author: Xabi
 */

#ifndef SWITCHES_H
#define SWITCHES_H

#define SWT0	0
#define SWT1	1
#define SWT2	2
#define SWT3	3

#define IN_PL	1 //AXI config

void initSwitches(void);
unsigned char getSwitchStatus(int swt);

#endif /* HW_SWITCHES_H_ */
