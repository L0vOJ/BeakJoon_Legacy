#include <stdio.h>
int main(){
  int in,result=1,ladder=2;
  scanf("%d",&in);
  if(in == 1){
    printf("1");
    return 0;
  }
  while(in >= ladder){
    ladder += 6*result;
    result +=1;
  }
  printf("%d",result);
  return 0;
}
