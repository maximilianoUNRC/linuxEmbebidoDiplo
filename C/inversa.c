#include <stdio.h>


void invertirCadena (char *cadena)
{
    int j=0;
    int i;
    while (cadena[j] != '\0'){
        j++;
    }

    for (i=j-1 ; i>=0 ; i--){
        printf("%c",cadena[i]);
    }
 }

int main (void)
{
    char palabra[30];

	printf("ingrese palabra\n");
	fflush(stdin);
	scanf("%s",palabra);  

    invertirCadena(palabra);

    return 0;
}

