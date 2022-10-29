#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int fle;    
    fle=open("text2.txt",O_RDONLY);
    int count=0;
    char out;
    char c;
    while(read(fle,&c,1)!=0){
        if(c=='\n'){
            count++;
            if(count%20==0){
                puts(" ");
                fgetc(stdin);
                //scanf("%hhd",&out);
            }
        }
        printf("%c",c);
    }
    puts(" ");
    return 0;
}