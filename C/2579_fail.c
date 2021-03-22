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




/*�� �տ��� ���� �͵� �����غ� �� ����
�ѹ� �ǳʶٰ� ���� �ι� �ǳʶٰ� ���� ����ϱ�
������ ������ ���� ���� �͸� ����ش�
������ ������ ���� ���� �ͺ��� Ŀ���� �ٷ� ��
����ܿ��� 2��� ���� �� ����
����ܱ��� 3��� �������� �ٷ� 101 ����
����ܱ��� 4��� �������� �ٷ� 0101 ����
�� �� ����� ������ ��� x
arr�� ������ ����� arr[in-1]�� ����

10->������ 1
11->������ 0
01->01,101 or 01,01





*/
