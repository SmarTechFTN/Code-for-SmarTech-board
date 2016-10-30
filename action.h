/*
 * action.h
 *
 *  Created on: Oct 25, 2016
 *      Author: root
 */

#ifndef ACTION_H_
#define ACTION_H_

#define RELAY_DDR   DDRC
#define RELAY_PORT	PORTC
#define RELAY_PIN	0

unsigned char temp;
void initProg(unsigned long baud);
void toggleSocket();


#endif /* ACTION_H_ */
