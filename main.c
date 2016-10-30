/*
 * main.c
 *
 *  Created on: Oct 1, 2016
 *      Author: Marko Kozomora
 */
#include "macros.h"

int main()
{
	initProg(9600);
	while(1)
	{
		toggleSocket();
	}
	return 0;
}
