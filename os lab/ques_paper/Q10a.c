//zombie or parent wait till child excution completed.
#include<stdio.h>
#include<fcntl.h>
int main(int argc, char const *argv[]) {
  pid_t pid;
  pid=fork();
  wait();
  if (pid==0) {
    printf("i am child , parent should for me.\n");
    sleep(3);
  } else {
    printf("hi i am parent , now i am going shine off\n");
  }
  return 0;
}
