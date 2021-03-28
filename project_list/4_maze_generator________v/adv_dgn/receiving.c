#include<stdio.h>
#include<string.h>

void route_order(char* buffer);

int main(){
  FILE *fptr;
  fptr = fopen("filename.txt","r");
  char buffer[1000];
  fgets(buffer,1000,fptr);
  route_order(buffer);
}

void route_order(char* buffer){
  int a=0;
  while(buffer[a]){
    switch(buffer[a]){
      case '1':{
        printf("up()/");
      }break;
      case '2':{
        printf("right()/");
      }break;
      case '3':{
        printf("down()/");
      }break;
      case '4':{
        printf("left()/");
      }break;
      case '5':{
        printf("Ææ ¶¼±â/");
      }break;
      case '6':{
        printf("Ææ Âï±â/");
      }
    }
    if(a%8==7){
      printf("\n\n");
    }
    a++;
  }
  printf("%d",a);
}
