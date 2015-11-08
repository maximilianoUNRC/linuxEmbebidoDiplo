#!/bin/ash
echo "Comienzo del bucle"
for i in $(seq 0 5)
do
	echo $(date -u)
	$(sleep ls)
done
echo "Fin del bucle"

