/*Alumno: Correa, Carlos Maximiliano.
 * Servidor_tcp que actua segun el estado de un boton y la variacion de las lecturas de un potenciometro.
 * */

#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "mraa.h"
#include "gpio.h"
#include "mraa/aio.h" // Se incluye en este ejercicio la libreria de tratamiento
					  // Analog Pin por una cuestion de hardware implementado.


#define IOPIN_ 13  // Led conectado al pin digital 13
#define IOPIN_B 3 //El buzzer en mi shield esta en el pin ~3


int main() {

	int socket_desc , client_sock , c , read_size;

	struct sockaddr_in server , client;
	char client_message[20];

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

	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}
	puts("Connection accepted");

	//------------------------------------ MRAA ------------------------------------------
	mraa_result_t r = MRAA_SUCCESS;
	mraa_init();
	mraa_gpio_context gpio = mraa_gpio_init(IOPIN_);
	mraa_pwm_context pwm = mraa_pwm_init(IOPIN_B);
	mraa_pwm_enable(pwm, 1);
	mraa_pwm_write(pwm,0.5f);

	// set direction to OUT
	r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
	if (r != MRAA_SUCCESS) {
		mraa_result_print(r);
	}
	//-------------------------------------------------------------------------------------
	int indice;
	char aux[5];
	int value;
	int component;
	int i;
	//Receive a message from client
	while( (read_size = recv(client_sock , client_message , 2000, 0)) > 0 )
	{
		indice = 0;
		component=0;
		i=0;
		while(client_message[indice] !='*'){
			 if(client_message[indice]!='|'){
				 aux[i]= client_message[indice];
				 i++;
			 }else{
				 value = toString(aux);
				 if(component == 0){ //Numero de Actuador
					 if(value==0){
						 mraa_gpio_write(gpio, 0);
					 }else{
						 mraa_gpio_write(gpio, 1);
					 }
				 }else{
					 mraa_pwm_period_us(pwm, value);
					 usleep(25000);
				 }
			     memset(aux, 0, sizeof(aux));
				 component++;
				 i=0;
			 }
		indice++;
		}
	}


	if(read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}

	mraa_gpio_close(gpio);
	return r;

}
//*******************************************
/*De string a entero*/
int toString(char a[]) {
  int c, sign, offset, n;
  if (a[0] == '-') {
    sign = -1;
  }
  if (sign == -1) {
    offset = 1;
  }
  else {
    offset = 0;
  }
  n = 0;
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
  if (sign == -1) {
    n = -n;
  }
  return n;
}
//********************************************
