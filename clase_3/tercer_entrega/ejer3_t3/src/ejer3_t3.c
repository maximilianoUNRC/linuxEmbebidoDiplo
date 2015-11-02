/* Alumno: Correa, Carlos Maximiliano.
* Reutilizando el código del EJERCICIO_2, modificar el periodo o frecuencia del tono
* mediante el uso del conversor A/D. Nota: Usar el la entrada A0 del Shield de expansión.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.


#define IOPIN_ 3 //El buzzer en mi shield esta en el pin ~3
#define analog_Pin_0 0 // El potenciometro esta conectado al analogico_0
#define analog_Pin_1 1 // El pulsador esta conectado en pull-up al analogico_1

int main() {


	// Setup()
	mraa_init();
	mraa_pwm_context pwm = mraa_pwm_init(IOPIN_);
	mraa_aio_context pot = mraa_aio_init(analog_Pin_0);
	mraa_aio_context pulsador = mraa_aio_init(analog_Pin_1);
	mraa_pwm_enable(pwm, 1);
	mraa_pwm_write(pwm,0.5f);


	// Loop()
	for (;;) {
		if( mraa_aio_read(pulsador) == 0){ //el button esta conectado en pull-up
	        mraa_pwm_period_us(pwm, mraa_aio_read(pot));
	        usleep(25000);
	        printf("%d\n",mraa_aio_read(pot));

		}
	}

	mraa_aio_close(pot);
	mraa_aio_close(pulsador);

	return MRAA_SUCCESS;

}

