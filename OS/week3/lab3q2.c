#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    printf(" Starting parent process\n");
    int r_val = fork();

    switch (r_val)
    {


    case -1:
    {
        perror(" fork\n");
        exit(EXIT_FAILURE);
    }
    break;


    case 0:
    {
        printf(" Inside child process\n");
        printf(" Executing ./q1 inside child\n");

        
        execlp("./q1", NULL);

        
        exit(0);
    }
    break;

    default:
    {
        printf(" Waiting for child\n");

        wait(NULL);
        printf(" Child process finished execution\n");

        exit(0);
    }
    }
}