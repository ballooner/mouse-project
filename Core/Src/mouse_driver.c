/*
 * usb_driver.c
 *
 *  Created on: Aug 5, 2026
 *      Author: Jace
 */

#include "mouse_driver.h"
#include "stm32f4xx_ll_usb.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart2;

HAL_StatusTypeDef USB_Start(PCD_HandleTypeDef *hpcd_USB) {
	HAL_PCD_Start(hpcd_USB);

	return HAL_OK;
}

void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd) {
	uint8_t *setup = (uint8_t*) hpcd->Setup;

	//uint8_t bmRequestType = setup[0];
	uint8_t bRequest = setup[1];
	//uint16_t wValue = setup[2] | ((uint16_t) setup[3 << 8]);
	//uint16_t wIndex = setup[4] | ((uint16_t) setup[5] << 8);
	//uint16_t wLength = setup[5] | ((uint16_t) setup[6] << 8);

	unsigned char uart_message[] = "Request identified\r\n";

	switch (bRequest) {
	case BREQUEST_GET_STATUS:
	case BREQUEST_CLEAR_FEATURE:
	case BREQUEST_SET_FEATURE:
	case BREQUEST_SET_ADDRESS:
	case BREQUEST_GET_DESCRIPTOR:
	case BREQUEST_SET_DESCRIPTOR:
	case BREQUEST_GET_CONFIGURATION:
	case BREQUEST_SET_CONFIGURATION:
		HAL_UART_Transmit(&huart2, (uint8_t*) uart_message,
					sizeof(uart_message) - 1, 100);
		break;
	default:
	}
}
