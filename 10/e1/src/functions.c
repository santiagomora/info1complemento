#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int errno;

int printChars ( char* path ) {
	FILE* fp;
	char c;
	fp = fopen( path, "r" );
	if ( fp ) {
		while ( ( c=fgetc( fp ) ) != EOF ) {
			putchar(c);
		}
		fclose(fp);
		return 0;
	} else
		printf( "ERROR:%s\n",strerror(errno) );
	return 1;

} 

int printSource( char* main ){
	char* func = __FILE__;
	printf( "El archivo fuente de: %s:\n", main );
	if ( printChars(main) == 0 ) {
		printf( "\nEl archivo fuente de: %s\n", func );
		exit( printChars(func) );
	} else exit(1);
	exit(0);
}
