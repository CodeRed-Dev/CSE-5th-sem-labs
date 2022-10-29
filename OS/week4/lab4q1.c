#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("Incorrect number of arguments, Expected 1, Got: %d\n",argc-1);
		return 0;
	}
	struct stat statbuf;
	int returnvalue = stat(argv[1], &statbuf);
	if(returnvalue != 0){
		perror("stat");
		return 1;
	}
	printf("INPUT FILE NAME - %s\n", argv[1]);
	printf("INODE value - %ld\n",statbuf.st_ino);
	return 0;
}