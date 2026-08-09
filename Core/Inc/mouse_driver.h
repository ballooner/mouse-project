/*
 * usb_driver.h
 *
 *  Created on: Aug 5, 2026
 *      Author: Jace
 */

#ifndef INC_MOUSE_DRIVER_H_
#define INC_MOUSE_DRIVER_H_

#include "stm32f4xx_hal_def.h"
#include <stddef.h>

/* Setup packet bRequest defines */
#define BREQUEST_GET_STATUS			(0x00)
#define BREQUEST_CLEAR_FEATURE		(0x01)
#define BREQUEST_SET_FEATURE		(0x03)
#define BREQUEST_SET_ADDRESS		(0x05)
#define BREQUEST_GET_DESCRIPTOR		(0x06)
#define BREQUEST_SET_DESCRIPTOR		(0x07)
#define BREQUEST_GET_CONFIGURATION	(0x08)
#define BREQUEST_SET_CONFIGURATION	(0x09)

typedef struct
{
	uint8_t		bmRequestType;
	uint8_t		bRequest;
	uint16_t	wValue;
	uint16_t	wIndex;
	uint16_t	wLength;
} usb_setup_packet_t;

HAL_StatusTypeDef USB_Setup();

/* HAL_PCD callbacks */
void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd);

#endif /* INC_MOUSE_DRIVER_H_ */
