#include<stdio.h>
int main(){                   //성공!
  int arr[40]={'\0'};
  int zz=1;
  scanf("%c",&arr[0]);        //1이라고 적으면 49라고 저장됨 //\n(엔터)의 정수형d는 10이다
  while(arr[zz-1]!='\n'){
    scanf("%c",&arr[zz]);
    zz++;
  }                    //2342엔터 라고 친다면 51/52/53/52/10 이 정수형으로 저장된다 //그냥 엔터만 치면 zz=1, 숫자 5개 치고 엔터 치면 zz=6
  for(int a=0;a<zz-1;a++){
    arr[a]-=48;
    printf("%d",arr[a]);
  }
}
