#!/bin/ash

echo "se muestra en pantalla esta linea"

$(echo "Contenido a colocar en Adri" > archivo.txt)

echo "Se escribio el archivo..."

cat archivo.txt
