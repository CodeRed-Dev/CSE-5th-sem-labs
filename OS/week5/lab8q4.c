#include<pthread.h>
#include<stdio.h>


void *Sume(void *param){
	int *arr=(int *)param;
	printf("In the child thread \n");
	int sum=0;
	for (int i=1;i<arr[0];i++){
		if(arr[i]%2==0)
			sum+=arr[i];
	}
	return (void *)sum;
}

void *Sumo(void *param){
	int *arr=(int *)param;
	printf("In the child thread \n");
	int sum=0;
	for (int i=1;i<arr[0];i++){
		if(arr[i]%2!=0)
			sum+=arr[i];
	}
	return (void *)sum;
}


int main()
{
	int num;
	printf("In the main thread \n");
	printf("Enter the size of the array \n");
	scanf("%d",&num);
	int arr[num+1];
	arr[0]=num+1;
	printf("Enter the elements of the array : ");
	for (int i = 1; i < num+1; ++i)
	{
		scanf("%d",&arr[i]);
	}
	pthread_t thread1,thread2;
	int sum_even,sum_odd;
	pthread_create(&thread1,0,&Sume,(void*)arr);
	pthread_join(thread1,(void**)&sum_even);
	pthread_create(&thread2,0,&Sumo,(void*)arr);
	pthread_join(thread2,(void**)&sum_odd);
	printf("In the main thread \n");
	printf("The sum of even numbers is %d and odd numbers is %d ",sum_even,sum_odd);
	puts(" ");
	return 0;
}