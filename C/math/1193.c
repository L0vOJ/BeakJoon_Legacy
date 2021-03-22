#include <stdio.h>
int main(){
  int in,bound=1,ladder=1;
  scanf("%d",&in);
  if(in == 1){
    printf("1/1");
    return 0;
  }
  while(in > bound){
    ladder++;
    bound += ladder;
  }
  if(ladder%2==0){
    printf("%d/%d",ladder - bound + in,1 + bound - in);
  }
  else{
    printf("%d/%d",1 + bound - in,ladder - bound + in);
  }
  return 0;
}

//in=7
//bound - in = shift = 3 뒤로 3번 움직여야함
//ladder가 짝수 -> ladder - shift / 1+shift
//ladder가 홀수 -> 1+shift / ladder - shift
