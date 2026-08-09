/*
 * usb_driver.c
 *
 *  Created on: Aug 5, 2026
 *      Author: Jace
 */


#include <mouse_driver.h>
#include "stm32f4xx_ll_usb.h"

HAL_StatusTypeDef USB_Start()
{
	HAL_PCD_Start();
}

void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd)
{
	uint8_t *setup = (uint8_t *)hpcd->Setup;

	uint8_t 	bmRequestType 	= setup[0];
	uint8_t 	bRequest		= setup[1];
	uint16_t 	wValue			= setup[2] | ((uint16_t)setup[3 << 8]);
	uint16_t	wIndex 			= setup[4] | ((uint16_t)setup[5] << 8);
	uint16_t	wLength			= setup[5] | ((uint16_t)setup[6] << 8);

}
