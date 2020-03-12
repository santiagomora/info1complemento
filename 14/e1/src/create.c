#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {
	umask(S_IRWXU|S_IRWXG|S_IRWXO);

	int fp1 = open("arch1", O_CREAT, S_IRWXU | S_IRGRP | S_IWOTH);
	int fp2 = open("arch2", O_CREAT, S_IRUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH );
	int fp3 = open("arch3", O_CREAT, S_IRUSR | S_IXGRP | S_IWOTH | S_IXOTH );

	close(fp1);
	close(fp2);
	close(fp3);
}
