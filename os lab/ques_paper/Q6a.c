//duplicate a process.
#include<stdio.h>
#include<unistd.h>
int main(int argc, char const *argv[]) {
  pid_t pid;
  printf("This is Parent PID -> %d\n",getpid());
  pid=fork();
  wait();
  if (pid==0) {
    printf("This is child PID -> %d and This is parent -> %d\n",getpid(),getppid());
  }
  else{
    pid=fork();
    if (pid==0) {
      printf("This is child PID -> %d and This is parent -> %d\n",getpid(),getppid());
    }

  }
  return 0;
}


/*                         A
                        /     \
                      B         C



                      */
