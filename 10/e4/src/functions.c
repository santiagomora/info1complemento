#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printStream ( char* path ) {
	int size;
	FILE* fp = fopen( path, "r" );

	if (fp){
		fseek( fp, 0, SEEK_END );
		size = ftell( fp );
		char* buff = malloc( size*sizeof( char )+1 );
		// return pointer to original position
		fseek( fp, 0, SEEK_SET );
		fread( buff, size, sizeof( char ), fp );
		puts( path );
		puts( buff );
		fclose( fp );
	}
	else printf( "El archivo no puede ser encontrado: %s\n", path );

} 

int printSource( char* path_to_file ){
	printStream( path_to_file );
	return 0;
}
