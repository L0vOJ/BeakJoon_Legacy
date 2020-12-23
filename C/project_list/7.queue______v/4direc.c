#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

void change(int* arr);
void back_to_startline();

int main(){
  srand(time(0));
  int arr[4];
  while(1){
    for(int a=0;a<4;a++){
      arr[a]=a+1;
    }
    for(int a=0;a<12;a++){
      change(arr);
    }
    for(int a=0;a<4;a++){
      printf("%d",arr[a]);
    }
    back_to_startline();
  }
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
  printf("새로 구하고자 한다면 any키를 입력하시오");
  scanf(" %c",&check);
  system("cls");
}
