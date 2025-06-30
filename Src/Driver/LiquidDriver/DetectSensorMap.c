/*
 * ValveMap.c
 *
 *  Created on: 2016年6月7日
 *      Author: Administrator
 */

#include <LiquidDriver/DetectSensorMap.h>
#include "stm32f4xx.h"

#include "Peripheral/DetectSensorManager.h"

void DetectSensorMap_Init(Sensor *sensor)
{
    Uint8 i;

    sensor[0].pin = GPIO_Pin_4;
    sensor[0].port = GPIOC;
    sensor[0].rcc = RCC_AHB1Periph_GPIOC;
    DetectSensorDriver_Init(&sensor[0]);

    sensor[1].pin = GPIO_Pin_7;
    sensor[1].port = GPIOA;
    sensor[1].rcc = RCC_AHB1Periph_GPIOA;
    DetectSensorDriver_Init(&sensor[1]);

    sensor[2].pin = GPIO_Pin_13;
	sensor[2].port = GPIOE;
	sensor[2].rcc = RCC_AHB1Periph_GPIOE;
	DetectSensorDriver_Init(&sensor[2]);
}


