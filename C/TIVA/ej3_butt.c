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
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08

int btnIzq = 1;
int btnDer = 1;

void onButtonDown(void);
void onButtonUp(void);

void onButtonDown(void) {
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
        // PF4 was interrupt cause
    	btnIzq=0;
        GPIOIntRegister(GPIO_PORTF_BASE, onButtonUp);   // Register our handler function for port F
        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4,
            GPIO_RISING_EDGE);          // Configure PF4 for rising edge trigger
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);  // Clear interrupt flag
    }
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_0) {
    	// PF0 was interrupt cause
        btnDer=0;
        GPIOIntRegister(GPIO_PORTF_BASE, onButtonUp);   // Register our handler function for port F
        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0,
        GPIO_RISING_EDGE);          // Configure PF0 for rising edge trigger
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_0);  // Clear interrupt flag
    }
}

void onButtonUp(void) {
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
        // PF4 was interrupt cause
    	btnIzq=1;
        GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown); // Register our handler function for port F
        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4,
            GPIO_FALLING_EDGE);         // Configure PF4 for falling edge trigger
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);  // Clear interrupt flag
    }
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_0) {
    	// PF0 was interrupt cause
    	btnDer=1;
    	GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown); // Register our handler function for port F
    	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0,
    			GPIO_FALLING_EDGE);         // Configure PF0 for falling edge trigger
    	GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_0);  // Clear interrupt flag
    }
}


void GPIOPinUnlockGPIO(uint32_t ui32Port, uint8_t ui8Pins) {
    HWREG(ui32Port + GPIO_O_LOCK) = GPIO_LOCK_KEY;      // Unlock the port
    HWREG(ui32Port + GPIO_O_CR) |= ui8Pins;             // Commit specified pins for next access
    HWREG(ui32Port + GPIO_O_AFSEL) &= ~ui8Pins;         // Function: GPIO (disable alternate function)
    HWREG(ui32Port + GPIO_O_DEN) &= ~ui8Pins;           // Disable digital driver
    HWREG(ui32Port + GPIO_O_LOCK) = 0;                  // Lock the port
}


int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    // Pin F4 setup
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);        // Enable port F
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED );
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);  // Init PF4 as input
    GPIOPinUnlockGPIO(GPIO_PORTF_BASE, GPIO_PIN_0);     // Configure PF0 as GPIO
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);  // Init PF0 as input
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4,
        GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);  // Enable weak pullup resistor for PF4
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0,
            GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);  // Enable weak pullup resistor for PF0

    // Interrupt setuü
    GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);        // Disable interrupt for PF4 (in case it was enabled)
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);      // Clear pending interrupts for PF4
    GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown);     // Register our handler function for port F
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0,
        GPIO_FALLING_EDGE);             // Configure PF4 for falling edge trigger
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);     // Enable interrupt for PF4

    while(1) {

    	if(btnIzq == 1 && btnDer == 1){
    		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , GREEN_LED);
    		SysCtlDelay(2000000);
    		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , 0x00);
    		SysCtlDelay(2000000);
    	}else{
    		if(btnIzq == 0){
    			GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , BLUE_LED);
    			SysCtlDelay(2000000);
    			GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , 0x00);
    			SysCtlDelay(2000000);
    		}else{
    			GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , RED_LED);
    			SysCtlDelay(2000000);
    			GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED | RED_LED | BLUE_LED , 0x00);
    			SysCtlDelay(2000000);
    		}
    	}


    }
}
