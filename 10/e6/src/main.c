#include "./head/headers.h"

int main (
	int arc,
	char **arv
) {
	if ( arc>1 )
		printSource( *( arv+1 ) );
	else 
		printf("Debes indicar cuantos numeros quieres generar.\n");
}
