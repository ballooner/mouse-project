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

static const uint8_t device_descriptor[] =
{
		0x12,			//bLength
		0x01,			//bDescriptorType
		0x02, 0x00,		//bcdUSB
		0x00,			//bDeviceClass
		0x00,			//bDeviceSubClass
		0x00,			//bDeviceProtocol
		0x40,			//bMaxPacketSize
		0x83, 0x04,		//idVendor
		0x01, 0x00,		//idProduct
		0x00, 0x01,		//bcdDevice
		0x00,			//iManufacturer
		0x00,			//iProduct
		0x00,			//iSerialNumber
		0x01			//bNumConfigurations
};

HAL_StatusTypeDef USB_Start(PCD_HandleTypeDef *hpcd_USB) {
	HAL_PCD_Start(hpcd_USB);

	return HAL_OK;
}

void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd) {
	USB_OTG_GlobalTypeDef USBx = hpcd->Instance;
	uint8_t *setup = (uint8_t*) hpcd->Setup;

	uint8_t bmRequestType = setup[0];
	uint8_t bRequest = setup[1];
	uint16_t wValue = setup[2] | ((uint16_t) setup[3] << 8);
	uint16_t wIndex = setup[4] | ((uint16_t) setup[5] << 8);
	uint16_t wLength = setup[5] | ((uint16_t) setup[6] << 8);

	unsigned char uart_message[] = "Request identified\r\n";

	switch (bRequest) {
	case BREQUEST_GET_STATUS:
		// Device is self-powered and doesn't need to wake the host up during suspend
		uint16_t response = 0x00;
		USB_WritePacket(USBx, &response, 0, 2, 0);
		break;
	case BREQUEST_CLEAR_FEATURE:
		break;
	case BREQUEST_SET_FEATURE:
		break;
	case BREQUEST_SET_ADDRESS:
		break;
	case BREQUEST_GET_DESCRIPTOR:
		break;
	case BREQUEST_SET_DESCRIPTOR:
		break;
	case BREQUEST_GET_CONFIGURATION:
		break;
	case BREQUEST_SET_CONFIGURATION:
		break;
	default:
	}
}
