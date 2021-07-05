#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
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
