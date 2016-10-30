/*
 * UART.c
 *
 *  Created on: Oct 23, 2016
 *      Author: Marko Kozomora
 */

#include "macros.h"

void initUsart(unsigned long baud){

	UCSRA = 0;
	UCSRB = (1 << RXCIE) | (1 << TXCIE) | (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0);
	SREG |= 0x80;
	unsigned int temp =((double)F_CPU/(baud*16.0f))-1;
	UBRRH = (unsigned char)(temp >> 8);
	UBRRL = (unsigned char)temp;
}

#define TX_BUFFER_SIZE 64
static volatile unsigned char tx_buffer[TX_BUFFER_SIZE];
static volatile unsigned char tx_wr_index=0;
static volatile unsigned char tx_counter=0;
static volatile unsigned char tx_rd_index=0;

void writeUsart(unsigned char data){

	while(tx_counter == TX_BUFFER_SIZE);
	cli();

	if(!(UCSRA >> UDRE))
	{
		tx_buffer[tx_wr_index] = data;
		if(++tx_wr_index == TX_BUFFER_SIZE)
			tx_wr_index=0;

		tx_counter++;
	}
	else{
		UDR=data;
	}
	sei();
}

void writeUsartString(unsigned char* data){
	unsigned char i=0;
	while(data[i] != 0x00)
	{
		writeUsart(data[i]);
		i++;
	}
}

ISR(USART_TXC_vect){

	if(tx_counter)
	{
		tx_counter--;
		UDR = tx_buffer[tx_rd_index];
		if(++tx_rd_index == TX_BUFFER_SIZE)
			tx_rd_index = 0;

	}
}

#define RX_BUFFER_SIZE 64
static volatile unsigned char rx_buffer[TX_BUFFER_SIZE];
static volatile unsigned char rx_wr_index=0;
static volatile unsigned char rx_counter=0;
static volatile unsigned char rx_rd_index=0;

unsigned char readUsart(){
	unsigned char data;
	while(rx_counter==0);

	data = rx_buffer[rx_rd_index];
	if(++rx_rd_index == RX_BUFFER_SIZE)
		rx_rd_index=0;

	rx_counter--;
	return data;
}

ISR(USART_RXC_vect){
	unsigned char status;
	status = UCSRA;

	if(!(status & ((1 << FE) | (1 << DOR) | (1 <<  PE))))
	{
		rx_buffer[rx_wr_index] = UDR;
		if(++rx_wr_index == RX_BUFFER_SIZE)
			rx_wr_index = 0;

		rx_counter++;
	}
}
