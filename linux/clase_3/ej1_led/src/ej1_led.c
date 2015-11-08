#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include "gpio.h"

static int iopin;

#define DEFAULT_IOPIN 3

int main() {

	mraa_result_t r = MRAA_SUCCESS;

	iopin = DEFAULT_IOPIN;
	mraa_init();

	mraa_gpio_context gpio;
	gpio = mraa_gpio_init_raw(iopin);
	if (gpio == NULL) {
		fprintf(stderr, "Are you sure that pin%d you requested is valid on your platform?", iopin);
	    exit(1);
	}
	printf("Initialised pin %d \n", iopin);

	// set direction to OUT
	r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
	if (r != MRAA_SUCCESS) {
		mraa_result_print(r);
	}


	for (;;) {
		r = mraa_gpio_write(gpio, 1);
		sleep(1);
		r = mraa_gpio_write(gpio, 0);
		sleep(1);

	}

	mraa_gpio_close(gpio);

	return 0;
}
