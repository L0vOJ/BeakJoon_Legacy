#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
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
    choice[a]=rand()%4;    //rand �ִ밪: size-1; �迭 ���� ū �ε����ѹ��� ����
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
