#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<time.h>

void printdir(char *dir,int depth){
    DIR *dp;
    struct stat statbuf;
    struct dirent *entry;
    if((dp=opendir(dir))==NULL){
        fprintf(stderr,"cannot open directory: %s",dir);
        return;
    }
    chdir(dir);
    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
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
        if(S_ISDIR(statbuf.st_mode)){
            if((strcmp(".",entry->d_name)==0)||(strcmp("..",entry->d_name)==0))
                continue;
            printf("%*s%s  \n",depth,"",entry->d_name);
            printf("%*sID - %ld\n",depth,"",statbuf.st_dev);
            printf("%*sInode number - %ld\n",depth,"",statbuf.st_ino);
            printf("%*sAccess mode - %s\n",depth,"",per );
            printf("%*sHard Links - %ld\n",depth,"",statbuf.st_nlink);
            printf("%*sUser ID -%d\n",depth,"",statbuf.st_uid);
            printf("%*sGroup ID -%d\n",depth,"",statbuf.st_gid);
            printf("%*sDevice Id (if special file) - %ld\n",depth,"",statbuf.st_rdev);
            printf("%*sSize - %ld\n",depth,"",statbuf.st_size);
            printf("%*sBlocksize - %ld\n",depth,"",statbuf.st_blksize);
            printf("%*sNumber of blocks allocated - %ld\n",depth,"",statbuf.st_blocks);
            printf("%*sLast access time - %s",depth,"",ctime(&statbuf.st_atime));
            printf("%*sLast modification time -%s",depth,"",ctime(&statbuf.st_mtime));
            printf("%*sLast Status change time - %s",depth,"",ctime(&statbuf.st_ctime));
            printf("\n\n");
            printdir(entry->d_name,depth+4);
        }
        else{
            printf("%*s%s \n",depth,"",entry->d_name);
            printf("%*sID - %ld\n",depth,"",statbuf.st_dev);
            printf("%*sInode number - %ld\n",depth,"",statbuf.st_ino);
            printf("%*sAccess mode - %s\n",depth,"",per );
            printf("%*sHard Links - %ld\n",depth,"",statbuf.st_nlink);
            printf("%*sUser ID -%d\n",depth,"",statbuf.st_uid);
            printf("%*sGroup ID -%d\n",depth,"",statbuf.st_gid);
            printf("%*sDevice Id (if special file) - %ld\n",depth,"",statbuf.st_rdev);
            printf("%*sSize - %ld\n",depth,"",statbuf.st_size);
            printf("%*sBlocksize - %ld\n",depth,"",statbuf.st_blksize);
            printf("%*sNumber of blocks allocated - %ld\n",depth,"",statbuf.st_blocks);
            printf("%*sLast access time - %s",depth,"",ctime(&statbuf.st_atime));
            printf("%*sLast modification time -%s",depth,"",ctime(&statbuf.st_mtime));
            printf("%*sLast Status change time - %s",depth,"",ctime(&statbuf.st_ctime));
            printf("\n\n");
        }
    }
    chdir("..");
    closedir(dp);
}

int main(){
    char str[100];
    //size_t size=100;
    getcwd(str,sizeof(str));
    printdir(str,1);
    return 0;
}