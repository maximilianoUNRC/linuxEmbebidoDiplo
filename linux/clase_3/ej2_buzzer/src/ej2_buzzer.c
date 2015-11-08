#include <unistd.h>
#include "mraa.h"

int main()
{
    mraa_init();
    mraa_pwm_context pwm;
    pwm = mraa_pwm_init(5);


    mraa_pwm_period_us(pwm, 1000000);
    mraa_pwm_enable(pwm, 1);

    float duty_in = 0.0f;
    float inc = 0.01f;
    float duty_out;

    while (1) {
        duty_in = duty_in + inc;
        mraa_pwm_write(pwm, duty_in);
        usleep(25000);
        if ((duty_in >= 1.3f) || (duty_in <= 0.0f)) {
            inc = -inc;
        }
        duty_out = mraa_pwm_read(pwm);
        printf("%f\n",duty_in);
    }

    return 0;
}
