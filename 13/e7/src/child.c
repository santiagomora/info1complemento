#include "head/servidor.h"
#define MAXDATASIZE 4096 /* máxima cantidad de bytes que puede recibir en una transacción*/

int sendfile( FILE* fp,int sockfd ){
	char fbuf[MAXDATASIZE];
	size_t bytes=0;
	while ( ( bytes = fread( fbuf,sizeof(char),sizeof(fbuf),fp ) ) > 0 ){
		fbuf[bytes] = '\0';
		if (write (sockfd, fbuf , bytes) == -1){
			perror("error de escritura en el socket");
                        exit(1);
		}
	}
	return 0;
}

void child_process (int sockdup) {
	char buf[MAXDATASIZE], confirm[] = "OK", err[]="ERROR:";
	int numbytes;
	FILE* fp;

	if ((numbytes = read (sockdup, buf, MAXDATASIZE)) == -1){
		perror("error de lectura en el socket");
		exit(1);                
	}

	printf("archivo a enviar:%s\n",buf);
	fp = fopen(buf,"r");
	// para timeout de cliente 
	// sleep(30);
	
	if (!fp) {
		strcat(err,strerror(errno));
		if (write (sockdup, err , strlen(err)) == -1)
                        perror("error de escritura en el socket");
		exit(1);
	} else {
		if (write (sockdup, confirm , sizeof (confirm)) == -1){
                	perror("error de escritura en el socket");
        	        exit(1);
	        } else if ( sendfile(fp,sockdup) == 0 ) 
			printf("archivo enviado exitosamente\n");
		fclose(fp);
	}

	close(sockdup);
	exit(0);
}
