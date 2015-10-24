/*
Escribir un programa usando una función que muestre el máximo de tres números
ingresados por teclado.
*/

#include <stdio.h>

int max(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}

int main(char argc, char * argv[]) {
	int a,b,c;
	
	printf("Introduce el primer numero: ");
	scanf("%d",&a);
	printf("Introduce el segundo numero: ");
	scanf("%d",&b);
	printf("Introduce el tercer numero: ");
	scanf("%d",&c);

	printf("El mayor numero es %d \n",max(a,max(b,c)));
}