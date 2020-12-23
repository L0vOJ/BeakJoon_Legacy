#include<stdio.h>
const double table=10;
const int goal=9;
int main(){
  for(int b=1;b<goal;b++){
    for(int c=b;c<goal;c++){
      printf("%lf\t",(1/table)*c);
    }
    printf("\n");
  }
}
