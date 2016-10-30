/*
 * action.c
 *
 *  Created on: Oct 25, 2016
 *      Author: Marko Kozomora
 */

#include "macros.h"

void initProg(unsigned long baud){
	_delay_ms(10);
	initUsart(baud);
	initTimer();
	_delay_ms(10);
	//Set pin CO as a output for toggle relay
	RELAY_DDR |= (1 << RELAY_PIN);
	RELAY_PORT = (1 << RELAY_PIN);

}

void toggleSocket(){

	temp = readUsart();
	if(temp == 'H')
	{
		RELAY_PORT ^= (1 << RELAY_PIN);
		writeUsartString("OK");
	}
}

