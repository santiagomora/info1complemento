#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "./head/calculos.h"
#define BUFF_SIZE 1024
#define MAX_READ 100

int errno;

void readbuffer( char* buff ) {
	int k=0;
	char* endptr = buff;
	double *nums = malloc( sizeof( double )*100 );
	while ( *endptr != '\n' && *endptr != '\0' ) {
		nums[k++] = strtod(endptr,&endptr);
		if ( k%MAX_READ == 0 ) {
			nums = mostrarCalculos( nums,k );
			k=0;
		}
	}
} 

void calculos ( char* path ) {
	size_t bsize = BUFF_SIZE;
	char *buff = malloc(bsize*sizeof(char));
	FILE *fp = fopen( path,"r" );
	int read;

	if ( fp ) {
		while ( !feof( fp ) ) {
			if ( ( read = getline( &buff,&bsize,fp )!=-1 ) > 0) {
				buff[bsize-1] = '\0';
				readbuffer( buff );
			} else if ( read == -1 )
				fprintf( stderr,"ERROR: %s",strerror(errno) );
		}
	       fclose( fp );	
	} else 
		fprintf( stderr,"ERROR: %s",strerror(errno) );
} 

int printSource( char* path_to_file ){
	calculos( path_to_file );
	return 0;
}
