/*
 * UART.h
 *
 *  Created on: Oct 23, 2016
 *      Author: root
 */

#ifndef UART_H_
#define UART_H_

void initUsart(unsigned long baud);
void writeUsart(unsigned char data);
unsigned char readUsart();
void writeUsartString(unsigned char* data);

#endif /* UART_H_ */
