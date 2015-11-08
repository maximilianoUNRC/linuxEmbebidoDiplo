/* Alumno: Correa, Carlos Maximiliano.
* Escribir en un documento los datos del GPIO28 (D4) y el conversor A/D (A0).
* Luego, hacer accesible vía Web, mediante el uso de un navegador.
* Nota: Usar el la entrada D4 y A0 del Shield de expansión.
*/
//***************************************************************************************
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.

//*********************************************************************************
#define analog_Pin_0 0 // El potenciometro esta conectado al analogico_0
#define analog_Pin_1 1 // El pulsador esta conectado en pull-up al analogico_1
//*********************************************************************************

int main() {

	int socket_desc , client_sock , c ;
	struct sockaddr_in server , client;

	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("192.168.1.204");
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");

	//Listen
	listen(socket_desc , 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	mraa_init();
	mraa_aio_context pot = mraa_aio_init(analog_Pin_0);
	mraa_aio_context pulsador = mraa_aio_init(analog_Pin_1);
	int value_pot = 0;
	char snum[5];
	int state_button = 1;

	while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
	{
		puts("Connection accepted");

		value_pot = mraa_aio_read(pot);
		state_button = mraa_aio_read(pulsador);

		itoa(value_pot,snum);

		//Send the message back to client
		write(client_sock , "<html><body><h1>" , strlen("<html><body><h1>")+1);
		write(client_sock , "<head><meta http-equiv=\"refresh\" content=\"1\"></head>" , strlen("<head><meta http-equiv=\"refresh\" content=\"1\"></head>")+1);
		write(client_sock , "Potenciometro = " , strlen("Potenciometro = ")+1);
		write(client_sock , snum , strlen(snum)+1);
		write(client_sock , "<br />" , strlen("<br />")+1);
		write(client_sock , "Estado Boton = " , strlen("Estado Boton = ")+1);

		if(state_button == 0){
			write(client_sock , "ON" , strlen("ON")+1);

		}else{
			write(client_sock , "OFF" , strlen("OFF")+1);
		}
		write(client_sock , "<br />" , strlen("<br />")+1);
		write(client_sock , "</h1></body></html>" , strlen("</h1></body></html>")+1);
	}


	return 0;
}


/* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
