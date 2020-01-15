#include<stdio.h>
int ar[100];

void check(int ar[], int,int);
int main(){

  for(int i=0;i<100;i++){
    ar[i]=0;
  }
int index,size;
printf("Enter tha starting position of file\n");
scanf("%d",&index);
printf("Enter tha size of file\n");
scanf("%d", &size);
check(ar,index,size);
int input;
printf("u want again enter then press 1 else 0\n");
scanf("%d",&input);
if (input==0) {
  return;
} else {
  printf("Enter tha starting position of file\n");
  scanf("%d",&index);
  printf("Enter tha size of file\n");
  scanf("%d", &size);
  check(ar,index,size);
}

}
/***************/
void check(int ar[],int index,int size) {
  for(int i=index;i<(index+size);i++){
    if(ar[i]==0){
      ar[i]=1;
      printf("\n%d->%d",i,ar[i]);
    }
    else{
      printf("Block already allocated");
      break;
    }
    if(i==(index+size))
    printf("\n the file is allocated to disk");
  }
}
