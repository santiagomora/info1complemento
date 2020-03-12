#include "head/aux.h" 

// nombres de variables a leer de servidor.conf
// asociados a un id unico. los nombres deberan
// ser unicos tambien
const struct name varmap[NAMESTOSOLVE] = {
        (struct name){.string="chmax",.id=1}
};

int assignvar(char* name, char* value, struct vconf* vars){
        switch( getvnameid( varmap,name,NAMESTOSOLVE ) ){
                case 1:
                        vars->maxch = atoi(value);
                        break;
                default:
                        return -1;
        }
        return 0;
}

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
	char buf[BUF_SIZE];
	char* vval,*vname;
       	config = fopen("/etc/servidor.conf","r");
	if (config) {
		while( fgets( buf,BUF_SIZE,config ) && !feof(config) ){
			readvar( buf,&vname,&vval );
			if (vname && vval){
				if ( assign( vname,vval,vars ) == -1 ) {
					fprintf(stderr,"Error en estructuras de configuracion");
					return 1;
				}
			} else {
				fprintf(stderr,"Error en el archivo de configuracion\n");
			       return 1;	
			}
		}
		fclose(config);
	} else {
		fprintf(stderr,"No es posible abrir el archivo de configuracion.\n");	
		return 1;
	}
	return 0;
}
