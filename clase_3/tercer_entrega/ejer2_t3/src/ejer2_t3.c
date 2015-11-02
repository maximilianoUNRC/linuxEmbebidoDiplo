/* Alumno: Correa, Carlos Maximiliano.
 * Agregar al EJERCICIO_1 el uso de un Buzzer, mediante la implementación
 * del módulo PWM.
 * Nota: Usar en modo salida el D5 del Shield de expansión
*/

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.


#define IOPIN_ 3 //El buzzer en mi shield esta en el pin ~3
#define analog_Pin 1 // El pulsador esta conectado en pull-up al analogico_1

int main() {

	mraa_result_t r = MRAA_SUCCESS;
	mraa_init();

	// Inicializacion de variables...
	mraa_gpio_context gpio = mraa_gpio_init(IOPIN_);
	mraa_aio_context pulsador = mraa_aio_init(analog_Pin);

	// set direction to OUT
	r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
	if (r != MRAA_SUCCESS) {
		mraa_result_print(r);

	}

	for (;;) {
		if( mraa_aio_read(pulsador) == 0){ //el button esta conectado en pull-up
			r = mraa_gpio_write(gpio, 0);
		}else{
			r = mraa_gpio_write(gpio, 1);
		}
	}

	mraa_gpio_close(gpio);
	mraa_aio_close(pulsador);
	return r;

}
