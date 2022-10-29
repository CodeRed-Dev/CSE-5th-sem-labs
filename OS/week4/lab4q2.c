    #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<time.h>

void printfile(char *filename){
    struct stat statbuf;
    stat(filename,&statbuf);
    char per[]="----------";
    if(S_ISDIR(statbuf.st_mode)){
        per[0]='d';
    }
    if(statbuf.st_mode & S_IREAD){
        per[1]='r';
    }
    if(statbuf.st_mode & S_IWRITE){
        per[2]='w';
    }
    if(statbuf.st_mode & S_IEXEC){
        per[3]='x';
    }
    if(statbuf.st_mode & S_IRGRP){
        per[4]='r';
    }
    if(statbuf.st_mode & S_IWGRP){
        per[5]='w';
    }
    if(statbuf.st_mode & S_IXGRP){
        per[6]='x';
    }
    if(statbuf.st_mode & S_IROTH){
        per[7]='r';
    }
    if(statbuf.st_mode & S_IWOTH){
        per[8]='w';
    }
    if(statbuf.st_mode & S_IXOTH){
        per[9]='x';
    }
    printf("ID - %ld\n",statbuf.st_dev);
    printf("Inode number - %ld",statbuf.st_ino);
    printf("Access mode - %s\n",per );
    printf("Hard Links - %ld\n",statbuf.st_nlink);
    printf("User ID -%d\n",statbuf.st_uid);
    printf("Group ID -%d\n",statbuf.st_gid);
    printf("Device Id (if special file) - %ld\n",statbuf.st_rdev);
    printf("Size - %ld\n",statbuf.st_size);
    printf("Blocksize - %ld\n",statbuf.st_blksize);
    printf("Number of blocks allocated - %ld\n",statbuf.st_blocks);
    printf("Last access time - %s",ctime(&statbuf.st_atime));
    printf("Last modification time -%s",ctime(&statbuf.st_mtime));
    printf("Last Status change time - %s",ctime(&statbuf.st_ctime));
}

int main()
{
    char filename[20];
    printf("Enter the filename : ");
    scanf("%s",filename);
    printfile(filename);
    return 0;
}