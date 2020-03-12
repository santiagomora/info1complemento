#include <stdlib.h>
#include <stdio.h>
#include "./head/punto.h"
#include "./head/acciones.h"

void mostrarMenu() {
	char opt;
	struct ptarr puntos = readFile( "puntos.dp" );
	while ( (int)opt!=27 ) {
		printf("Que desea hacer?:\na:Presentar valores\nb:Ordenar mediante coordenada x\n");
		scanf(" %c",&opt);
		switch ( opt ) {
			case 'a':
			system("clear");
				mostrarPuntos( puntos );
				break;
			case 'b':
				system("clear");
				ordenarPuntos( puntos );
				escribirPuntos( puntos,"w" );
				break;
			default:
				break;
		} 

	}

}

int printSource( char* charsize ){
	generarPuntos( atoi( charsize ) );
	mostrarMenu(); 
	return 0;
}
