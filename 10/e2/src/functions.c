#include <stdlib.h>
#include <stdio.h>

void printChars ( char* path ) {

	FILE* fp = fopen( path, "r" );

	if (fp){
		printf("el archivo fuente de %s: \n",path);
		char c = fgetc(fp);
		while ( c != EOF ) {
			putchar(c);
			c = fgetc(fp);
		}
		fclose(fp);
	}
	else printf( "El archivo no puede ser encontrado: %s\n", path );

} 

int printSource( char* path_to_file ){
	printChars( path_to_file );
	return 0;
}
