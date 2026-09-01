/*
 * usb_driver.c
 *
 *  Created on: Sep 1, 2026
 *      Author: jaced
 */


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
		0x19, 0x00,		//bTotalLength (return 34 bytes of data)
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
		0x00,			//bInterfaceClass (HID class)
		0x00,			//bInterfaceSubClass
		0x00,			//bInterfaceProtocol
		0x00,			//iInterface

		/* HID DESCRIPTOR
		0x09, 			//bLength
		0x21,			//bDescriptorType
		0x10, 0x01,		//bcdHID
		0x00,			//bCountryCode
		0x01,			//bNumDescriptors
		0x22,			//bDescriptorType
		0x2f, 0x00,		//wDescriptorLength
		*/

		/* INTERRUPT IN ENDPOINT DESCRIPTOR */
		0x07,			//bLength
		0x05,			//bDescriptorType
		0x81,			//bEndpointAddress (Endpoint number 1, Direction is IN)
		0x03,			//bmAttributes (Interrupt type endpoint)
		0x04, 0x00,		//wMaxPacketSize (Max packet size of 4 bytes)
		0x01,			//bInterval (Poll at 1ms)
};

uint8_t device_address = 0;

HAL_StatusTypeDef USB_Start(PCD_HandleTypeDef *hpcd_USB) {
	HAL_PCD_Start(hpcd_USB);

	return HAL_OK;
}

void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd) {
	uint8_t *setup = (uint8_t*) hpcd->Setup;

	uint8_t bmRequestType = setup[0];
	uint8_t bRequest = setup[1];
	uint16_t wValue = setup[2] | ((uint16_t) setup[3] << 8);
	uint16_t wIndex = setup[4] | ((uint16_t) setup[5] << 8);
	uint16_t wLength = setup[6] | ((uint16_t) setup[7] << 8);
}
