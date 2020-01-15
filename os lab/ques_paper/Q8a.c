//copy using system call
#include<stdio.h>
#include<fcntl.h>
int main(){
char buff[20];
int fd;
fd=open("golu.txt",O_CREAT|O_RDWR,0777);
printf("write something with in 20 words\n");
int x = read(0,buff,20);
int y=write(fd,buff,x);
/*******************************************************/
int fd2=open("golu1.txt",O_CREAT|O_WRONLY,0777);
int z=write(fd2,buff,y);
close(fd);
close(fd2);
printf("writing successfully\n");
}
