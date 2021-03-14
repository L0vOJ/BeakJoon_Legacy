#include<stdio.h>
#include<math.h>
int main(){
  int arr[20];
  for(int a=0;a<20;a++){
    arr[a]=1100001;
  }
  int in;
  scanf("%d",&in);
  int ha = pow(2,in)-1;
  printf("%d\n",ha);
  hanoi(arr,in-1,in);
  return 0;
}
int hanoi(int *arr,int dif,int in){
  int boo;
  if((in-dif)%2 == 0){
    boo=1;
  }
  else if((in-dif)%2 == 1){
    boo=-1;
  }
  if(dif == 0){
    printf("%d %d\n",arr[0]%3+1,(arr[0]+boo)%3+1);
    arr[0]+=boo;
    return 0;
  }
  hanoi(arr,dif-1,in);
  printf("%d %d\n",arr[dif]%3+1,(arr[dif]+boo)%3+1);
  arr[dif]+=boo;
  hanoi(arr,dif-1,in);
}
