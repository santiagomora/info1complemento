#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void handler (int s){
	int w;
	pid_t fid;
	while ((fid = waitpid(-1,&w,WNOHANG)) > 0){
		printf("Proceso terminado:%d\n",fid);
	}
}

int main () {
	int i=0;
        pid_t ch;
	puts("Empezando ejecucion");
	signal(SIGCHLD,handler);
	while ( (ch=fork())!=0 && ++i<=10000 ){
		if (ch && i==10000){
			sleep(30);
			printf("fin padre\n");
			exit(0);	
		}
	} 
	if (ch==0){
		printf("Proceso hijo:%d, pid:%d\n",i,getpid());
		sleep(5);
	}
}

