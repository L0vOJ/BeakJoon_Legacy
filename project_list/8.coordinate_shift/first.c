#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>

void set_pos(int x,int y);
int main(){
  int i=0;
  char*str = "hello c world";
  system("color fc");
  for(i=0;i<50;i++){
    SetPosition(i,1);
    puts(str);
    Sleep(100);
    system("cls");
  }
}
void set_pos(int x,int y){
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
