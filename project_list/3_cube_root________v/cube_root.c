#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
root(double);
int main(){
  printf("�������� ���ϱ�\n");
  while(1){
    double input;
    printf("�Է°�:");
    scanf("%lf",&input);
    root(input);
    printf("�ٽ� �Է��Ͻ÷��� anyŰ�� �Է��Ͻÿ�\n");
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
    printf("��������:%lf\n",a);//input�� 1�̸� �� if�� ��ο� ��ġ�� �ʾ� �ڿ������� ���������� a �ʱⰪ�� 1�̶�� ��п� �����ϰ� �ȴ�
    return 0;
}
