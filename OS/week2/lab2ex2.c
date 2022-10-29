 /*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

void printdir(char *dir,int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr,"Cannot open directory: %s\n",dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s\n",depth,"",entry->d_name);
            printdir(entry->d_name,depth+4);

        }
        else
            printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

int main()
{
    printf("Directories and Subdirectories:\n");
    printdir("/home/student/Desktop",1);
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

void printdir(char *dir,int depth){
    DIR *dp;
    struct stat statbuf;
    struct dirent *entry;
    if((dp=opendir(dir))==NULL){
        fprintf(stderr,"cannot open directory: %s\n",dir);
        return;
    }
    chdir(dir);
    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if((strcmp(".",entry->d_name)==0)||(strcmp("..",entry->d_name)==0))
                continue;
            printf("%*s%s\n",depth,"",entry->d_name);
            printdir(entry->d_name,depth+4);
        }
        else
            printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

int main(){
    //char str[] = "/home/student/Desktop";
    printdir("/home/student/Desktop",1);
    return 0;
}