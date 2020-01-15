#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
int main(int argc, char const *argv[]) {
  mkdir("sakshi",0777);
  DIR *dr=opendir("sakshi");
  if(dr==NULL){
    printf("ERROR 404 !\n");
  }else{
    printf("FILE SUCCESSFULLY FOUND\n");
  }
  struct dirent *rd;
  while((rd=readdir(dr))!=NULL){
    printf("NAME OF FILE %s\n",rd->d_name);
    
  }
  return 0;
}
