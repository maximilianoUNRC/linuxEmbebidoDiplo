/* Alumno: Correa, Carlos Maximiliano.
 * Crear un programa que prenda un led cuando se presione algún pulsador.
 * Nota: Usar GPIO3 para la salida del led
 * Comentario: Tener en cuenta el esquematico agregado en la carpeta..
*/

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"

#define IOPIN_ 3

int main() {

	mraa_result_t r = MRAA_SUCCESS;
	mraa_init();

	// Inicializacion de variables...
	mraa_gpio_context gpio_1 = mraa_gpio_init_raw(36);
	mraa_gpio_dir(gpio_1, MRAA_GPIO_OUT);
	mraa_gpio_write(gpio_1, 1);
	mraa_gpio_context gpio_2 = mraa_gpio_init_raw(45);
	mraa_gpio_dir(gpio_2, MRAA_GPIO_IN);

	mraa_gpio_context gpio = mraa_gpio_init_raw(IOPIN_);
    mraa_gpio_dir(gpio, MRAA_GPIO_OUT);


	for (;;) {
		if(mraa_gpio_read(gpio_2) == 0 ){ //el button esta conectado en pull-up en el Analogico "0"
			mraa_gpio_write(gpio, 1);
		}else{
			mraa_gpio_write(gpio, 0);
		}
	}

	mraa_gpio_close(gpio);
	mraa_gpio_close(gpio_1);
	mraa_gpio_close(gpio_2);
	return r;

}
