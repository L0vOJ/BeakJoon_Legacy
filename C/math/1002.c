#include <stdio.h>
#include <math.h>
int main(){
  int row,a,b,arr[6];
  double d;
  scanf("%d",&row);
  for(a=0;a<row;a++){
    for(b=0;b<6;b++){
      scanf("%d",&arr[b]);
    }
    d = sqrt(pow(arr[0] - arr[3],2) + pow(arr[1]-arr[4],2));
    if(d==0 && arr[2] == arr[5]){
      printf("-1\n");
    }
    else if(d == arr[2] + arr[5] || d == fabs(arr[2] - arr[5])){
      printf("1\n");
    }
    else if(d < fabs(arr[2] - arr[5]) || d > arr[2] + arr[5]){
      printf("0\n");
    }
    else{
      printf("2\n");
    }
  }
  return 0;
}
