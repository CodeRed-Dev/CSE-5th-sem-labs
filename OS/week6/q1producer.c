#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"

int main()
{
	int pipe_fd;
	int res;
	int open_mode=O_WRONLY;
	if (access(FIFO_NAME,F_OK)==-1){
		res=mkfifo(FIFO_NAME,0777);
		if (res!=0){
			fprintf(stderr,"Could not Create fifo %s\n",FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	printf("Process %d opening FIFO O_WRONLY\n",getpid());
	pipe_fd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pipe_fd);
	if (pipe_fd!=-1){
		for(int i=0;i<4;i++){
			write(pipe_fd,&i,sizeof(int));
		}
		(void)close(pipe_fd);
	}
	else{
		exit(EXIT_SUCCESS);
	}
	printf("Process %d finished \n",getpid());
	exit(EXIT_SUCCESS);
}