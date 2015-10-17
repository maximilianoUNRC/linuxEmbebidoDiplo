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


int ** create_matrix(int * row, int * column){
	int **matrix;
	int rows,columns,i,j,elem;

	printf("Ingrese cantidad de filas: ");
	scanf("%d", &rows);

	printf("Ingrese cantidad de columnas: ");
	scanf("%d", &columns);

	matrix = (int **)malloc (rows*sizeof(int *));
	for (i=0;i<rows;i++)
		matrix[i] = (int *) malloc (columns*sizeof(int));

	

	if(matrix==NULL) {
		printf("Error de asignacion de memoria\n");
		exit(1);
	}else{
		for(i=0; i<rows; i++){
			for (j = 0; j < columns; j++)
			{
				printf("Ingrese el elemento a cargar: ");
				scanf("%d",&elem);
				matrix[i][j]=elem;
			}
		}
		printf("\n");
	}
	(*row) = rows;
	(*column) = columns;

	return matrix;
}

void show_matrix(int **matrix, int row, int col) {
	int i,j;
	printf("Matriz \n");
	for(i=0; i<row; i++){
		printf("[ ");
		for (j = 0; j < col; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("]\n");
	}	
	printf("\n");
}

int ** prod(int *vect, int size, int **matrix, int row, int col){
	int **res; 
	int i,j,aux;

	if(size != col){
		printf("No es posible multiplicar el vector por la matriz\n");
		printf("El número de filas del vector debe ser igual a las columnas de la matriz\n");
		return;
	}else{
		res = (int **)malloc (row*sizeof(int *));
		for (i=0;i<row;i++)
			res[i] = (int *) malloc (sizeof(int));

		for(i=0; i<row; i++){
			aux=0;
			for (j = 0; j < size; j++){
				aux=aux+matrix[i][j]*vect[j];
			}
			res[i][0]=aux;
		}
		return res;
	}
}


int main(){
	int *vector;
	int vector_size;

	int **matrix;
	int columns,rows;

	int ** result;

	vector = create_vector(&vector_size);
	show_vect(vector,vector_size);

	matrix = create_matrix(&rows,&columns);
	show_matrix(matrix,rows,columns);

	result = prod(vector,vector_size,matrix,rows,columns);
	show_matrix(result,rows,1);
}
 