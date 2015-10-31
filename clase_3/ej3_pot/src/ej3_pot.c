#include <unistd.h>
#include "mraa.h"

int main()
{
    mraa_init();
    mraa_pwm_context pwm;
    pwm = mraa_pwm_init(5);

    mraa_aio_context pot;
    pot = mraa_aio_init(0);
    if (pot == NULL) {
        return 1;
    }

    mraa_pwm_enable(pwm, 1);
    mraa_pwm_write(pwm,0.5f);


    unsigned int duty_in = 0;
    //float duty_out;

    while (1) {
        duty_in = mraa_aio_read(pot);
        //mraa_pwm_write(pwm,duty_in);

        mraa_pwm_period_us(pwm, duty_in);
        usleep(25000);
        /*if ((duty_in >= 1.3f) || (duty_in <= 0.0f)) {
            inc = -inc;
        }
        duty_out = mraa_pwm_read(pwm);*/
        printf("%d\n",duty_in);
    }

    return 0;
}
