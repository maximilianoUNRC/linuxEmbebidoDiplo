#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#include "FreeRTOS.h"
#include "task.h"

#define GREEN_LED	0x08
#define PRIORITY_LED_TASK	1
#define LEDTASKSTACKSIZE	128

/*
 * main.c
 */
int main(void) {

	//
	// Set the clocking to run at 50 MHz from the PLL.
	//
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);


	//
	// Create the LED task.
	//
	if(LEDTaskInit() != 0)
	{
		while(1)
		{
		}
	}

	//
	// Start the scheduler.  This should not return.
	//
	vTaskStartScheduler();
	
	//
	// In case the scheduler returns for some reason, print an error and loop
	// forever.
	//

	while(1)
	{
	}
}
