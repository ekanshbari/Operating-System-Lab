//cp commond
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *arg[]){
printf("%s\n%s\n%s\n",arg[0],arg[1],arg[2]);
char buff[20];
int fd;
fd=open(arg[1],O_CREAT|O_RDWR,0777);
printf("write something with in 20 words\n");
int x = read(0,buff,20);
int y=write(fd,buff,x);
close(fd);
/*******************************************************/
int fd2=open(arg[2],O_CREAT|O_WRONLY,0777);
int z=write(fd2,buff,y);

close(fd2);
printf("writing successfully\n");
}
