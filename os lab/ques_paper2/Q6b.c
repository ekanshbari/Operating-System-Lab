#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
struct data{
  int d1,d2;
};
void *fun1(void *arg);
void *fun2(void *arg);
int main(int argc, char const *argv[]) {
struct data dt;
dt.d1=11;
dt.d2=10;
int *result1;
int *result2;
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,&dt);
pthread_join(t1,&result1);
printf("Final sum = %d\n",result1);
/******************************************/
pthread_create(&t2,NULL,fun2,&dt);
pthread_join(t2,&result2);
printf("Final value of dt1 = %d\n",result2);
  return 0;
}
/**********************************************/
void *fun1(void *arg){
  struct data *ar=arg;
  int sum=(ar->d1+ar->d2);
  pthread_exit(sum);
}
/**********************************************/
void *fun2(void *arg){
  struct data *ar=arg;
  int val=ar->d1+1;
  pthread_exit(val);
}
