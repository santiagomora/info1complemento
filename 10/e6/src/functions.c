#include <stdlib.h>
#include <stdio.h>
#include "./head/punto.h"
#include "./head/acciones.h"

void mostrarMenu() {
	char opt;
	struct ptarr puntos;
       	if ( readFile( "puntos.dp",&puntos ) != -1 ) {  
		while ( (int)opt!=27 ) {
			printf("Que desea hacer?:\n\
a:Presentar valores\n\
b:Ordenar mediante coordenada x\n\
Presione ESC para salir.\n");
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
	exit(0);
}

int printSource( char* charsize ){
	if ( generarPuntos( atoi( charsize ) ) != -1 )
		mostrarMenu(); 
	return 0;
}
