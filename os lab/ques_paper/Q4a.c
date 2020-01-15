#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  int fd[2];
  char buff[20];
  pid_t p;
  pipe(fd);
  p=fork();
  if(p>0){
    close(fd[0]);//no process can write on pipe
    printf("parent sendinga message to child\n");
    write(fd[1],"hello child",12);//writing to child
    wait();//waiting for child to comlete excution
  }else//child
  {
    close(fd[1]);//no process can write on pipe
    printf("child reading the message\n");
    int n=read(fd[0],buff,20);//reading the message in pipe
    write(1,buff,n);//write on console

  }
  return 0;
}
