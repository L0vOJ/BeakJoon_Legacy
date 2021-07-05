#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

int* arr_init(int size);
void change(int* arr,int size);
void back_to_startline();

int main(){
  srand(time(0));
  int size;
  int*arr;
  while(1){
    free(arr);
    printf("배열의 크기:");
    scanf("%d",&size);
    arr = arr_init(size);
    for(int a=0;a<pow(size,2)/2;a++){
      change(arr,size);
    }
    for(int a=0;a<size;a++){
      printf("%d",arr[a]);
    }
    back_to_startline();
  }
}
int* arr_init(int size){
  int* arr = calloc(size,sizeof(int));
  for(int a=0;a<size;a++){
    arr[a]=a+1;
  }
  return arr;
}

void change(int* arr,int size){
  int buffer;
  int choice[2];
  for(int a=0;a<2;a++){
    choice[a]=rand()%size;    //rand 최대값: size-1; 배열 가장 큰 인덱스넘버와 같다
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
