#include<stdio.h>
int main(){
  int arr_num;
  long long output=0;             //�̳� ū long long ������ ��� 10�� * 10�� ���� ���� ������ ;;������ ��� �̷����ֳ�
  int length[100001];
  int oil;
  long long buffer;
  scanf("%d",&arr_num);           //2 ~ 100000
  for(int a=0;a<arr_num-1;a++){   //�ּ� 1���� ��
    scanf("%d",&length[a]);
  }
  scanf("%lld",&buffer);            //������ �ϳ��� ��
  for(int a=1;a<arr_num;a++){     //�ּ� 1���� �۵�
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
