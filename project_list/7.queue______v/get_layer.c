#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

void change(int* arr);
void back_to_startline();
int* queue();

int main(){
  srand(time(0));
  int* arr;
  while(1){
    free(arr);
    arr=queue();
    for(int a=0;a<4;a++){
      printf("%d",arr[a]);
    }
    back_to_startline();
  }
}

int* queue(){
  int* arr;
  arr=calloc(4,sizeof(int));
  for(int a=0;a<4;a++){
    arr[a]=a;
  }
  for(int a=0;a<12;a++){
    change(arr);
  }
  return arr;
}
void change(int* arr){
  int buffer;
  int choice[2];
  for(int a=0;a<2;a++){
    choice[a]=rand()%4;    //rand 최대값: size-1; 배열 가장 큰 인덱스넘버와 같다
  }
  buffer = arr[choice[0]];
  arr[choice[0]] = arr[choice[1]];
  arr[choice[1]] = buffer; //교환 완료
}

void back_to_startline(){
  char check;
  printf("\t\t\t\t");
  scanf(" %c",&check);
}
