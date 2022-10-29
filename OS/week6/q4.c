#include<stdio.h>
#include<stdlib.h>

int main(){
	int num = 0;
	FILE *fileout;
	fileout = fopen("ex-binary.bin","wb+");
	printf("Enter any 4 digits- \n");
	for(int i=0; i<4; i++)
	{
		scanf("%d",&num);
		fwrite(&num,sizeof(int),1,fileout);
	}
	printf("Writing in the file is now complete\n");
	fclose(fileout);
	printf("reading the binary file...\n");
	fileout=fopen("ex-binary.bin","rb");

	for(int i=0; i<4; i++)
	{
		fread(&num,sizeof(int),1,fileout);
		printf("%d\n",num);
	}
	fclose(fileout);
	return 0;

}