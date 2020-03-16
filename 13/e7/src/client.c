#include "../../../11/info1includes/sock-lib.h"
#define MAXDATASIZE 4096 /* máxima cantidad de bytes que puede recibir en una transacción*/

int received;

void almhand ( int sg ) {
	if (received == 0){
		printf("archivo no recibido, cerrando conexion\n");
		exit(1);
	}
}

int receivefile( int sockfd ){
	char fbuf[MAXDATASIZE];
        size_t bytes=0;
	FILE* rfile;
	rfile = fopen("serverfile","w");
	if (rfile) {
		while ((bytes = read (sockfd, fbuf, sizeof(fbuf)-1)) >0 ){
			fbuf[bytes]='\0';
			if (fbuf[bytes-1] == EOF)
				fbuf[bytes-1] = '\0';
			fwrite(fbuf,sizeof(char),bytes,rfile);
		}
		fclose(rfile);
		return 0;
	}
	return 1;
}


int main(int argc, char * argv[])
{
	received = 0;
	int sockfd,numbytes;  		/* File Descriptor para sockets */
	char message[MAXDATASIZE]; 	/* Buffer donde se escribe el archivo a abrir*/
	
	signal(SIGALRM,almhand);
	
	/* Tratamiento de la línea de comandos. */
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
        }

	sockfd = conectar (argc, argv);
	
	/* pasamos el nombre del archivo al servidor */
	printf("introduzca la ruta del archivo:%s\n",message);
	scanf("%s",message);
	printf("archivo a encontrar:%s\n",message);

	if (write (sockfd, message , sizeof (message)) == -1){
		perror("error de escritura en el socket");
		exit(1);
	}
	alarm(30);
	
	if ((numbytes = read (sockfd, message, sizeof(message))) == -1){       
                perror("error de lectura en el socket");
                exit(1);
        }
	
	message[numbytes] = '\0';

	received=1;

	if (strcmp(message,"OK") == 0){
		if (receivefile(sockfd) == 0)
			printf("archivo recibido exitosamente, disponible en serverfile\n");
		else
			printf("transaccion fallida, no se pudo crear archivo local\n");
		exit(1);
	} else {
		printf("%s\n",message);
                exit(1);
	}

	/* Devolvemos recursos al sistema */
	close(sockfd);
	exit(0);
}
