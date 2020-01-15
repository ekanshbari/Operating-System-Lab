//race condition
#include<stdio.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=2;
int main(int argc, char const *argv[]) {
  pthread_t t1,t2;
  pthread_create(&t1,NULL,fun1,NULL);
  pthread_create(&t2,NULL,fun2,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  printf("Final Value of Shared Variable -> %d\n",shared);
  return 0;
}
void *fun1(){
  int x;
  x=shared;
  x++;
  sleep(1);
  shared=x;
}
void *fun2(){
  int y;
  y=shared;
  y--;
  sleep(1);
  shared=y;
}
