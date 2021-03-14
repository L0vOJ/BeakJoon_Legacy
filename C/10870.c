#include <stdio.h>
#include <string.h>

int main(){
  int input;
  scanf("%d",&input);
  printf("%d",fibbo(input));
  return 0;
}
//strlen(input) ->해당 str의 길이
int fibbo(int a){
  switch(a){
    case 0:
      return 0;
    break;
    case 1:
    case 2:
      return 1;
    break;
    default:
      return fibbo(a-2) + fibbo(a-1);
    break;
  }
}
