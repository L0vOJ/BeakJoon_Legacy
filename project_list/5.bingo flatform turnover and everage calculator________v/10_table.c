//�����忬���忬���忬���忬���忬���忬����
#include<stdio.h>
#include<stdlib.h>  //rand, srand ����� ���̺귯��
#include<time.h>    //���� �ð�(��)�ҷ����� ���
#include<windows.h> //  �ܼ� ���� ����� ���--system("cls") ���� ���̺귯��
//��ǥ: <1>�� ������ ������ Ȯ���� ����Ѵ�.
//2.
int main(){
  srand(time(0));
  int room[10]={0};
  int a;
  int ma[50]={0};  //ma�� �� ����, mb�� �� ���� ����� �ʿ����
  int count=0;
  int tap=0;

while(1){
    a=(rand()%10);
    room[a]=1;
    tap++;
    printf("  1 2 3 4 5 6 7 8 9 10\n1 ");
    for(int x=0;x<10;x++){
        printf("%d ",room[x]);
        if(room[x]==1){
          count++;
        }
      }
    printf("������� %d��\n",tap);
    printf("1�� ������ %d��\n",count);
    /*printf("�ٽ� �����ðڽ��ϱ�?: 1. ��/2. ��/default. ��");
    int zz,dd;
    scanf("%d %d",&zz,&dd);*/

    if(count >= 9){
      printf("����!\n");
      printf("�� ���� Ƚ�� : %d\n",tap);
      break;
      return 0;
    }
    count = 0;
    system("cls");
  }

}
