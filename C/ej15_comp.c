/*
Escribir un programa que lea dos números enteros y escriba el mayor de los dos o un
mensaje si son iguales.
*/

#include <stdio.h>

void comp(int a, int b){
	if(a<b){
		printf("El numero %d es menor que %d \n",a,b);
	}else{
		if(b>a){
			printf("El numero %d es menor que %d \n",b,a);
		}else{
			printf("Los numeros son iguales \n");
		}
	}
}


int main(char argc, char * argv[]) {
	int a,b,c;
	
	printf("Introduce el primer numero: ");
	scanf("%d",&a);
	printf("Introduce el segundo numero: ");
	scanf("%d",&b);
	
	comp(a,b);

	
}