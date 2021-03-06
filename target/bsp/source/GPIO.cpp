/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.8.0 evaluation distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * Copyright (C) 2014-2016 Draupner Graphics A/S <http://www.touchgfx.com>.
 * All rights reserved.
 *
 * TouchGFX is protected by international copyright laws and the knowledge of
 * this source code may not be used to write a similar product. This file may
 * only be used in accordance with a license and should not be re-
 * distributed in any way without the prior permission of Draupner Graphics.
 *
 * This is licensed software for evaluation use, any use must strictly comply
 * with the evaluation license agreement provided with delivery of the
 * TouchGFX software.
 *
 * The evaluation license agreement can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#include <touchgfx/hal/GPIO.hpp>

extern "C"
{
#include "stm32469i_discovery.h"
}

using namespace touchgfx;

static bool gpioState[4];

void GPIO::init()
{
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Mode	= GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull	= GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	
	GPIO_InitStruct.Pin	 = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);  //Arduino connector D2

	GPIO_InitStruct.Pin	 = GPIO_PIN_12;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);	 //Arduino connector D4

	GPIO_InitStruct.Pin	 = GPIO_PIN_11;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);	 //Arduino connector D7
}

void GPIO::set(GPIO_ID id)
{
  
}

void GPIO::clear(GPIO_ID id)
{
  
}

void GPIO::toggle(GPIO_ID id)
{
  
}

bool GPIO::get(GPIO_ID id)
{
    return gpioState[id];
}
