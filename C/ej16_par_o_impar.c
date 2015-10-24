/*
Escribir un programa que lea un número e imprima un mensaje “Par” o “Impar”.
*/

#include <stdio.h>
#include <math.h>

void comp(int a){
	if(a%2==0){
		printf("Es par\n");
	}else{
		printf("Es impar\n");
	}
}


int main(char argc, char * argv[]) {
	int a;
	
	printf("Introduce el numero: ");
	scanf("%d",&a);
		
	comp(a);
}