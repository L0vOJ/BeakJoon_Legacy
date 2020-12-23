#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

int main(){

}

int queue(){
  srand(time(0));
  int queue[4];
  int result[4];
  for(int a=0;a<4;a++){       //result[0]=rand()%4;   //2       //0           //1
    result[a]=rand()%(4-a);   //result[1]=rand()%3;   //0       //2           //1
  }                           //result[2]=rand()%2;   //1       //1           //0   //세번째:1203
  for(int a=0;a<3;a++){
    int count=0;
    for(int b=0;b<a;b++){
      if(result[a]>=result[b]){
        count++;
      }
    }
    queue[a]=result[a]+count;
  }
  for(int a=0;a<3;a++){
    int same=0;
    for(int b=0;b<3;b++){
      if(queue[b]==a){
        same++;
      }
    }
    if(same==0){
      queue[3]=a;
      break;
    }
  }
  for(int a=0;a<4;a++){
    printf("%d",queue[a]);
  }
}
