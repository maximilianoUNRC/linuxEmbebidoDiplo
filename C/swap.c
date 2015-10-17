#include <stdio.h>

void swap_copy (int a, int b){
	int aux;
	aux=a;
	a=b;
	b=aux;
	printf("En swap_copy: num1 = %d num2 = %d \n",a,b);
	return;
}

void swap_reference (int *a, int *b){
	int aux;
	aux=(*a);
	(*a)=(*b);
	(*b)=aux;
	printf("En swap_reference: num1 = %d num2 = %d \n",*a,*b);
	return;	
}

int main (){
	int num1 = 4;
	int num2 = 6;

	printf("En main: num1 = %d num2 = %d \n",num1,num2);
	printf("\n");
	
	swap_copy(num1,num2);
	printf("num1 = %d num2 = %d \n",num1,num2);
	printf("\n");

	swap_reference(&num1,&num2);
	printf("num1 = %d num2 = %d \n",num1,num2);	
	printf("\n");

	return 0;
}