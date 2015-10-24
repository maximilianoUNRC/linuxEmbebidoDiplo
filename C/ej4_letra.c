/*
Escribir un programa usando una función que inserte un carácter en una determinada
posición de una cadena.
*/

#include <stdio.h>

int insert(char str[], char c, int pos){
	str[pos]=c;
}

int main(char argc, char * argv[]) {
	char word[]="palabra";
	

	insert(word,'t',4);
	
	printf("Palabra: %s \n",word);
}