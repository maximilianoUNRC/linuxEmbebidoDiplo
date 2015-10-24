/*
Escribir un programa usando funciones que ordene un vector usando el método de la
burbuja. Éste consiste en ciclar repetidamente a través de la lista, comparando elementos
adyacentes de dos en dos. Si un elemento es mayor que el que está en la siguiente posición
se intercambian.
*/

#include <stdio.h>

void bubble_sort(int nums[]){
	int sorted = 0;
	int i;
	while(sorted == 0){
		sorted=1;
		for (i = 0; i<= 8; ++i){
			if(nums[i]>nums[i+1]){
				int aux;
				aux=nums[i];
				nums[i]=nums[i+1];
				nums[i+1]=aux;

				sorted=0;
			}
		}	
	}
}

void show(int nums[]){
	int i;
	for (i = 0; i<= 9; ++i)	{
		printf("%d ", nums[i]);
	}	
}

int main(char argc, char * argv[]) {
	int numeros[]={1,2,3,12,98,65,23,11,67,5};

	bubble_sort(numeros);
	show(numeros);

}