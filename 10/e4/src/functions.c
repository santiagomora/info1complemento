#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define BUFF_SIZE 1024

int errno;

int printSource( char* path ) {
	int size=0;
	FILE* fp = fopen( path, "r" );
	char buff[BUFF_SIZE], 
	     ver[] = "Viendo archivo: ";
	
	if (fp){
		strcat ( ver,path );
		puts( ver );
		while ( !feof( fp ) ) {
			size = fread( buff, sizeof( char ), sizeof(buff), fp );
			buff[size-1] = '\0';
			puts( buff );			
		}
		fclose( fp );
		exit(0);
	} else 
		printf("ERROR:%s\n",strerror(errno));
	exit(1);
} 

