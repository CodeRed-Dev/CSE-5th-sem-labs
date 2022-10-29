#include<pthread.h>
#include<stdio.h>

void *prime(void *param){
  int *arr =(int *)param;
  int count=0;
  printf("In the child thread \n");
  for(int i=arr[0];i<(arr[1]);i++){
    if(i==1 || i==0 )
      continue;
    for(int j=2;j<i;j++){
      if(i==2)
        break;
      if(i%j==0){
        count=1;
        break;
      }
    }
    if (count==0){
      printf("%d ",i);
    }
    else
      count=0;
  } 
}

int main()
{
  int arr[2];
  pthread_t thread;
  printf("In the main thread \n");
  printf("Enter the starting number \n");
  scanf("%d",&arr[0]);
  printf("Enter the ending number \n");
  scanf("%d",&arr[1]);
  pthread_create(&thread,0,&prime,(void *)arr);
  pthread_join(thread,0);
  printf("\nIn the main thread \n");
  //printf("%d",return_value);
  puts(" ");
  return 0;
}