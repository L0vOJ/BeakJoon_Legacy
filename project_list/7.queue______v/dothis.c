#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
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
    printf("�迭�� ũ��:");
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
    choice[a]=rand()%size;    //rand �ִ밪: size-1; �迭 ���� ū �ε����ѹ��� ����
  }
  buffer = arr[choice[0]];
  arr[choice[0]] = arr[choice[1]];
  arr[choice[1]] = buffer; //��ȯ �Ϸ�
}

void back_to_startline(){
  char check;
  printf("���� ���ϰ��� �Ѵٸ� anyŰ�� �Է��Ͻÿ�");
  scanf(" %c",&check);
  system("cls");
}
