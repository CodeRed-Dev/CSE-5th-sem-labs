#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


void printlink(char *filepath){
 
    char *newpath = "newsoftpath.c";
    int ret = symlink(filepath,newpath);
    if(ret)
        perror("link");
    printf("%s\n",newpath);
    system("ls");
    unlink(newpath);
    printf("New Path Unlinked\n");
    system("ls");
}

int main()
{
    char filepath[20];
    printf("Enter the filename path : ");
    scanf("%s",filepath);
    printlink(filepath);
    return 0;
}