#include "head/servidor.h"

int main ()
{
	cctr = 0;
	int sockfd; 			/* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */

	int sockdup; 
	
	if (initvars(&init,assignvar) != 0){
		exit(1);
	}
	
	if (sig_trap() != 0){
		exit(1);
	}

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(1){
		if (cctr >= init.maxch){
			pause();	
		}  
		sockdup = Aceptar_pedidos (sockfd);
		// Aca se pone un fork () y se lo convierte en un server concurrente
		// En tal caso, lo que sigue es el child process
		// El padre vuelve a Aceptar_pedidos
		if ((fork()==0) && sockdup) {
			child_process(sockdup);
			close(sockfd);
		} else {
			close(sockdup);
			cctr++;
		}	
	}
	exit(0);
}
