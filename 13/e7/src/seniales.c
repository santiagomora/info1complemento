#include "head/servidor.h"

void chldhand (int sg) {
        int w;
        pid_t fid;
        while ((fid = waitpid(-1,&w,WNOHANG)) > 0){
                cctr--;
                printf("finalizado:%d,status:%d\n",fid,w);
        }
}

void huphand (int sg) {
        printf("leyendo nuevamente el archivo de configuracion servidor.conf\n");
        cctr=0;
        if ( initvars(&init,assignvar) != 0 ) {
                exit(1);
        }
}

int sig_trap () {
	if (signal(SIGHUP,huphand) == SIG_ERR || signal(SIGCHLD,chldhand) == SIG_ERR){
		return SIG_ERR;
	}
	return 0;
}
