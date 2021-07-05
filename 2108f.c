#include<stdio.h>
//O(n^2)�� ���� �ð��ʰ�
//-4000���� 4000���� ���� ������ stack�ϴ� ������� �ٽ� ¥�� �� �ٵ� ���Ұ���
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

int first(int* arr,int in){ //1.������
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
//2.�߾Ӱ� arr[in/2]
int third(int* arr,int in){ //3.�ֺ�
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
//4.���� arr[0]-arr[in]
