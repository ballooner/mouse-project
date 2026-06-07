#include "stm32f4xx.h"
#include <stdio.h>
#include "uart.h"

int periph_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	/* Set up PC12 button */
	// Set mode
	GPIOC->MODER &= ~(GPIO_MODER_MODE10);
	// Set pull-up
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD10);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD10_0;


	/* Set up PC12 button */
	// Set mode
	GPIOC->MODER &= ~(GPIO_MODER_MODE12);
	// Set pull-up
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD12);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD12_0;

	return 0;
}

int main(void)
{
	periph_init();
	uart_init();

	while (1)
	{
		if (!(GPIOC->IDR & (1U << 10)))
		{
			printf("Button 1 pressed!\r\n");
		}

		if (!(GPIOC->IDR & (1U << 12)))
		{
			printf("Button 2 pressed\r\n");
		}
	}

}
