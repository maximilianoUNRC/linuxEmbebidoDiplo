#include <stdio.h>
#include <stdlib.h> 

int lenght (char *word)
{
    int j=0;
    while (word[j] != '\0')
    	j++;
    return j;
}

int equals(char *word1, char *word2){
    int j=0;
    while (word1[j] != '\0' && word2[j] != '\0' && word1[j]==word2[j])
        j++;
    
    if (word1[j] == '\0' && word2[j] == '\0'){
        return 1;
    }else{
        return 0;
    }
}

concat(char *word1, char *word2){
    int j=0;
    int i=0;
    while (word1[j] != '\0')
        j++;

    while (word2[i] != '\0'){
        word1[j+i]=word2[i];
        i++;
    }
    word1[j+i]='\0';
    
    return;
}

void copy_from_to(char *word1, char *word2){
    int i=0;
    while (word1[i] != '\0'){
        word2[i]=word1[i];
        i++;
    }
    word2[i]='\0';
}

int main (void)
{
    char word1[50];
    char word2[50];

	printf("Ingrese la primer palabra\n");
	fflush(stdin);
	scanf("%s",word1);  

    printf("Ingrese la segunda palabra\n");
    fflush(stdin);
    scanf("%s",word2);  

	printf("La longitud de la palabra '%s' es %d \n",word1,lenght(word1));
    printf("La longitud de la palabra '%s' es %d \n",word2,lenght(word2));

    if(equals(word1,word2)==1){
        printf("Las palabas son iguales \n");
    }else{
        printf("Las palabas son distintas \n");
    }

    concat(word1,word2);
    printf("Palabra concatenada: '%s' \n", word1);

    copy_from_to(word1,word2);
    printf("Palabra copiada: '%s' \n", word2);

    return 0;
}

