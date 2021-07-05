#include <stdio.h>
int main(){
  int a,b,t=0;;
  int output[10001];
  while(1){
    scanf("%d %d",&a,&b);
    if(a == 0 || b == 0){
      break;
    }
    if(a>b){
      if(a%b == 0)
        output[t]=1;  //multiple
      else
        output[t]=0;
    }
    else{
      if(b%a == 0)
        output[t]=2;  //factor
      else
        output[t]=0;
    }
    t++;
  }
  for(int z=0;z<t;z++){
    switch (output[z]) {
      case 0:
        printf("neither\n");
        break;
      case 1:
        printf("multiple\n");
        break;
      case 2:
        printf("factor\n");
        break;
    }
  }
}
