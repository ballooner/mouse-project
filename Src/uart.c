/*
 * uart.c
 *
 *  Created on: May 25, 2026
 *      Author: Jace
 */

#include "uart.h"
#include <stdint.h>

#define GPIOA_EN			(1U << 0)
#define USART2_EN			(1U << 17)
#define BAUD_RATE			(115200)
#define SYS_CLOCK			(16000000)

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}

void uart_init()
{
	// Enable GPIOA and GPIOC clocks
	RCC->AHB1ENR |= GPIOA_EN;
	RCC->APB1ENR |= USART2_EN;

	// Set up PA2 (TX) and PA3 (RX)
	GPIOA->MODER &= ~(GPIO_MODER_MODER2);	// Clear bits
	GPIOA->MODER |= GPIO_MODER_MODER2_1;	// Set upper bit to 1
		// Set AFRL to 0111
	GPIOA->AFR[0] &= ~(15 << 8);			// Clear bits
	GPIOA->AFR[0] |= (7 << 8);				// Set bits 8-10 to 111

	GPIOA->MODER &= ~(GPIO_MODER_MODER3);	// Clear bits
	GPIOA->MODER |= GPIO_MODER_MODER3_1;	// Set upper bit to 1
		// Set AFRL to 0111
	GPIOA->AFR[0] &= ~(15 << 12);			// Clear bits
	GPIOA->AFR[0] |= (7 << 12);				// Set bits 12-14 to 111

	// Set USART_BRR to proper baud rate
	USART2->BRR = (SYS_CLOCK + (BAUD_RATE / 2U)) / BAUD_RATE;

	// Enable USART, USART_RX, and USART_TX
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_RE;
}

void uart_write(int ch)
{
	while (!(USART2->SR & USART_SR_TXE));		// Check if transmit register isn't empty

	USART2->DR = (ch & 0xFF);
}

uint8_t uart_receive(void)
{
	while (!(USART2->SR & USART_SR_RXNE));		// Wait while data not received

	return (USART2->DR & 0xFF);
}
