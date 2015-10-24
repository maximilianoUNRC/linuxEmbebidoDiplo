/*
Leer un carácter y dos números enteros. Si el carácter leído es un operador aritmético
calcular la operación correspondiente, si es cualquier otro mostrar error. Hacer el programa
utilizando if-else.
*/

#include <stdio.h>

void arit(int a,int b, char c){
	if(c=='+'){
		printf("%d \n", a+b);	
	}else{
		if(c=='-'){
			printf("%d \n", a-b);	
		}else{
			if(c=='*'){
				printf("%d \n", a*b);	
			}else{
				if(c=='/'){
					printf("%d \n", (int)a/b);	
				}else{
					printf("ERROR\n");
				}			
			}		
		}	
	}
	
	
	
	
}


int main(char argc, char * argv[]) {
	int a,b;
	char c;

	printf("Introduce el caracter: ");
	fflush(stdin);
	scanf("%c",&c);
	getchar();
	
	printf("Introduce el primer numero: ");
	scanf("%d",&a);
	
	printf("Introduce el segundo numero: ");
	scanf("%d",&b);

	
	arit(a,b,c);
}