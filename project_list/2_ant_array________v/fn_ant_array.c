#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int gogo(int,int);
int main(){
  printf("~~ant array~~\n");
  while(1){
    printf("������ ù �ڸ��� �� ���� ���ڸ��� �����ּ���\n");
    int fn; // first number
    scanf("%d",&fn);
    while(fn > 9 || fn < 1){
      printf("�߸��� �亯�Դϴ�. �ٽ� �Է��� �ֽñ� �ٶ��ϴ�\n");
      scanf("%d",&fn);
    }
    printf("�� ���� ������ ����ұ��?(�ִ� 15������)\n");
    int lastarray;
    scanf("%d",&lastarray);
    while(lastarray > 15 || lastarray < 1){
      printf("�߸��� �亯�Դϴ�. �ٽ� �Է��� �ֽñ� �ٶ��ϴ�\n");
      scanf("%d",&lastarray);
    }
    gogo(fn,lastarray);
  }
}
int gogo(int fn,int lastarray){
  printf("-------------------------\n");
  int arr[100] = {0};
  arr[0]=fn;
  printf("%d\t(1��)\n",arr[0]);
  for(int a=1;a<lastarray;a++){
    int read = 0;
    while(arr[read]!=0){  //�� ���� ��ȸ
      int run;    run = read;  //��ȸ �ʱ�->run=read=0 //��ȸ �߱� ->run�� �о���� �������� �ʱ�ȭ��
      int count=1;
      while(arr[run]==arr[run+1]){  //1.������ �о��
        count++;
        run++;
      }     //�ٸ� ���� ������ ������ ���� ���ڰ� ��ġ�� ���� run ���尪�̴�
      run++;  //���� �ٸ��� ù��°�� ��ġ�Ѵ�
      switch (count) {         //2.���� ����
        case 1:
        for(int a=100;a>run;a--){
          arr[a]=arr[a-1];
        }
        break;
        case 3:
        for(run;run<100;run++){
          arr[run-1]=arr[run];
        }
        break;
      }
      arr[read+1] = count;  //3.count �� ����ֱ�
      read+=2;
    }                               //printf("%d,%d\n",fn,lastarray); <-Ȯ�ο�
    int write=0;
    while(arr[write]!=0){
      printf("%d",arr[write]);
      write++;
    }
    printf("\t(%d��)",write);
    printf("\n");
  }
}
