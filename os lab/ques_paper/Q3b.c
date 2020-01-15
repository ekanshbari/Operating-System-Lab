//Process synchronization using locks.
#include<stdio.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=1;
pthread_mutex_t l;
int main(int argc, char const *argv[]) {
pthread_mutex_init(&l,NULL);
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("Final Value of Shared Variable = %d\n",shared);
return 0;
}
/***********************************************************/
void *fun1(){
int x;
pthread_mutex_lock(&l);
x=shared;
x++;
sleep(1);
shared=x;
pthread_mutex_unlock(&l);
}
/***********************************************************/
void *fun2(){
int y;
pthread_mutex_lock(&l);
y=shared;
y--;
sleep(1);
shared=y;
pthread_mutex_unlock(&l);
}
