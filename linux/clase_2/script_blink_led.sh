#!/bin/ash

#Inicializacion de estados
echo -n "55" > /sys/class/gpio/export
echo -n "out" > /sys/class/gpio/gpio55/direction
echo -n "1" > /sys/class/gpio/gpio55/value #HIGH

echo -n "39" > /sys/class/gpio/export
echo -n "out" > /sys/class/gpio/gpio39/direction

echo -n "26" > /sys/class/gpio/export
echo -n "in" > /sys/class/gpio/gpio26/direction

#iteracion de actuacion
while true
do 
	if [ $(cat /sys/class/gpio/gpio26/value) = 1 ]
	then 
		echo -n "1" > /sys/class/gpio/gpio39/value #On
	else
		echo -n "0" > /sys/class/gpio/gpio39/value #Off
	fi
done
