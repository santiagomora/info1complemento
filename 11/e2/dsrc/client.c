#include "functions.h"
/* 
 * máxima cantidad de bytes que 
 * puede recibir en una transacción
 * */
#define MAXDATASIZE 4096 
#define NUM_FUNC 1

struct sym* initsymarr( struct sym *symbols ) {
	int (*conectar)(int,char**);
        symbols[0] = (struct sym) INIT_FUNC(conectar,"conectar");
        return symbols;
} 

int main(int argc, char * argv[])
{
	int sockfd;  		/* File Descriptor para sockets */
	int numbytes;		/* Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read () */
	void *lib;
	struct sym syms[NUM_FUNC];

	if (solvesymbols( initsymarr(syms),lib,NUM_FUNC ) == 0) {
		/* Tratamiento de la línea de comandos. */
		if (argc < 2) {
			fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
			exit(1);
	        }

		sockfd = (syms[0].func)(argc, argv);
	
		/* Recibimos los datos del servidor */
		if ((numbytes = read (sockfd, buf, MAXDATASIZE)) == -1)
		{
			perror("error de lectura en el socket");
			exit(1);
		}

		/* Visualizamos lo recibido */
		buf[numbytes] = '\0';
		printf("Recibido: %s\n",buf);
	
		/* Devolvemos recursos al sistema*/ 
		close(sockfd);
	}
	//libclose(lib);
	return 0;
}
