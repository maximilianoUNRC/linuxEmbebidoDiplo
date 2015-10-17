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