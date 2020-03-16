#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "./head/calculos.h"
#define BUFF_SIZE 1024

int errno;

/*
 * necesitamos modificar el stream a medida que avancemos 
 * con la lectura. por eso **fp
 * */
void readbuffer( char* buff ) {
	int k=0;
	char* endptr = buff;
	double* nums = malloc( sizeof( double )*100 );
	while ( *endptr != '\0' ) {
		nums[k++] = strtod(endptr,&endptr);
		if ( k%100 == 0 ) {
			nums = mostrarCalculos( nums,k );
			k=0;
		}
	}
} 

void calculos ( char* path ) {
	char* buff;
	int fsize,read;			
	FILE* fp = fopen( path,"r" );
	
	if ( fp ){
		fseek( fp, 0, SEEK_END );
		fsize = ftell( fp );
		if (fsize > 0) {
			if ( ( buff = malloc( fsize*sizeof( char )+1 ) ) != NULL ) {
				fseek( fp,0,SEEK_SET );
				if ( ( read = fread( buff, fsize*sizeof(char), sizeof( char ),  fp ) )>0 ) {
					buff[fsize-1] = '\0';
					readbuffer( buff );
				} else 
					fprintf( stderr,"ERROR: %s",strerror(errno) );
			} else
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
