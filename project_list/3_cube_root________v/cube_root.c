#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
root(double);
int main(){
  printf("세제곱근 구하기\n");
  while(1){
    double input;
    printf("입력값:");
    scanf("%lf",&input);
    root(input);
    printf("다시 입력하시려면 any키를 입력하시오\n");
    int zz;
    scanf("%d",&zz);
    system("cls");
  }
}
root(double input){
    double a=1;
    double balance=1;
    if(input>1){
      for(int t=0;t<7;t++){
        while(a*a*a<input){
          a+=balance;
        }
        if(a*a*a == input){
          break;
        }
        a-=balance;
        balance /= 10;
      }
    }
    else if(input<1){
      balance /=10;
      for(int t=0;t<6;t++){
        while(a*a*a>input){
          a-=balance;
        }
        if(a*a*a == input){
          break;
        }
        a+=balance;
        balance /= 10;
      }
    }
    printf("세제곱근:%lf\n",a);//input이 1이면 두 if문 모두에 걸치지 않아 자연스럽게 세제곱근이 a 초기값인 1이라는 결론에 도달하게 된다
    return 0;
}
