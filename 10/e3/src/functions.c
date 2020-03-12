#include <stdlib.h>
#include <stdio.h>
#include "./head/calculos.h"

void calculos ( char* path ) {
	
	double* nums = malloc( 101*sizeof(double) );	// por enunciado
	int k = 0,			// go through string
	    n = 0;
	char flt[16];			// donde almacenaremos el float para despues convertirlo 
	FILE* fp = fopen( path, "r" );

	if ( fp ){
		char c = fgetc( fp );
		while ( c != EOF ) {
			while ( c!=' ' && c!='\n' && c!=EOF ){
				flt[k++] = c;
				c = fgetc( fp );
				if ( c==' ' || c==EOF || c=='\n' ){
					flt[k] = '\0';
					nums[n++] = atof( flt );
					if ( ( n%100 == 0 || feof( fp ) ) && n>0 ) {
		                                nums = mostrarCalculos( nums,n );
                		                n=0;
                        		}
					k=0;			
				} 
			}	
			c = ( c==EOF ) 
				? EOF 
				: fgetc( fp );
		}
		fclose( fp );
	}
	else puts( "El archivo no puede ser encontrado:\n" );

} 

int printSource( char* path_to_file ){
	calculos( path_to_file );
	return 0;
}
