#include "head/aux.h"
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 50
#define DELIM "="

int getvnameid ( const struct name *names, char* vname, int len ) {
	for (int i=0; i<len; i++){
		if (strcmp(names[i].string,vname) == 0){
			return names[i].id;
		}
	}
	return -1;
}

void readvar (char* buf, char** vname, char** vval ) {
	if (buf[0] != '#'){
		*vname=strtok(buf,DELIM);
		*vval=strtok(NULL,buf);
		//remove \n from end of vval if there is
		if (vval[0][strlen(*vval)-1] == '\n') 
			vval[0][strlen(*vval)-1]='\0';
	}
}

int initvars(struct vconf* vars,int (*assign)(char*,char*,struct vconf*)) {
	FILE* config;
	size_t bufsize = BUF_SIZE;
        int read;
	char *buf = malloc( bufsize*sizeof( char ) );
	char *vval,*vname;
       	config = fopen("/etc/servidor.conf","r");
	if (config) {
		while( ( read = getline( &buf,&bufsize,config ) ) > 0 && !feof(config) ){
			buf[read-1] = '\0';
			readvar( buf,&vname,&vval );
			if (vname && vval){
				if ( assign( vname,vval,vars ) == -1 ) {
					printf("Error en estructuras de configuracion");
					return 1;
				}
			} else {
				printf("Error en el archivo de configuracion\n");
			       return 1;	
			}
		}
		fclose(config);
	} else {
		printf("No es posible abrir el archivo de configuracion.\n");	
		return 1;
	}
	return 0;
}
