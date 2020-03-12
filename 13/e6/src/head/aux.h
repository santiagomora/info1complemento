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
#include <string.h>

int initvars(struct vconf* vars, int (*assign)(char*,char*,struct vconf*));

int getvnameid( const struct name *names, char* vname, int len );
