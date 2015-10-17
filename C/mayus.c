#include <stdio.h>


int main(char argc, char * argv[]) {
	
	int a,j;
	char l;
	char word[30];

	printf("Ingrese una palabra (en minusculas)\n");
	fflush(stdin);
	scanf("%s",word);  

	j=0;
	while (word[j] != '\0'){
    	l=word[j];
    	a = (int) l;
    	a= a-32;

    	word[j]= toascii(a);

    	j++;
    }

    j=0;
    printf("Palabra en mayusculas: ");
	while (word[j] != '\0'){
    	printf("%c", word[j]);	
    	j++;
    }
    printf("\n");
	
}
