#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int score;
  int prev;
}arr;
int main(){
  int ladder[301];
  arr stack[301];
  int n;
  scanf("%d",&n);
  for(int a=0;a<n;a++){
    scanf("%d",&ladder[a]);
    stack[a].prev=0;
  }
  stack[0].score = ladder[0];
  if(n>2){
    stack[1].score = stack[0].score+ladder[1];
    stack[1].prev=1;
  }
  for(int a=2;a<n;a++){
    if(stack[a-1].prev == 0 && stack[a-2].score < stack[a-1].score){
      stack[a].score = stack[a-1].score;
      stack[a].prev = 1;
    }
    else{
      stack[a].score = stack[a-2].score;
    }
    stack[a].score+=ladder[a];
  }
  printf("%d",stack[n-1].score);
}
