/*
Escribir un programa que lea un carácter y escriba el mismo carácter y su código ASCII
*/

#include <stdio.h>


int main(char argc, char * argv[]) {
	
	char letra,ascii;

	printf("Ingresa un caracter: ");     
   	scanf("%c",&letra);
   	getchar();    
    printf("\n");
    ascii = letra;

    printf("El caracter %c tiene codigo ascii: %d\n\n",letra,ascii);

}