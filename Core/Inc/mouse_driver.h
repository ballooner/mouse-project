/*
 * usb_driver.h
 *
 *  Created on: Aug 5, 2026
 *      Author: Jace
 */

#ifndef INC_MOUSE_DRIVER_H_
#define INC_MOUSE_DRIVER_H_

#include "stm32f4xx_hal.h"
#include <stddef.h>

/* Setup packet bRequest defines */
#define BREQUEST_GET_STATUS			((uint8_t)0x00)
#define BREQUEST_CLEAR_FEATURE		((uint8_t)0x01)
#define BREQUEST_SET_FEATURE		((uint8_t)0x03)
#define BREQUEST_SET_ADDRESS		((uint8_t)0x05)
#define BREQUEST_GET_DESCRIPTOR		((uint8_t)0x06)
#define BREQUEST_SET_DESCRIPTOR		((uint8_t)0x07)
#define BREQUEST_GET_CONFIGURATION	((uint8_t)0x08)
#define BREQUEST_SET_CONFIGURATION	((uint8_t)0x09)

HAL_StatusTypeDef USB_Start(PCD_HandleTypeDef *hpcd_USB);

/* HAL_PCD callbacks */
void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd);

#endif /* INC_MOUSE_DRIVER_H_ */
