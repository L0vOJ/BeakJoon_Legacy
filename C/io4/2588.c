#include <stdio.h>
int main(){
  int a,b,c;
  scanf("%d",&a);
  scanf("%d",&b);
  c = b%10;
  printf("%d\n%d\n%d\n%d\n",a*c,a*((b%100)-c)/10,a*(b/100),a*b);
}

//�������� ���� �� ���� ���ϴ� ���� �ٽ�
//%10, %100���� ���Ѵ�
