#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>

typedef struct{
  int a;
  int b;
  int c;
  int d;
}hello;
int main(){
  int* hi;
  hi=malloc(8);
  printf("%d\n",sizeof(hi));
  hi = realloc(hi,10*sizeof(hi));
  printf("%d",sizeof(hello));
}
