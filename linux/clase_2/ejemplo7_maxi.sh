#!/bin/ash
local1 hora
hora = $(date)
$(sleep 10)

while true
do 
	echo ${hora}
	hora=$(date)
	$(sleep ls)
done


