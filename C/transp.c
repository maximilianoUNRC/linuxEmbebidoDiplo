#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
				matrix[i][j]=(int)pow((double)(i+2*j),(double)2);
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

int ** transp(int **matrix, int row, int col) {
	int i,j;
	int **res;

	res = (int **)malloc (row*sizeof(int *));
	for (i=0;i<row;i++)
		res[i] = (int *) malloc (col*sizeof(int));

	for(i=0; i<row; i++){
		for (j = 0; j < col; j++) {
			res[i][j]=matrix[j][i];
		}
	}

	return res;	
}



int main(){

	int **matrix;
	int columns,rows;

	int ** result;

	matrix = create_matrix(&rows,&columns);
	show_matrix(matrix,rows,columns);

	printf("Transpuesta:\n");
	result = transp(matrix,rows,columns);
	show_matrix(result,rows,columns);
}
 