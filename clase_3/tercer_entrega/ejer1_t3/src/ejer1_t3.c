/* Alumno: Correa, Carlos Maximiliano.
 * Crear un programa que prenda un led cuando se presione algún pulsador.
 * Nota: Usar GPIO3 para la salida del led
*/

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.


#define IOPIN_ 3
#define analog_Pin 1

int main() {

	mraa_result_t r = MRAA_SUCCESS;
	mraa_init();

	// Inicializacion de variables...
	mraa_gpio_context gpio = mraa_gpio_init_raw(IOPIN_);
	mraa_aio_context pulsador = mraa_aio_init(analog_Pin);

	// set direction to OUT
	r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
	if (r != MRAA_SUCCESS) {
		mraa_result_print(r);
	}


	for (;;) {
		if( mraa_aio_read(pulsador) == 0){ //el button esta conectado en pull-up
			r = mraa_gpio_write(gpio, 1);
		}else{
			r = mraa_gpio_write(gpio, 0);
		}
	}

	mraa_gpio_close(gpio);
	mraa_aio_close(pulsador);
	return r;

}
