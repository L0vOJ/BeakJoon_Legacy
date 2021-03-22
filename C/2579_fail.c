#include<stdio.h>
int tree(int in,int x,int current, int* arr, int* goal){
  if(current >= *goal){
    return 0;
  }
  if(in - x == 3){
    current += arr[x+1];
    tree(in,x+3,current,arr,goal);
    return 0;
  }
  if(in - x == 4){
    current += arr[x] + arr[x+2];
    tree(in,x+4,current,arr,goal);
    return 0;
  }
  if(in == x){
    *goal = current;
    return 0;
  }
  tree(in,x+2,current+arr[x],arr,goal);
  tree(in,x+3,current+arr[x+1],arr,goal);
  return 0;
}

int main(){
  int in,sum=0,current=0,x=1;
  int arr[300] = {0,};
  int goal[1] = {3000000};
  scanf("%d",&in);
  for(int a=0;a<in;a++){
    scanf("%d",&arr[a]);
    sum += arr[a];
  }
  tree(in,x,current,arr,goal);
  printf("%d",sum - *goal);
  free(arr);
  return 0;
}




/*총 합에서 빼는 것도 생각해볼 수 있음
한번 건너뛰고 뺄지 두번 건너뛰고 뺄지 고려하기
뺄샘의 총합이 가장 적은 것만 살려준다
뺄샘의 총합이 가장 적은 것보다 커지면 바로 컷
막계단에서 2계단 남을 수 있음
막계단까지 3계단 남았으면 바로 101 실행
막계단까지 4계단 남았으면 바로 0101 실행
그 외 막계단 경우수는 고려 x
arr의 마지막 계단은 arr[in-1]에 있음

10->무조건 1
11->무조건 0
01->01,101 or 01,01





*/
