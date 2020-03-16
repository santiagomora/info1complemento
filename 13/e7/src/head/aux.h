#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <signal.h>
#ifndef CONF_STRUCT
	#define CONF_STRUCT
	struct vconf {
		int maxch;
	};
#endif
#ifndef CONF_NAME
	#define CONF_NAME
	struct name {
		char *string;
		char id;
	};
#endif
#define BUF_SIZE 50
#define DELIM "="
#define NAMESTOSOLVE 1 

int initvars(struct vconf* vars, int (*assign)(char*,char*,struct vconf*));

int getvnameid(const struct name *names, char* vname, int len );

int assignvar(char* name, char* value, struct vconf* vars);
