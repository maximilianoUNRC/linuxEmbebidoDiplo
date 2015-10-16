#!/bin/ash

local hora
hora=$(date)
$(sleep 10)

while true
do
	echo ${hora}
	hora=$(date)
	$(sleep 1s)
done
