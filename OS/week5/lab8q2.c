#include<pthread.h>
#include<stdio.h>


void *Sum(void *param){
  int *arr=(int *)param;
  printf("In the child thread \n");
  int sum=arr[0]+arr[1];
  return (void *)sum;
}

int main()
{
  int arr[2];
  printf("In the main thread \n");
  printf("Enter the first number \n");
  scanf("%d",&arr[0]);
  printf("Enter the second number \n");
  scanf("%d",&arr[1]);
  pthread_t thread;
  int return_value;
  pthread_create(&thread,0,&Sum,(void*)arr);
  pthread_join(thread,(void**)&return_value);
  printf("In the main thread \n");
  printf("The sum of %d and %d is %d",arr[0],arr[1],return_value);
  puts(" ");
  return 0;
}