/* Alumno: Correa, Carlos Maximiliano.
* Escribir en un documento los datos del GPIO28 (D4) y el conversor A/D (A0).
* Luego, hacer accesible vía Web, mediante el uso de un navegador.
*/
//***************************************************************************************
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "mraa.h"
#include "gpio.h"

#define analog_Pin_0 0 // El potenciometro esta conectado al analogico_0

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
	server.sin_addr.s_addr = inet_addr("192.168.0.101");
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

	// Setup()
	mraa_init();
	mraa_gpio_context gpio_1 = mraa_gpio_init_raw(36);
	mraa_gpio_dir(gpio_1, MRAA_GPIO_OUT);
	mraa_gpio_write(gpio_1, 1);
	mraa_gpio_context gpio_2 = mraa_gpio_init_raw(45);
	mraa_gpio_dir(gpio_2, MRAA_GPIO_IN);

	mraa_aio_context pot = mraa_aio_init(analog_Pin_0);

	unsigned int value_pot = 0;
	char snum[5];
	int state_button = 1;

	while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
	{
		puts("Connection accepted");

		value_pot = mraa_aio_read(pot);
		state_button = mraa_gpio_read(gpio_2);

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

	mraa_aio_close(pot);
	mraa_gpio_close(gpio_1);
	mraa_gpio_close(gpio_2);
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
