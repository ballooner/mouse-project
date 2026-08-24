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

static const uint8_t	device_descriptor[] =
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

static const uint8_t	config_descriptor[] =
{
		/* CONFIG DESCRIPTOR */
		0x09,			//bLength
		0x02,			//bDescriptorType
		0x22, 0x00,		//bTotalLength (return 34 bytes of data)
		0x01,			//bNumInterfaces
		0x01,			//bConfigurationValue
		0x00,			//iConfiguration
		0xC0,			//bmAttributes (Self powered)
		0x32,			//bMaxPower

		/* INTERFACE DESCRIPTOR */
		0x09,			//bLength
		0x04,			//bDescriptorType
		0x00,			//bInterfaceNumber
		0x00,			//bAlternateSetting
		0x01,			//bNumEndpoints (only using 1 interrupt endpoint)
		0x03,			//bInterfaceClass (HID class)
		0x01,			//bInterfaceSubClass
		0x02,			//bInterfaceProtocol
		0x00,			//iInterface

		/* HID DESCRIPTOR */
		0x09, 			//bLength
		0x21,			//bDescriptorType
		0x10, 0x01,		//bcdHID
		0x00,			//bCountryCode
		0x01,			//bNumDescriptors
		0x22,			//bDescriptorType
		0x2f, 0x00,		//wDescriptorLength

		/* INTERRUPT IN ENDPOINT DESCRIPTOR */
		0x07,			//bLength
		0x05,			//bDescriptorType
		0x81,			//bEndpointAddress (Endpoint number 1, Direction is IN)
		0x03,			//bmAttributes (Interrupt type endpoint)
		0x04, 0x00,		//wMaxPacketSize (Max packet size of 4 bytes)
		0x01,			//bInterval (Poll at 1ms)
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
