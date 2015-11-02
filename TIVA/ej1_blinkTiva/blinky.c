//*****************************************************************************
// Ej 1) Crear un proyecto nuevo en donde se utilice como periferico led y se encienda
// parpadeante (blink) sobre color verde (green).
//
// blinky.c - Correa, Maximiliano - Galfioni, Adrian.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#define GREEN_LED 0x08

int
main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GREEN_LED);

    //
    // Loop forever.
    //
    while(1)
    {
    	//
    	// Turn on the LED whit green.
    	//
    	GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | 0x02 | 0x04 ,GREEN_LED);

        SysCtlDelay(2000000);

        //
        // Turn off the LED.
        //
    	GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);

    	SysCtlDelay(2000000);
    }
}
