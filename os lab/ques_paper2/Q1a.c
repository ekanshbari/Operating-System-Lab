//orphan process
#include<stdio.h>
#include<fcntl.h>
int main(int argc, char const *argv[]) {
  pid_t pid;
  pid=fork();
  if(pid>0){
    printf("i am parent....\n");
  }
  else{
    sleep(5);
    printf("I am child\n");
  }
  return 0;
}
