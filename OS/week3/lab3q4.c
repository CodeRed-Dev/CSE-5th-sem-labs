
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{

   
    printf("[*] Starting parent process\n");
    int r_val = fork();

 
    switch (r_val)
    {

  
    case -1:
    {
        perror("[*] fork\n");
        exit(EXIT_FAILURE);
    }
    break;

    
    case 0:
    {
        printf(" Inside child process\n");

        pid_t curr_ppid = getppid();
        printf(" Current parent: %d\n", curr_ppid);
       

       
        //curr_ppid = getppid();
       // printf(" Current parent: %d\n", curr_ppid);

       
        exit(0);
    }
    break;
    
   
    default:
    {

        
        for (int i = 0; i < 5; i++)
        {
            sleep(1);
            //printf(" Sleeping child for %d seconds...\n", i + 1);

        }
        printf("wait for 5 seconds\n");
        printf(" Executing ps\n");
        execl("/bin/ps", "ps", NULL);

        exit(0);
    }
    }
}

/*

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 
int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
 
    if(pid < 0)
    {
        printf("Error\n");
        exit(-1);
    }
 
    if(pid == 0)
        { //child process
        printf("child process\n");
        exit(0);
    }
 
    else
    { //parent process
        sleep(2);
        printf("parent process\n");
    }
 
    return 0;
}*/