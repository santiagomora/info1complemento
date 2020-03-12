#include <stdlib.h>
#include <stdio.h>
#include "./head/punto.h"

struct ptarr readFile (
	char* path 
) {

	int size;
	struct ptarr res;
	FILE* fp = fopen( path, "r" );
	int k = 0;
	struct punto aux;
	
	if ( fp ) {
		fseek( fp, 0, SEEK_END );
		size = ftell( fp );
		res.puntos = malloc( size * sizeof( struct punto ) );
		fseek( fp, 0, SEEK_SET );

		while ( !feof(fp) ) {
			fscanf( fp,"%lf %lf", &(aux.x), &(aux.y) );
			res.puntos[k++] = aux;
		}

		res.puntos = realloc( res.puntos, k * sizeof( struct punto ) );
		res.length = k;
		fclose( fp );
	}
	return res;
}

void escribirPuntos ( 
	struct ptarr ptarr,
	char* mod
) {
	int i=0;
	FILE* fp = fopen("puntos.dp",mod);
	
	if ( fp ){
		while ( i<ptarr.length ) {
			fprintf(fp,"%lf %lf\n",ptarr.puntos[i].x,ptarr.puntos[i].y);
			i++;
		}
		printf("el archivo ha sido escrito\n");
		fclose(fp);
	}
}

void generarPuntos ( 
	int n 
) {
	struct ptarr ptarr;
	ptarr.puntos = malloc(sizeof(struct punto)*n);
	int i=0;
	while ( i<n ){
		srand(i);
		ptarr.puntos[i++] = (struct punto) {
			.x = ( (double)  RAND_MAX/rand() )*10,
			.y = ( (double)  RAND_MAX/rand() )*10
		};
	}
	ptarr.length = i;
	escribirPuntos( ptarr,"w" );
}

void ordenarPuntos (
	struct ptarr pts
) {
	struct punto aux;
       	struct punto* puntos = pts.puntos; 	
	int i, max = pts.length;

	while ( i<max ) {
		if ( puntos[i+1].x>puntos[i].x ) {
			aux = puntos[i+1];
			puntos[i+1] = puntos[i];
			puntos[i] = aux;
		}
		if ( i==max-1 ) {
			max--;
			i=0;
		} else
			i++;
	}
}

void mostrarPuntos (
	struct ptarr puntos
) {
	int k=0; 
	
	if ( puntos.length>0 )
		while ( k<puntos.length ){
			printf( "x:%lf, y:%lf\n",puntos.puntos[k].x,puntos.puntos[k].y );
			k++;
		}
	else 
		printf("archivo vacio o no encontrado");
}
