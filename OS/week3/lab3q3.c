#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>



int main()
{
    int status;
    pid_t pid;
    printf("Parent program starting.\n");
    pid=fork();
    switch(pid){



   case -1:
        {
            fprintf(stderr,"Fork Failed.");
            exit(-1);
        }



   case 0:
        {
            printf("Child process.\n");
            pid_t curr_pid = getpid();
            printf("Process ID of child process: %d\n",curr_pid);
            pid_t cur_pid = getppid();
            printf("Process ID of parent process: %d\n",cur_pid);
            exit(0);
        }
        break;


 
   default:
        {
            wait(&status);
            printf("Child program complete.\n");
            pid_t curr_pid = getpid();
            printf("Process ID of child process: %d\n",pid );
            printf("Process ID of parent process: %d\n",curr_pid);
            exit(0);
    
        }



   }
}