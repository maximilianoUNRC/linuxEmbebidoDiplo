#include <stdio.h>
#include <stdlib.h>

void show_vect(int *vect, int size) {
	int i;
	printf("Vector = [ ");
	for(i=0; i<size; i++)
		printf("%d ",vect[i]);
	printf("]\n");
	printf("\n");
}

int * create_vector(int * size){
	int *vector;
	int tam,i,elem;

	printf("Ingrese cantidad de elementos del vector: ");
	scanf("%d", &tam);

	vector = (int *)malloc(sizeof(int)*tam);

	if(vector==NULL) {
		printf("Error de asignacion de memoria\n");
		exit(1);
	}else{
		for(i=0; i<tam; i++){
			printf("Ingrese el elemento a cargar: ");
			scanf("%d",&elem);
			vector[i]=elem;
		}
		printf("\n");
	}
	(*size) = tam;
	return vector;
}


int * suma(int *vect1, int *vect2, int size){
	int *sum;
	int *result;
	int tam,i,elem;

	
	sum = (int *)malloc(sizeof(int)*size);
	result = &sum[0];

	if(sum==NULL) {
		printf("Error de asignacion de memoria\n");
		exit(1);
	}else{
		for(i=0; i<size; i++){
			*(result+i)=vect1[i]+vect2[i];
		}
	}
	return sum;
}


int main(){
	int *vector1;
	int *vector2;
	int *vector_suma;
	int vector_size1;
	int vector_size2;
	int vector_suma_size;

	
	vector1 = create_vector(&vector_size1);
	show_vect(vector1,vector_size1);

	vector2 = create_vector(&vector_size2);
	show_vect(vector2,vector_size2);

	//Los vectores deben ser del mismo tamaño
	vector_suma = suma(vector1,vector2,vector_size1);
	show_vect(vector_suma,vector_size1);
}
 