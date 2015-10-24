/*
Escribir un programa que lea un texto y lo escriba convertido todo a mayúsculas. Tener en
cuenta que la diferencia entre el código ASCII de una letra mayúscula y el de la misma letra
en minúscula es un número constante.
*/

#include <stdio.h>


int main(char argc, char * argv[]) {
	
	int row=(300/20)+1;
    int col=2;
    int i,j;
	int temp[row][col];

	
    for(i=0; i<row; i++){
        temp[i][0]=i*20;
    }
    for(i=0; i<row; i++){
        temp[i][1]=5*((temp[i][0])-32)/9;
    }
       
    printf("  F°  C°\n");
    for(i=0; i<row; i++){
        printf("[ ");
        for (j = 0; j < col; j++)
        {
            printf("%d ",temp[i][j]);
        }
        printf("]\n");
    }   
    printf("\n");
}
