/*
Realizar un programa que lea dos números y aplique sobre ellos todos los operadores
aritméticos (incluyendo el pre y post incremento y decremento).
*/

#include <stdio.h>

void arit(int a,int b){
	
	printf("%d+%d=%d \n", a,b,a+b);	
	printf("%d-%d=%d \n", a,b,a-b);	
	printf("%d*%d=%d \n", a,b,a*b);	
	printf("%d/%d=%d (división entera) \n", a,b,(int)a/b);	
	printf("Valor de a=%d \n",a);
	printf("Posincremento de %d \n", a++);	
	printf("Valor de a=%d \n",a);
	printf("Predecremento de %d \n", a--);	
	printf("Valor de a=%d \n",a);
}


int main(char argc, char * argv[]) {
	int a,b;
	
	printf("Introduce el primer numero: ");
	scanf("%d",&a);
	
	printf("Introduce el segundo numero: ");
	scanf("%d",&b);
	
	arit(a,b);
}