#include "./head/headers.h"
#include <stdio.h>
#include <stdlib.h>

int main (
	int arc,
	char **arv
) {
	if ( arc>1 )
		printChars(*(arv+1));
	else 
		printf("ERROR: tienes que especificar un archivo\n");
}
