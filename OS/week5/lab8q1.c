#include<pthread.h>
#include<stdio.h>

struct array{
  int arr[20];
  int size;
};


void *Fibonacci(void *param){
  int fst=0,lst=1;
  printf("In the child thread \n");
  struct array *ar=(struct array *)param;
  for(int i=0;i<ar->size;i++){
    ar->arr[i]=fst;
    int temp=lst;
    lst=lst+fst;
    fst=temp;
  }
}

int main()
{
  printf("Enter the number\n");
  int num;
  scanf("%d",&num);
  struct array *ar;
  ar->size=num;
  pthread_t thread;
  pthread_create(&thread,0,&Fibonacci,(void *)ar);
  pthread_join(thread,0);
  printf("In the main thread \n");
  for(int i=0;i<num;i++){
    printf("%d ",ar->arr[i]);
  }
  puts(" ");
  return 0;
}