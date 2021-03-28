#include<stdio.h>
#include<string.h>
int main(){
  char arr[100];
  for(int a=0;a<50;a++){
    arr[a]=a;
  }
  for(int c=0;c<50;c++){
    printf("%d",arr[c]);
  }
  for(int b=0;b<50;b++){
    arr[b]+=48;
  }
  printf("\n");
  arr[50]='\0';
  printf("%d",strlen(arr));
  printf("\n");
  printf("%s",arr);
}
