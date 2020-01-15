#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
  char buffer[100];
  pid_t p;
  int fd[2];
  pipe(fd);
  p=fork();
  if (p>0) {
    close(fd[0]);
    printf("we are in parent write a msg to child:\n");
    int r=read(0,buffer,100);
    write(fd[1],buffer,r);
    wait();

  } else {
    close(fd[1]);
    int w=read(fd[0],buffer,100);
    printf("we are in child and msg is :\n");
    write(1,buffer,w);
    close(fd[1]);
  }
}
