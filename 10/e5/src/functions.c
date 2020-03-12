#include <stdlib.h>
#include <stdio.h>
#include "./head/calculos.h"

void calculos ( char* path ) {
	
	double* nums = malloc( 101*sizeof(double) ),		// por enunciado
	     	read;
	int k = 0;			// go through string
	FILE* fp = fopen( path, "r" );

	if ( fp ){
		fscanf( fp,"%lf",&read );
		while ( !feof( fp ) ) {
			nums[k++] = read;
			fscanf( fp,"%lf",&read );
			if ( ( k%100 == 0 || feof( fp ) ) && k>0 ) {
				nums = mostrarCalculos( nums,k );
				k=0;
			}
		}
		fclose( fp );
	}
	else puts( "El archivo no puede ser encontrado:\n" );

} 

int printSource( char* path_to_file ){
	calculos( path_to_file );
	return 0;
}
