#include "./head/headers.h"
#include <stdlib.h>
#include <stdio.h>

int main (
	int arc,
	char **arv
) {
	if ( arc>1 )
		printSource(*(arv+1));
	else 
		printf("ERROR: tiene que especificar un numbre de archivo\n");
}
