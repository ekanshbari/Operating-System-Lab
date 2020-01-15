#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int fd1;// to access file in other function
int x,w,r;
char buffer[100];
void *readd();
void *writed();

int main(int argc, char const *argv[]) {
  pthread_t t1,t2;
  fd1 = open("nikhil.txt",O_CREAT|O_RDWR,0777);
  pthread_create(&t1,NULL,writed,NULL);
  pthread_join(t1,NULL);
  printf("THREAD 1 DONE\n");
  /********************************************/
  pthread_create(&t2,NULL,readd,NULL);
  pthread_join(t2,NULL);
  printf("THREAD 2 DONE\n");
  return 0;
}
/****************************************/
void *writed(){
  printf("Enter something:\n");
  r=read(0,buffer,100);
  w=write(fd1,buffer,r);
  pthread_exit(NULL);
}
/****************************************/
void *readd(){
  printf("reading something:\n");
  x=read(fd1,buffer,w);
  write(1,buffer,w);
  pthread_exit(NULL);
}
