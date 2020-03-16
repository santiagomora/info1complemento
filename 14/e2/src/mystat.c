#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

int errno;

void printperm(mode_t mode){
	umask(S_IRWXU|S_IRWXG|S_IRWXO);
	if (S_ISLNK(mode)) 
		printf("l");
	else
		printf( (S_ISDIR(mode)) ? "d" : "-");
	printf( (mode & S_IRUSR) ? "r" : "-");
	printf( (mode & S_IWUSR) ? "w" : "-");
	printf( (mode & S_IXUSR) ? "x" : "-");
	printf( (mode & S_IRGRP) ? "r" : "-");
	printf( (mode & S_IWGRP) ? "w" : "-");
	printf( (mode & S_IXGRP) ? "x" : "-");
	printf( (mode & S_IROTH) ? "r" : "-");
	printf( (mode & S_IWOTH) ? "w" : "-");
	printf( (mode & S_IXOTH) ? "x" : "-");
}

int main (int argc,char** argv) {
	struct stat myfstat;
	struct tm * my_tm;
	struct group* grp;
	struct passwd * usr;

	char linkref[1024];
	int read=0;

	if (argc<2){
		printf("no hay suficientes argumentos\n");
		exit(1);
	} else {
		if ( stat(argv[1],&myfstat) != -1 ) {
			grp = getgrgid(myfstat.st_gid);
			usr = getpwuid(myfstat.st_uid);
			if ( ( read=readlink( argv[1],linkref,sizeof(linkref)-1 ) ) != -1){
				linkref[read] = '\0';
				if (lstat(argv[1],&myfstat) == -1)
					fprintf(stderr, "Error: %s\n", strerror( errno ));
				printf("File:\t%s -> %s\n",argv[1],linkref);
			} else	
				printf("File:\t%s\n",argv[1]);
			printf("Size:\t%ld\n",myfstat.st_size);
			printf("Owner:\tUser:\t%d/%s\n\tGroup:\t%d/%s\n",myfstat.st_uid,usr->pw_name,myfstat.st_uid,grp->gr_name);
			printf("\tPermission:\t%04o/",myfstat.st_mode);
			printperm(myfstat.st_mode);
			printf("\nDevice number:\t%lx(hex)/%ld(dec)\t",myfstat.st_dev,myfstat.st_dev);
			printf("Inode number:\t%li\n",myfstat.st_ino);
			printf("Hard Links:\t%ld\t",myfstat.st_nlink);
			printf("Device ID (special file):\t%lx\n",myfstat.st_rdev);
			printf("----------------------------------------------\nFilesystem:\t");
			printf("Total size (bytes):\t%ld\n",myfstat.st_size);
			printf("\t\tBlock size:\t\t%ld\n",myfstat.st_blksize);
			printf("\t\t512B blocks allocated:\t%ld\n",myfstat.st_blocks);
			printf("----------------------------------------------\nDate:\t");
			
			clock_gettime(CLOCK_REALTIME, &myfstat.st_atim);
			my_tm = localtime(&myfstat.st_atim.tv_sec);
			printf("Last access:\t\t%s",asctime(my_tm));

			clock_gettime(CLOCK_REALTIME, &myfstat.st_mtim);
			my_tm = localtime(&myfstat.st_mtim.tv_sec);
			printf("\tLast modification:\t%s",asctime(my_tm));

			clock_gettime(CLOCK_REALTIME, &myfstat.st_ctim);
			my_tm = localtime(&myfstat.st_ctim.tv_sec);
			printf("\tLast status change:\t%s",asctime(my_tm));
		} else {
			fprintf(stderr, "Error: %s\n", strerror( errno ));
		}

	}
}
