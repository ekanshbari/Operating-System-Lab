//read from files
#include<stdio.h>
#include<fcntl.h>
int main(){
int fd;
char buffer[10]; 
fd=open("Test.txt",O_RDONLY,0777);
int x=read(fd,buffer,10);
write(1,buffer,x);
}
