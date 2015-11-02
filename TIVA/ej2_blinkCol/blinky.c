//*****************************************************************************
//
// Ej 2) Tomar como base el ej1 pero ahora que el led se encienda
// también sobre los colores rojo (red) y azul (blue).
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

#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08

int
main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED );

    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED whit green.
        //
    	GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , GREEN_LED);


    	SysCtlDelay(2000000);

    	//
        // Turn on the LED with red.
        //
    	GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , RED_LED);


        SysCtlDelay(2000000);

        //
        // Turn on the LED with blue.
        //
        GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , BLUE_LED);

        SysCtlDelay(2000000);
    }
}
