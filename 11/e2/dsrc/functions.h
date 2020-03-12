#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../info1includes/sock-lib.h"
#ifndef SYM
	#define SYM 		
	struct sym {		
		int (*func)();	
		char* name;	
	};
#endif
#ifndef INIT_FUNC
	#define INIT_FUNC(func,name){	\
		func,			\
		name			\
	}
#endif

void libclose( void *lib );

int solvesymbols ( struct sym *symbols, void *lib, int len);

