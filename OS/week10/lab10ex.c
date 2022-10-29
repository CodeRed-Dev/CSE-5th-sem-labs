#include <stdio.h>
int main()
{
	int numSector = 10;
	char sector[1024];
	FILE* disqueF = fopen("/dev/sda6","r");
	fseek(disqueF,numSector*512,SEEK_SET);
	fread(sector,1024,1,disqueF);

	//print("%s",sector);
	for(int i=0;i<sizeof(sector);i++)
	{
		printf("%x",sector[i]);
		if((i+1)%16==0)
		{
			printf("\n");
		}

	}
	fclose(disqueF);
	return 0;	
}