//Zombie process
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main(int argc, char const *argv[]) {
  pid_t p;
  p=fork();
  if (p>0) {
    sleep(5);
    printf("IN PARENT\n");
  } else if (p<0) {
    printf("Error\n");
  }
  else{
    printf("IN CHILD\n");
    exit(0);
  }
  return 0;
}
