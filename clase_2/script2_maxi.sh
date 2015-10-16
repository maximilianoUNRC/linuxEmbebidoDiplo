#!/bin/ash

echo "Se muestra en pantalla esta linea"
$(echo "contenido a colocar en el archivo maxi" > archivo_maxi.txt)
$(chmod 777 archivo_maxi.txt)
echo "Se escribio... "
cat archivo_maxi.txt

