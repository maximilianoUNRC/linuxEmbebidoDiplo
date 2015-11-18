/* Alumno: Correa, Carlos Maximiliano.
 * Agregar al EJERCICIO_1 el uso de un Buzzer, mediante la implementación
 * del módulo PWM.
 * Nota: Usar en modo salida el D5 del Shield de expansión
 */

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"

#define PWMPIN_ 3 //El buzzer en mi shield esta en el pin ~3
#define LEDPIN_ 3 // Led pin 3 digital propio de la placa intel galileo.

int main() {

	mraa_result_t r = MRAA_SUCCESS;
	mraa_init();

	// Inicializacion de variables...
    mraa_pwm_context pwm = mraa_pwm_init(PWMPIN_);
    mraa_pwm_period_us(pwm, 200);
    mraa_pwm_enable(pwm, 1);

    mraa_gpio_context gpio_led = mraa_gpio_init_raw(LEDPIN_);
    mraa_gpio_dir(gpio_led, MRAA_GPIO_OUT);

    mraa_gpio_context gpio_1 = mraa_gpio_init_raw(36);
	mraa_gpio_dir(gpio_1, MRAA_GPIO_OUT);
	mraa_gpio_write(gpio_1, 1);
	mraa_gpio_context gpio_2 = mraa_gpio_init_raw(45);
	mraa_gpio_dir(gpio_2, MRAA_GPIO_IN);

	for (;;) {
		if(mraa_gpio_read(gpio_2) == 0 ){ //el button esta conectado en pull-up
	        mraa_pwm_write(pwm, 0.0f);
			mraa_gpio_write(gpio_led, 1);
		}else{
			mraa_pwm_write(pwm, 1.0f);
			mraa_gpio_write(gpio_led, 0);
		}
		 usleep(50000);
	}

	mraa_gpio_close(gpio_led);
	mraa_gpio_close(gpio_1);
	mraa_gpio_close(gpio_2);

	return r;

}
