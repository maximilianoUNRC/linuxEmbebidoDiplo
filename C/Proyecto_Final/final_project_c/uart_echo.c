//*****************************************************************************
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "../../SW-TM4C-2.1.1.71/inc/hw_ints.h"
#include "../../SW-TM4C-2.1.1.71/inc/hw_memmap.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/debug.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/fpu.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/gpio.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/interrupt.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/pin_map.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/rom.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/sysctl.h"
#include "../../SW-TM4C-2.1.1.71/driverlib/uart.h"

char command[] = { '0', '0', '0', '0', '0', '0', '0' ,'0'};
char msg_ack[] = { 'A', 'C', 'K', '0' };
char msg_nack[] = { 'N', 'A', 'C', 'K', '0' };
int i = 0;
char my_Id = '0';

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


//*****************************************************************************
//
// The UART interrupt handler.
//
//*****************************************************************************
void UARTIntHandler(void) {
	// mismo tratamiento de msg
		uint32_t ui32Status;
		int stringComplete = 0;
		int ok = 0;

		ui32Status = ROM_UARTIntStatus(UART0_BASE, true);
		ROM_UARTIntClear(UART0_BASE, ui32Status);

		while (ROM_UARTCharsAvail(UART0_BASE)) {
			command[i] = (char) ROM_UARTCharGetNonBlocking(UART0_BASE);

			if (command[i] == '*') {
				stringComplete = 1;
			}

			i++;
		}

		if (stringComplete) {
			i = 0;
			if (command[0] == my_Id) {
				stringComplete = 0;
				i = 0;
				char opc = command[2];
				switch (opc) {
				case 'B':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
					}
					break;
				case 'R':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
					}
					break;
				case 'G':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
					}
					break;
				default:
					break;
				}

				i = 0;
				int j = 0;
				if (ok) {
					while (msg_ack[j] != '0') {
						ROM_UARTCharPutNonBlocking(UART0_BASE, msg_ack[j]);
						j++;
					}
				} else {
					while (msg_nack[j] != '0') {
						ROM_UARTCharPutNonBlocking(UART0_BASE, msg_nack[j]);
						j++;
					}
				}
			memset(command, 0x00, 6);
		}else {
			int j = 0;
			// tratamineto  de mensajes a la Otra TIVA por el UART1...
			while(command[j] != '0'){
				ROM_UARTCharPutNonBlocking(UART1_BASE, command[j]);
			}
			memset(command, 0x00, 6);
		}
	}

}

//---------------------------------------------------------------------------------
void UART1IntHandler(void){
	// mismo tratamiento de msg
		uint32_t ui32Status;
		int stringComplete = 0;
		int ok = 0;

		ui32Status = ROM_UARTIntStatus(UART1_BASE, true);
		ROM_UARTIntClear(UART1_BASE, ui32Status);

		while (ROM_UARTCharsAvail(UART1_BASE)) {
			command[i] = (char) ROM_UARTCharGetNonBlocking(UART1_BASE);

			if (command[i] == '*') {
				stringComplete = 1;
			}

			i++;
		}

		if (stringComplete) {
			i = 0;
			if (command[0] == my_Id) {
				stringComplete = 0;
				i = 0;
				char opc = command[2];
				switch (opc) {
				case 'B':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
					}
					break;
				case 'R':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
					}
					break;
				case 'G':
					ok = 1;
					if (command[4] == 'U') {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
					} else {
						//
						// Turn off the LED
						//
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
					}
					break;
				default:
					break;
				}

				i = 0;
				int j = 0;
				if (ok) {
					while (msg_ack[j] != '0') {
						ROM_UARTCharPutNonBlocking(UART0_BASE, msg_ack[j]);
						j++;
					}
				} else {
					while (msg_nack[j] != '0') {
						ROM_UARTCharPutNonBlocking(UART0_BASE, msg_nack[j]);
						j++;
					}
				}
			memset(command, 0x00, 6);
		}else {
			int j = 0;
			// tratamineto  de mensajes a la Otra TIVA por el UART1...
			while(command[j] != '*'){
				ROM_UARTCharPutNonBlocking(UART1_BASE, command[j]);
			}
			memset(command, 0x00, 6);
		}
	}
 }

//*****************************************************************************
//
// Redefinir el UART1
//
//*****************************************************************************
void UARTSend(const uint8_t *pui8Buffer, uint32_t ui32Count) {
	//
	// Loop while there are more characters to send.
	//
	while (ui32Count--) {
		//
		// Write the next character to the UART.
		//
		ROM_UARTCharPutNonBlocking(UART0_BASE, *pui8Buffer++);
	}
}

//*****************************************************************************
//
// This example demonstrates how to send a string of data to the UART.
//
//*****************************************************************************
int main(void) {
	//
	// Enable lazy stacking for interrupt handlers.  This allows floating-point
	// instructions to be used within interrupt handlers, but at the expense of
	// extra stack usage.
	//
	ROM_FPUEnable();
	ROM_FPULazyStackingEnable();

	//
	// Set the clocking to run directly from the crystal.
	//
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
	SYSCTL_XTAL_16MHZ);

	//
	// Enable the GPIO port that is used for the on-board LED.
	//
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	//
	// Enable the GPIO pins for the LED (PF2).
	//
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE ,
			GPIO_PIN_2 | GPIO_PIN_1 | GPIO_PIN_3);


	//
	// Enable the peripherals used by this example.
	//
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);



	//
	// Set GPIO A0 and A1 as UART pins.
	//
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	//
	// Set GPIO A0 and A1 as UART pins.
	//
	GPIOPinConfigure(GPIO_PB0_U1RX);
	GPIOPinConfigure(GPIO_PB1_U1TX);
	ROM_GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	ROM_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);

	//
	// Configure the UART for 115,200, 8-N-1 operation.
	//
	ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
			(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			UART_CONFIG_PAR_NONE));

	ROM_UARTConfigSetExpClk(UART1_BASE, ROM_SysCtlClockGet(), 115200,
				(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
				UART_CONFIG_PAR_NONE));

	//
	// Enable the UART0 interrupt.
	//
	ROM_IntEnable(INT_UART0);
	ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

	//
	// Enable the UART1 interrupt.
	//
	ROM_IntEnable(INT_UART1);
	ROM_UARTIntEnable(UART1_BASE, UART_INT_RX | UART_INT_RT);

	// Prompt for text to be entered.
	//

	// seteo de
	UARTSend((uint8_t *) "Ingrese ID: ", 12);
	while(my_Id == '0'){
		my_Id = (char) ROM_UARTCharGet(UART0_BASE);
	}
	ROM_UARTCharPut(UART0_BASE, my_Id);

	//
	// Enable processor interrupts.
	//
	ROM_IntMasterEnable();


	//
	// Loop forever echoing data through the UART.
	//
	while (1) {
	}
}
