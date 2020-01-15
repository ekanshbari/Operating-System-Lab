//last 10 char
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char const *argv[]) {
  char buffer[10];
  int fd=open("Test.txt",O_RDONLY,0777);
  int a=lseek(fd,-10,SEEK_END);
  int z=read(fd,buffer,10);
  write(1,buffer,z);
  return 0;
}
