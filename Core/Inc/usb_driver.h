/*
 * usb_driver.h
 *
 *  Created on: Sep 1, 2026
 *      Author: jaced
 */

#ifndef INC_USB_DRIVER_H_
#define INC_USB_DRIVER_H_

#include "stm32f4xx_hal.h"
#include <stddef.h>

/* bmRequestType recipient defines */
#define RECIPIENT_MASK				((uint8_t)0x1F)
#define RECIPIENT_DEVICE			((uint8_t)0x00)
#define RECIPIENT_INTERFACE			((uint8_t)0x01)
#define RECIPIENT_ENDPOINT			((uint8_t)0x02)
/* bmRequestType type defines*/
#define TYPE_MASK					((uint8_t)(0x60))
#define TYPE_STANDARD				((uint8_t)0x00)
#define TYPE_CLASS					((uint8_t)0x20)
#define TYPE_VENDOR					((uint8_t)0x40)

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

/* USB Standard Request handlers */
void USB_StandardRequestHandler(PCD_HandleTypeDef *hpcd);

#endif /* INC_USB_DRIVER_H_ */
