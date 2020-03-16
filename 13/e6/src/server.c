#include "../../../11/info1includes/sock-lib.h"
#include "head/aux.h"
#define NAMESTOSOLVE 1

// nombres de variables a leer de servidor.conf
// asociados a un id unico. los nombres deberan
// ser unicos tambien
const struct name cnames[NAMESTOSOLVE] = {
	(struct name){.string="chmax",.id=1}
};

// cuantas conexiones estan activas
int cctr;

// struct donde se guardan las variables de configuracion
// por el momento solo el maximo numero de procesos children
struct vconf init; 

int assignvar(char* name, char* value, struct vconf* vars){
	switch( getvnameid( cnames,name,NAMESTOSOLVE ) ){
		case 1:
			vars->maxch = atoi(value);
			break;
		default: 
			return -1;
	}
	return 0;
} 

void chldhand (int sg) {
	int w;
	pid_t fid;
	while ((fid = waitpid(-1,&w,WNOHANG)) > 0){
		cctr--;
		printf("finalizado:%d,status:%d\n",fid,w);
	}
}

void huphand (int sg) {
	printf("leyendo nuevamente el archivo de configuracion /etc/servidor.conf\n");
	cctr=0;
	if ( initvars(&init,assignvar) != 0 ) {
		exit(1);
	}
}

int main ()
{
	int sockfd; 			/* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */

	int sockdup; 
	
	if (initvars(&init,assignvar) != 0){
		exit(1);
	}

	signal(SIGCHLD,chldhand);
	signal(SIGHUP,huphand);

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}
	while(1)
	{
		if (cctr >= init.maxch){
			pause();	
		}  
		sockdup = Aceptar_pedidos (sockfd);
		// Aca se pone un fork () y se lo convierte en un server concurrente
		// En tal caso, lo que sigue es el child process
		// El padre vuelve a Aceptar_pedidos
		if ((fork()==0) && sockdup) {
			close(sockfd);
			if (write (sockdup, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			close(sockdup);
			sleep(5);
			exit(0);
		} else {
			close(sockdup);
			cctr++;
		}	
	}
	exit(0);
}
