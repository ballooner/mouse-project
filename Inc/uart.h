/*
 * uart.h
 *
 *  Created on: May 25, 2026
 *      Author: Jace
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#include <stdint.h>

void uart_init(void);
void uart_write(int ch);
uint8_t uart_receive(void);

#endif /* UART_H_ */
