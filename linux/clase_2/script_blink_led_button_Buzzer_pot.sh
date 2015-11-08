#!/bin/ash

#local var

local variable
variable=0

#Inicializacion de estados
echo -n "55" > /sys/class/gpio/export
echo -n "out" > /sys/class/gpio/gpio55/direction
echo -n "1" > /sys/class/gpio/gpio55/value #HIGH

echo -n "39" > /sys/class/gpio/export
echo -n "out" > /sys/class/gpio/gpio39/direction

echo -n "26" > /sys/class/gpio/export
echo -n "in" > /sys/class/gpio/gpio26/direction

echo -n "5" > /sys/class/pwm/pwmchip0/export
echo -n "1" > /sys/class/pwm/pwmchip0/pwm5/enable

echo -n "0" > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo -n "1000000" > /sys/class/pwm/pwmchip0/pwm5/period

echo -n "37" > /sys/class/gpio/export
echo -n "out" > /sys/class/gpio/gpio37/direction
echo -n "0" > /sys/class/gpio/gpio37/value

#iteracion de actuacion
while true
do 
	
	variable=$(expr $(cat /sys/bus/iio/devices/iio\:device0/in_voltage0_raw) \* 120)	

	if [ $(cat /sys/class/gpio/gpio26/value) = 1 ]
	then 
		echo -n "1" > /sys/class/gpio/gpio39/value #On
		echo -n ${variable} > /sys/class/pwm/pwmchip0/pwm5/duty_cycle	

	fi
done
