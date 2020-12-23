#include <stdio.h>
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if(n == 1){
        return 1;
    }
    else {
      return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main(){
  int in,a;
  int* x;
  scanf("%d",&in);
  x = calloc(in,sizeof(x));
  for(a=0;a<in;a++){
    scanf("%d",&x[a]);
  }
  for(a=0;a<in;a++){
    printf("%d %d\n",fibonacci(x[a]-1),fibonacci(x[a]));
  }
  free(x);
  return 0;
}
