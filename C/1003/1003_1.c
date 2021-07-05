#include <stdio.h>
int fibonacci(int n,int* p) {
    if (n == 0) {
        p[0]++;
        return 0;
    } else if(n == 1){
        p[1]++;
        return 1;
    }
    else {
      int c = fibonacci(n-1,p) + fibonacci(n-2,p);
      return c;
    }
}


int main(){
  int in,x[10] = {0},p[2] = {0};
  scanf("%d",&in);
  for(int a=0;a<in;a++){
    scanf("%d",&x[a]);
  }
  for(int a=0;a<in;a++){
    fibonacci(x[a],p);
    printf("%d %d\n",p[0],p[1]);
    p[0]=0;
    p[1]=0;
  }
}
