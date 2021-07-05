#include<stdio.h>
//O(n^2)로 인한 시간초과
//-4000부터 4000까지 구간 나눠서 stack하는 방식으로 다시 짜야 함 근데 안할거임
void sort(int* arr,int in);
int first(int* arr,int in);
int third(int* arr,int in);

int main(){
  int in,seq;
  int* arr[500000];
  scanf("%d",&in);
  for(int a=0;a<in;a++){
    scanf("%d",&seq);
    arr[a] = seq;
  }
  sort(arr,in);
  int middle = (in-1)/2;
  printf("\n%d\n%d\n%d\n%d\n",first(arr,in),arr[middle],third(arr,in),arr[0]-arr[in-1]);
}

void sort(int* arr,int in){
  int buffer;
  while(1){
    int check=1;
    for(int a=0;a<in-1;a++){
      if(arr[a]<arr[a+1]){
        buffer = arr[a+1];
        arr[a+1] = arr[a];
        arr[a] = buffer;
        check=0;
      }
    }
    if(check)break;
  }
}

int first(int* arr,int in){ //1.산술평균
  int sum=0;
  double result;
  for(int a=0;a<in;a++){
    sum+=arr[a];
  }
  result = (double)sum/in;
  if(result - sum/in>=0.5){
    result = sum/in+1;
  }
  if(result - sum/in <= -0.5){
    result = sum/in-1;
  }
  return result;
}
//2.중앙값 arr[in/2]
int third(int* arr,int in){ //3.최빈값
  int streak=0,stack=0,result,buffer,dup=1;
  for(int a=0;a<in-1;a++){
    if(arr[a]==arr[a+1]){
      stack++;
    }
    else{
      if(stack>streak){
        streak = stack;
        result = a;
        dup=1;
      }
      else if(stack == streak){
        if(dup){
          buffer = a;
          dup=0;
        }
        else{
          result = buffer;
          buffer = a;
        }
      }
      stack=0;
    }
  }
  if(streak==0){
    if(in==1){
      return arr[0];
    }
    else
      return arr[in-2];
  }
  else
    return arr[result];
}
//4.범위 arr[0]-arr[in]
