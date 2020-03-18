#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "./head/punto.h"

int errno;

int readFile ( char* path, struct ptarr *res ) {
	int size;
	FILE* fp = fopen( path, "r" );
	int k = 0;
	struct punto aux;
	
	if ( fp ) {
		fseek( fp, 0, SEEK_END );
		size = ftell( fp );
		if ( ( res->puntos = malloc( size * sizeof( struct punto ) ) ) != NULL ) {
			fseek( fp, 0, SEEK_SET );
			while ( !feof(fp) ) {
				fscanf( fp,"%lf %lf", &(aux.x), &(aux.y) );
				res->puntos[k++] = aux;
			}
			res->puntos = realloc( res->puntos, k * sizeof( struct punto ) );
			res->length = k;
		} else {
			fprintf(stderr,"ERROR: %s\n",strerror(errno));
			return 1;
		}
		fclose( fp );
		return 0;
	} 
	fprintf(stderr,"ERROR: %s\n",strerror(errno));	
	return 1;
}

int escribirPuntos ( struct ptarr ptarr,char* mod ) {
	int i=0;
	FILE* fp = fopen("puntos.dp",mod);
	
	if ( fp ){
		while ( i<ptarr.length ) {
			fprintf(fp,"%lf %lf\n",ptarr.puntos[i].x,ptarr.puntos[i].y);
			i++;
		}
		printf("el archivo ha sido escrito\n");
		fclose(fp);
		return 0;
	} 
	fprintf(stderr,"ERROR: %s\n",strerror(errno));	
	return 1;
}

int generarPuntos ( int n ) {
	struct ptarr ptarr;
	if ( ( ptarr.puntos = malloc( sizeof( struct punto )*n ) ) != NULL ) {
		int i=0;
		while ( i<n ){
			srand(i);
			ptarr.puntos[i++] = (struct punto) {
				.x = ( (double)  RAND_MAX/rand() )*10,
				.y = ( (double)  RAND_MAX/rand() )*10
			};
		}
		ptarr.length = i;
		return escribirPuntos( ptarr,"a" );
	}
	fprintf(stderr,"ERROR: %s\n",strerror(errno));	
	return 1;
}

int ordenarPuntos ( struct ptarr pts ) {
	struct punto aux;
	int i, max = pts.length;
	if (max > 0) {
		while ( i<pts.length ) {
			if ( pts.puntos[i+1].x>pts.puntos[i].x ) {
				aux = pts.puntos[i+1];
				pts.puntos[i+1] = pts.puntos[i];
				pts.puntos[i] = aux;
			}
			if ( i==max-1 ) {
				max--;
				i=0;
			} else
				i++;
		}
		return 0;
	}
	printf("ERROR:no hay puntos que ordenar\n");
	return 1;

}

int mostrarPuntos ( struct ptarr puntos ) {
	int k=0; 
	if ( puntos.length>0 ) {
		while ( k<puntos.length-1 ){
			printf( "x:%lf, y:%lf\n",puntos.puntos[k].x,puntos.puntos[k].y );
			k++;
		}
		return 0;
	}
	printf("Puntos no almacenados correctamente\n");
	return 1;	
}
