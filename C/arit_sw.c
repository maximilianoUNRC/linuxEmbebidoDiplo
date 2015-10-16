#include <stdio.h>

void arit(int a,int b, char c){
	switch(c){
		case '+': printf("%d \n", a+b);
		break;
		case '-': printf("%d \n", a-b);
		break;
		case '*': printf("%d \n", a*b);
		break;
		case '/': printf("%d \n", (int)a/b);
		break;
		default: printf("ERROR \n");
	}
}


int main(char argc, char * argv[]) {
	int a,b;
	char c;

	printf("Introduce el caracter: ");
	fflush(stdin);
	scanf("%c",&c);
	getchar();
	
	printf("Introduce el primer numero: ");
	scanf("%d",&a);
	
	printf("Introduce el segundo numero: ");
	scanf("%d",&b);

	
	arit(a,b,c);
}