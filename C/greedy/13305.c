#include<stdio.h>
int main(){
  int arr_num;
  long long output=0;             //겁나 큰 long long 정수형 써야 10억 * 10억 연산 감당 가능함 ;;문제를 어떻게 이렇게주냐
  int length[100001];
  int oil;
  long long buffer;
  scanf("%d",&arr_num);           //2 ~ 100000
  for(int a=0;a<arr_num-1;a++){   //최소 1개는 들어감
    scanf("%d",&length[a]);
  }
  scanf("%lld",&buffer);            //무조건 하나는 들어감
  for(int a=1;a<arr_num;a++){     //최소 1번은 작동
    scanf("%d",&oil);
    if(buffer > oil){
      output += buffer*length[a-1];
      buffer = oil;
    }
    else{
      length[a] += length[a-1];
      if(a == arr_num-1){
        output += buffer*length[a-1];
      }
    }
  }
  printf("%lld",output);
}
