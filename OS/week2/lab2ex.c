#include<stdio.h>
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
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0  
		}
	}
}*/
void printdir(char *dir,int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if(dp = opendir(dir)==NULL){
		fprintf((dp = opendir(dir))==NULL)
		return;
	}
	chdir(dir);
	while((entry = readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0 )
				continue;
			printf("%*s%s/\n",depth,entry->d_name);
			printdir(entry->d_name,depth+3);	
		}
		else printf("%*s%s/\n",depth,entry->d_name);
	}
	chdir("..");
	closedir(dp);
}

int main(){
	printdir("/home/student/Desktop",1);
	return 0;
}