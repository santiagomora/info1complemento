#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int errno;

int printChars ( char* path ) {
	FILE* fp = fopen( path, "r" );
	char c;
	if (fp){
		printf("el archivo fuente de %s: \n",path);
		while ( ( c = fgetc( fp ) ) != EOF ) {
			putchar(c);
		}
		fclose(fp);
		exit(0);
	}
	else 
		printf( "ERROR: %s\n",strerror(errno) );
	exit(1);
} 

