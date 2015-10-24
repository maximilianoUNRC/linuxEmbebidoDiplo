/*
Escribir un programa para calcular el factorial de un número entero n utilizando la siguiente
fórmula recursiva: n! = n * (n-1)! teniendo en cuenta que: 1! = 1. El factorial calcularlo
dentro de una función.
*/

#include <stdio.h>

int factorial(int n){
	if(n==1){
		return 1;
	}else{
		return n*factorial(n-1);
	}
}

int main(char argc, char * argv[]) {
	int a;
	
	printf("Introduzca el numero: ");
	scanf("%d",&a);

	printf("El factorial es %d \n",factorial(a));
}