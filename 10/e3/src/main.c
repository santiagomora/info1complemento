#include "./head/headers.h"
#include <stdio.h>
#include <stdlib.h>

int main (
	int arc,
	char **arv
) {
	if (arc>1)
		calculos(*(arv+1));
	else 
		printf("ERROR: tiene que especificar un archivo\n");
}
