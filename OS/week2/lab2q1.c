/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

/*int main()
{
	char dir[250];

	if(!getcwd(dir,sizeof(dir)))
	{
		printf("Directory name is exceeds the buffer size\n");
	}
	DIR *dp;
	struct direct *entry;
	struct direct *filestat;

	if((dp = opendir(dir))==NULL)
	{
		printf("Cannot open the directory\n");
	}
	else
	{
		while((entry = readdir(dp))!=NULL);
		{
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0){
				continue;
			}  
		}
	}
}*/


/*void listFiles(char *path);


int main()
{
  
    char path[100];

   
    printf("Enter path to list files: ");
    scanf("%s", path);
    //printdir("/home/student/Desktop",1);
    
    //getcwd(path, sizeof(path));
    //printf(path,1);
	listFiles(path);

    return 0;
}


void listFiles(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    struct stat statbuf;


 
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
        //if(S_ISDIR(statbuf.st_mode)){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        continue;
    else
        {	
            printf("\t%s\n", dp->d_name);
             lstat(dp->d_name, &statbuf);
            printf((S_ISDIR(statbuf.st_mode))  ? "d" : "-");
				printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
				printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
				printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
				printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
				printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
				printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
				printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
				printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
				printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
				printf("\t%ld",statbuf.st_size);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFiles(path);
        }
   // }
    

    closedir(dir);
}
*/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir)
{
    // printf("%s\n", dir);
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if (!(dp = opendir(dir)))
    {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while ((entry = readdir(dp)))
    {
        char priviledge[10] = "----------";
        // printf("%s\n", priviledge);
        lstat(entry->d_name, &statbuf);

        if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
            continue;
        if (S_ISDIR(statbuf.st_mode))
            priviledge[0] = 'd';
        if (statbuf.st_mode & S_IRUSR)
            priviledge[1] = 'r'; /* 3 bits for user  */
        if (statbuf.st_mode & S_IWUSR)
            priviledge[2] = 'w';
        if (statbuf.st_mode & S_IXUSR)
            priviledge[3] = 'x';

        if (statbuf.st_mode & S_IRGRP)
            priviledge[4] = 'r'; /* 3 bits for group */
        if (statbuf.st_mode & S_IWGRP)
            priviledge[5] = 'w';
        if (statbuf.st_mode & S_IXGRP)
            priviledge[6] = 'x';

        if (statbuf.st_mode & S_IROTH)
            priviledge[7] = 'r'; /* 3 bits for other */
        if (statbuf.st_mode & S_IWOTH)
            priviledge[8] = 'w';
        if (statbuf.st_mode & S_IXOTH)
            priviledge[9] = 'x';
        printf("%s ", priviledge);
        printf("%s\n", entry->d_name);

        // if (S_IRUSR(statbuf.st_mode))
        //     priviledge[1] = 'd';
        // if (S_IWUSR(statbuf.st_mode))
        //     priviledge[2] = 'd';
        // if (S_IXUSR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
        // if (S_ISDIR(statbuf.st_mode))
        //     priviledge[0] = 'd';
    }
    // chdir("..");
    closedir(dp);
}
int main()
{
    printdir("/home/student/Desktop");
}
