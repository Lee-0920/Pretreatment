/*
 * PumpMap.c
 *
 *  Created on: 2016年5月30日
 *      Author: Administrator
 */
#include "stm32f4xx.h"
#include "PumpDriver.h"
#include "PumpMap.h"
#include "HardwareType.h"

void PumpMap_Init(Pump *pump)
{
	//泵1-蠕动泵1
	pump[0].driver.pinClock = GPIO_Pin_14;
	pump[0].driver.portClock = GPIOB;
	pump[0].driver.rccClock = RCC_AHB1Periph_GPIOB;

	pump[0].driver.pinDir = GPIO_Pin_15;
	pump[0].driver.portDir = GPIOB;
	pump[0].driver.rccDir = RCC_AHB1Periph_GPIOB;

	pump[0].driver.pinDiag = GPIO_Pin_13;
	pump[0].driver.portDiag = GPIOB;
	pump[0].driver.rccDiag = RCC_AHB1Periph_GPIOB;

	pump[0].driver.pinReset = GPIO_Pin_13; //蠕动泵无需复位，直接赋值悬空引脚
	pump[0].driver.portReset = GPIOC;
	pump[0].driver.rccReset = RCC_AHB1Periph_GPIOC;

    PumpDriver_Init(&pump[0].driver);
    PumpDriver_PullLow(&pump[0].driver);
    PumpDriver_SetForwardLevel(&pump[0].driver,Bit_RESET);
    PumpDriver_Disable(&pump[0].driver);

    //泵2-蠕动泵2
    pump[1].driver.pinClock = GPIO_Pin_12;
	pump[1].driver.portClock = GPIOD;
	pump[1].driver.rccClock = RCC_AHB1Periph_GPIOD;

	pump[1].driver.pinDir = GPIO_Pin_11;
	pump[1].driver.portDir = GPIOD;
	pump[1].driver.rccDir = RCC_AHB1Periph_GPIOD;

	pump[1].driver.pinDiag = GPIO_Pin_10;
	pump[1].driver.portDiag = GPIOD;
	pump[1].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[1].driver.pinReset = GPIO_Pin_13; //蠕动泵无需复位，直接赋值悬空引脚
	pump[1].driver.portReset = GPIOC;
	pump[1].driver.rccReset = RCC_AHB1Periph_GPIOC;

	PumpDriver_Init(&pump[1].driver);
	PumpDriver_PullLow(&pump[1].driver);
	PumpDriver_SetForwardLevel(&pump[1].driver,Bit_RESET);
	PumpDriver_Disable(&pump[1].driver);

	//泵3-直流泵1
	pump[2].driver.pinClock = GPIO_Pin_13; //直流泵无需脉冲，直接赋值悬空引脚
	pump[2].driver.portClock = GPIOC;
	pump[2].driver.rccClock = RCC_AHB1Periph_GPIOC;

	pump[2].driver.pinDir = GPIO_Pin_13;
	pump[2].driver.portDir = GPIOD;
	pump[2].driver.rccDir = RCC_AHB1Periph_GPIOD;

	pump[2].driver.pinDiag = GPIO_Pin_10; //直流泵无需故障检测，赋值蠕动泵引脚即可
	pump[2].driver.portDiag = GPIOD;
	pump[2].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[2].driver.pinReset = GPIO_Pin_8; //直流泵赋值使能引脚
	pump[2].driver.portReset = GPIOC;
	pump[2].driver.rccReset = RCC_AHB1Periph_GPIOC;

	PumpDriver_Init(&pump[2].driver);
	PumpDriver_PullLow(&pump[2].driver);
	PumpDriver_SetForwardLevel(&pump[2].driver,Bit_RESET);
	PumpDriver_Disable(&pump[2].driver);

	//泵4-直流泵2
	pump[3].driver.pinClock = GPIO_Pin_13; //直流泵无需脉冲，直接赋值悬空引脚
	pump[3].driver.portClock = GPIOC;
	pump[3].driver.rccClock = RCC_AHB1Periph_GPIOC;

	pump[3].driver.pinDir = GPIO_Pin_14;
	pump[3].driver.portDir = GPIOD;
	pump[3].driver.rccDir = RCC_AHB1Periph_GPIOD;

	pump[3].driver.pinDiag = GPIO_Pin_10; //直流泵无需故障检测，赋值蠕动泵引脚即可
	pump[3].driver.portDiag = GPIOD;
	pump[3].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[3].driver.pinReset = GPIO_Pin_9; //直流泵赋值使能引脚
	pump[3].driver.portReset = GPIOC;
	pump[3].driver.rccReset = RCC_AHB1Periph_GPIOC;

	PumpDriver_Init(&pump[3].driver);
	PumpDriver_PullLow(&pump[3].driver);
	PumpDriver_SetForwardLevel(&pump[3].driver,Bit_RESET);
	PumpDriver_Disable(&pump[3].driver);

	//泵5-直流泵3
	pump[4].driver.pinClock = GPIO_Pin_13; //直流泵无需脉冲，直接赋值悬空引脚
	pump[4].driver.portClock = GPIOC;
	pump[4].driver.rccClock = RCC_AHB1Periph_GPIOC;

	pump[4].driver.pinDir = GPIO_Pin_15;
	pump[4].driver.portDir = GPIOD;
	pump[4].driver.rccDir = RCC_AHB1Periph_GPIOD;

	pump[4].driver.pinDiag = GPIO_Pin_10; //直流泵无需故障检测，赋值蠕动泵引脚即可
	pump[4].driver.portDiag = GPIOD;
	pump[4].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[4].driver.pinReset = GPIO_Pin_8; //直流泵赋值使能引脚
	pump[4].driver.portReset = GPIOA;
	pump[4].driver.rccReset = RCC_AHB1Periph_GPIOA;

	PumpDriver_Init(&pump[4].driver);
	PumpDriver_PullLow(&pump[4].driver);
	PumpDriver_SetForwardLevel(&pump[4].driver,Bit_RESET);
	PumpDriver_Disable(&pump[4].driver);

	//泵6-直流泵4
	pump[5].driver.pinClock = GPIO_Pin_13; //直流泵无需脉冲，直接赋值悬空引脚
	pump[5].driver.portClock = GPIOC;
	pump[5].driver.rccClock = RCC_AHB1Periph_GPIOC;

	pump[5].driver.pinDir = GPIO_Pin_10;
	pump[5].driver.portDir = GPIOC;
	pump[5].driver.rccDir = RCC_AHB1Periph_GPIOC;

	pump[5].driver.pinDiag = GPIO_Pin_10; //直流泵无需故障检测，赋值蠕动泵引脚即可
	pump[5].driver.portDiag = GPIOD;
	pump[5].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[5].driver.pinReset = GPIO_Pin_3; //直流泵赋值使能引脚
	pump[5].driver.portReset = GPIOB;
	pump[5].driver.rccReset = RCC_AHB1Periph_GPIOB;

	PumpDriver_Init(&pump[5].driver);
	PumpDriver_PullLow(&pump[5].driver);
	PumpDriver_SetForwardLevel(&pump[5].driver,Bit_RESET);
	PumpDriver_Disable(&pump[5].driver);

	//泵7-直流泵5
	pump[6].driver.pinClock = GPIO_Pin_13; //直流泵无需脉冲，直接赋值悬空引脚
	pump[6].driver.portClock = GPIOC;
	pump[6].driver.rccClock = RCC_AHB1Periph_GPIOC;

	pump[6].driver.pinDir = GPIO_Pin_11;
	pump[6].driver.portDir = GPIOC;
	pump[6].driver.rccDir = RCC_AHB1Periph_GPIOC;

	pump[6].driver.pinDiag = GPIO_Pin_10; //直流泵无需故障检测，赋值蠕动泵引脚即可
	pump[6].driver.portDiag = GPIOD;
	pump[6].driver.rccDiag = RCC_AHB1Periph_GPIOD;

	pump[6].driver.pinReset = GPIO_Pin_4; //直流泵赋值使能引脚
	pump[6].driver.portReset = GPIOB;
	pump[6].driver.rccReset = RCC_AHB1Periph_GPIOB;

	PumpDriver_Init(&pump[6].driver);
	PumpDriver_PullLow(&pump[6].driver);
	PumpDriver_SetForwardLevel(&pump[6].driver,Bit_RESET);
	PumpDriver_Disable(&pump[6].driver);
}

