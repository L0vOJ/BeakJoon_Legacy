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
//bound - in = shift = 3 �ڷ� 3�� ����������
//ladder�� ¦�� -> ladder - shift / 1+shift
//ladder�� Ȧ�� -> 1+shift / ladder - shift
