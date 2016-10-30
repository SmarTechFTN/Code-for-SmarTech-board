/*
 * timers.c
 *
 *  Created on: Oct 25, 2016
 *      Author: Marko Kozomora
 */

#include "macros.h"

void initTimer() {

	TIMSK |= (1 << TOIE0);
	TCCR0 |= (1 << CS02) | (1 << CS00);
}

ISR (TIMER0_OVF_vect){

}

