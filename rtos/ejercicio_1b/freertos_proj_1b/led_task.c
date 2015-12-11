//*****************************************************************************
//
// led_task.c - A simple flashing LED task.
//
// Copyright (c) 2012-2015 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.1.71 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "drivers/rgb.h"
#include "drivers/buttons.h"
#include "utils/uartstdio.h"
#include "led_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

//*****************************************************************************
//
// The stack size for the LED toggle task.
//
//*****************************************************************************
#define LEDTASKSTACKSIZE        128         // Stack size in words


//*****************************************************************************
//
// Default LED delay value.
//
//*****************************************************************************
#define LED_DELAY1        1000
#define LED_DELAY2        2000

//*****************************************************************************
//
// This task toggles the user selected LED at a user selected frequency. User
// can make the selections by pressing the left and right buttons.
//
//*****************************************************************************
void LEDTask1(void *pvParameters)
{
    portTickType ui32WakeTime;
    uint32_t ui32LEDDelay;

    ui32LEDDelay = LED_DELAY1;
    ui32WakeTime = xTaskGetTickCount();

    while(1)
    {
    	GPIOPinWrite(GPIO_PORTF_BASE, 0x08, 0x08);
        vTaskDelayUntil(&ui32WakeTime, ui32LEDDelay / portTICK_RATE_MS);
        GPIOPinWrite(GPIO_PORTF_BASE, 0x08, 0x00);
        vTaskDelayUntil(&ui32WakeTime, ui32LEDDelay / portTICK_RATE_MS);
    }
}

//*****************************************************************************
//*****************************************************************************
//
// This task toggles the user selected LED at a user selected frequency. User
// can make the selections by pressing the left and right buttons.
//
//*****************************************************************************
void LEDTask2(void *pvParameters)
{
    portTickType ui32WakeTime;
    uint32_t ui32LEDDelay;

    ui32LEDDelay = LED_DELAY2;
    ui32WakeTime = xTaskGetTickCount();

    while(1)
    {
    	GPIOPinWrite(GPIO_PORTF_BASE, 0x02, 0x02);
        vTaskDelayUntil(&ui32WakeTime, ui32LEDDelay / portTICK_RATE_MS);
        GPIOPinWrite(GPIO_PORTF_BASE, 0x02, 0x00);
        vTaskDelayUntil(&ui32WakeTime, ui32LEDDelay / portTICK_RATE_MS);
    }
}

//*****************************************************************************

//
// Initializes the LED task.
//
//*****************************************************************************
uint32_t
LEDTaskInit(void)
{

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, 0x08 | 0x02);

    xTaskCreate(LEDTask1, (signed portCHAR *)"LED_1", LEDTASKSTACKSIZE, NULL,tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(LEDTask2, (signed portCHAR *)"LED_2", LEDTASKSTACKSIZE, NULL,tskIDLE_PRIORITY + 3, NULL);

    return(0);
}
