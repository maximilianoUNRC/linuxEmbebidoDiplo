/* Alumno: Correa, Carlos Maximiliano.
* Reutilizando el código del EJERCICIO_2, modificar el periodo o frecuencia del tono
* mediante el uso del conversor A/D. Nota: Usar el la entrada A0 del Shield de expansión.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"

#define PWMPIN_ 3 //El buzzer en mi shield esta en el pin ~3
#define LEDPIN_ 3 // Led pin 3 digital propio de la placa intel galileo.
#define analog_Pin_0 0 // El potenciometro esta conectado al analogico_0

int main() {


	// Setup()
	mraa_init();

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

	mraa_aio_context pot = mraa_aio_init(analog_Pin_0);

	// var auxiliar
	unsigned int value = 0;

	// Loop()
	for (;;) {
		value = mraa_aio_read(pot);
		printf("%d\n",value);

		if(mraa_gpio_read(gpio_2) == 0 ){ //el button esta conectado en pull-up ; 0 == HIGH
			 	 	mraa_pwm_period_us(pwm, value);
					mraa_gpio_write(gpio_led, 1);
				}else{
					mraa_pwm_period_us(pwm, 200);
					mraa_gpio_write(gpio_led, 0);
				}
		 usleep(50000);
	}

	mraa_aio_close(pot);
	mraa_gpio_close(gpio_led);
	mraa_gpio_close(gpio_1);
	mraa_gpio_close(gpio_2);

	return MRAA_SUCCESS;
}

