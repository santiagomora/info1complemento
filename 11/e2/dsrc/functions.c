#include "functions.h"

void libclose( 
	void *lib 
) {
	dlclose(lib);
}

/*
 * returns lib handler
 * */
int solvesymbols ( 
	struct sym *symbols,
        void *lib,
	int len
) {
        char *error;
	int i=0;
        lib = dlopen("../../libsrc/ver/libshared.so.1",RTLD_LAZY);
        if(!lib) {
                fputs (dlerror() , stderr);
                return EXIT_FAILURE;
        }
	while(i<len) {
		symbols[i].func = dlsym( lib,symbols[i].name );
        	if((error = dlerror()) != NULL ) {
                	fputs (error , stderr);
	                return EXIT_FAILURE;
        	}
		i++;
	}
	return 0;
} 
