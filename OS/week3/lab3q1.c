#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
    
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

    
        for (int i = 0; i < 10; i++)
        {
            sleep(1);
            printf(" Sleeping child for %d seconds...\n", i + 1);
        }

       
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

// creating child and parent process
    // storing process id in `r_val`
    //printf("[*] Starting parent process\n");

    // switching between different processes


    // in case some error occurs in creation


    // in case of child process

    // Sleeping...

 // exiting from the child program

// in case of parent class


        // waiting for child process to finish executing


        // exiting from the parent program 