#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void handler (int s){
	wait(NULL);
}

int main () {
	int i=0;
        pid_t ch;
	puts("Empezando ejecucion");
	signal(SIGCHLD,handler);
	while ( (ch=fork())!=0 && i<10000 ){
		if (ch && i==9999){
			sleep(30);
			printf("fin padre\n");
			exit(0);	
		}
		i++;
	} 
	if (ch==0){
		sleep(5);
	}
}

