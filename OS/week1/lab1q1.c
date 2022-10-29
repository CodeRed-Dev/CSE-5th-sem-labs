#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[]){
    char c;
    int i=0,count=0;
    char *str=argv[1];
    char *st=" ";
    strcat(str,st);
    int fle;    
    fle=open("text.txt",O_RDONLY);
    while(read(fle,&c,1)==1){
        if (c==str[i]){
            count++;
            i++;
            if (count==strlen(str))
                break;
        }
        else{
            count=0;
            i=0;
        }
    }
    off_t num=1;
    while(c!='\n'){
        lseek(fle,-num,SEEK_CUR);
        num++;
        read(fle,&c,1);
    }

    read(fle,&c,1);
    while(c!='\n'){
        printf("%c",c);
        read(fle,&c,1);
    }
    puts(" ");
    return 0;
    close(fle);

}