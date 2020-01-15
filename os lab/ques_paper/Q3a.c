//create two threads and then terminate them.
#include<stdio.h>
#include<pthread.h>
void *fun1(void *arg);
void *fun2(void *arg);
int main(int argc, char const *argv[]) {
  /******************************************************/
  pthread_t t1;
  char msg1[20]="we are in thread 1";
  void *result1;
  pthread_create(&t1,NULL,fun1,msg1);
  pthread_join(t1,&result1);
  printf("thread 1 has been %s\n",result1);
  /******************************************************/
  pthread_t t2;
  char msg2[20]="we are in thread 2";
  void *result2;
  pthread_create(&t2,NULL,fun2,msg2);
  pthread_join(t2,&result2);
  printf("thread 2 has been %s\n",result2);
  return 0;
}
/******************************************************/
void *fun1(void *arg){
printf("%s\n",arg);
pthread_exit("done now it terminated");
}
/******************************************************/
void *fun2(void *arg){
printf("%s\n",arg);
pthread_exit("done now it terminated");
}
