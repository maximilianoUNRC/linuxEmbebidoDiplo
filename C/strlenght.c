#include <stdio.h>
#include <stdlib.h> 

int longitudCadena (char *cadena)
{
    int j=0;
    while (cadena[j] != '\0')
    	j++;
    return j;
 }

int main (void)
{
    char palabra[30];

	printf("ingrese palabra\n");
	fflush(stdin);
	scanf("%s",palabra);  

	printf("La longitud de la palabra %s es %d \n",palabra,longitudCadena(palabra));

    return 0;
}

