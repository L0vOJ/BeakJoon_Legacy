#include<stdio.h>
int main(){
  int current,try=0;
  int goal[1];
  scanf("%d",&current);
  *goal = current;
  tree(current,try,goal);
  printf("%d",*goal);
  return 0;
}

int tree(int current,int try,int* goal){
  if(try == *goal){
    return 0;
  }
  if(current == 1){
    *goal = (try < *goal) ? try : *goal;
    printf("���� �� goal = %d\n",*goal);
    return 0;
  }
  if(current % 3 == 0){
    printf("3��%d\n",current);
    tree(current/3,try+1,goal);
  }
  if(current % 2 == 0){
    printf("2��%d\n",current);
    tree(current/2,try+1,goal);
  }
  printf("����%d\n",current);
  tree(current-1,try+1,goal);
  return 0;
}


//1.������ �����Ҷ����� �ٲ�� ���� �� �� �ٲ�������� ����Ѵ�
//2.��� �������� ��ͽ��� ���� ��� �f�� ���� �� ���ϴ� �ְ��� ��Ƴ��� �����
//���� �ۼ� �� �� �ּ��� ���� ��
//���� ���� ���� struct -> pointer�μ� ��� ������ ����
//value ���� ������ ����� ������ �������� ���̵��� ������ �Ѵ�

//**try�� goal�� �Ѿ�� �ٷ� ��
