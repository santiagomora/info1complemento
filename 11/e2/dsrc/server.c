#include "functions.h"
#define NUM_FUNC 2

struct sym* initsymarr( struct sym *symbols ) {
        int (*Open_conection)(struct sockaddr_in*);
        int (*Aceptar_pedidos)(int);
        symbols[0] = (struct sym) INIT_FUNC(Open_conection,"Open_conection");
	symbols[1] = (struct sym) INIT_FUNC(Aceptar_pedidos,"Aceptar_pedidos");
	return symbols;
} 

int main ()
{
	int sockfd;			 /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	 /* Contendrá la dirección IP y el número de puerto local */
	int sockdup; 
	void *lib;
	struct sym syms[NUM_FUNC];
	
	if (solvesymbols( initsymarr( syms ),lib,NUM_FUNC ) == 0) {
		if ((sockfd = (syms[0].func) (&my_addr)) == -1){
			perror ("Falló la creación de la conexión"); 
			exit (1);
		}

		while(1){
			sockdup = (syms[1].func) (sockfd);
			/* Aca se pone un fork () y se lo convierte en un server concurrente
		 	* En tal caso, lo que sigue es el child process
		 	* El padre vuelve a Aceptar_pedidos
		 	* */
			if (write (sockdup, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			close(sockdup);
		}
        	libclose(lib);
	}
	exit(0);
}

