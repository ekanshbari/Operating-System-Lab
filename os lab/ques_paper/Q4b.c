//Process synchronization using locks.
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t sem;
int main(int argc, char const *argv[]) {
sem_init(&sem,0,1);
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
sem_wait(&sem);
x=shared;
x++;
sleep(1);
shared=x;
sem_post(&sem);
}
/***********************************************************/
void *fun2(){
int y;
sem_wait(&sem);
y=shared;
y--;
sleep(1);
shared=y;
sem_post(&sem);
}
