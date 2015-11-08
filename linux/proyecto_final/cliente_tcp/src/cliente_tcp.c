/*Alumno: Correa, Carlos Maximiliano.
 * Cliente_tcp que emana el estado de un boton y la variacion de las lecturas de un potenciometro.
 * */

#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include "mraa.h"
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.


#define analog_Pin_1 1 // El pulsador esta conectado en pull-up al analogico_1
#define analog_Pin_0 0 // El potenciometro esta conectado al analogico_0


int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[20] , server_reply[2000];
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("192.168.1.204");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Declaracion de variables para la lectura de los estados de los actuadores...
	mraa_init();
	mraa_aio_context pulsador = mraa_aio_init(analog_Pin_1);
	mraa_aio_context pot = mraa_aio_init(analog_Pin_0);
	// variables auxiliares
	char str_button[80];
	char str_pot[80];

	puts("Enviando Datos\n");

	while(1){

    	// Lectura de Actuadores.
        itoa(mraa_aio_read(pulsador),str_button);
        itoa(mraa_aio_read(pot), str_pot);

        // Formato del mensaje.
        strcat(message,str_button);
        strcat(message, "|");
        strcat(message, str_pot);
        strcat(message, "|");
        strcat(message, "*");



        //Send some data
        if( send(sock , message, strlen(message)+1 , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        // Inicializacion  Vacio de message
        memset(message, 0, sizeof(message));
        sleep(1);
    }// End_while

    shutdown(sock,SHUT_RDWR);
    mraa_aio_close(pot);
    mraa_aio_close(pulsador);
   	return MRAA_SUCCESS;

}
//***********************************************************END_MAIN******************************************************

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
