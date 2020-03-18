#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "./head/calculos.h"

int errno;

int calculos ( char* path ) {
	
	double* nums = malloc( 101*sizeof(double) );	// por enunciado
	int n = 0;
	FILE* fp = fopen( path, "r" );

	if ( fp ){
		while ( !feof( fp ) ) {
			fscanf( fp,"%lf ",&nums[n++] );
			if ( n>=100 ) {
				nums = mostrarCalculos( nums,n );
				n=0;
			}
		}
		fclose( fp );
		exit(0);
	} else 
		printf( "ERROR: %s\n",strerror(errno) );
	exit(1);
} 
