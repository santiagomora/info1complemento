#include <stdlib.h>
#include <stdio.h>

void printChars ( char* path ) {
	FILE* fp;

	fp = fopen( path, "r" );
	
	char c = fgetc(fp);

	while ( c != EOF ) {
		putchar(c);
		c = fgetc(fp);
	}

	fclose(fp);
} 

int printSource( char* main ){
	char* func = __FILE__;
	printf( "El archivo fuente de: %s:\n", main );
	printChars(main);
	printf( "\nEl archivo fuente de: %s\n", func );
	printChars(func);
	return 0;
}
