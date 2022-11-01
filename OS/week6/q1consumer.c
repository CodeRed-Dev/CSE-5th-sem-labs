#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "/tmp/raghav"

int main()
{
	int pipe_fd;
	int res;
	int open_mode=O_RDONLY;
	printf("Process %d opening FIFO O_RDONLY\n",getpid());
	pipe_fd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pipe_fd);
	if (pipe_fd!=-1){
		for(int i=0;i<4;i++){
			int num;
			res=read(pipe_fd,&num,sizeof(num));
			printf("%d ",num);
		}
		(void)close(pipe_fd);
	}
	else{
		exit(EXIT_SUCCESS);
	}
	printf("\nProcess %d finished \n",getpid());
	exit(EXIT_SUCCESS);
}
