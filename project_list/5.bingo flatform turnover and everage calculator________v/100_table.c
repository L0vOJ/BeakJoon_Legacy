//�����忬���忬���忬���忬���忬���忬����
#include<stdio.h>
#include<stdlib.h>  //rand, srand ����� ���̺귯��
#include<time.h>    //���� �ð�(��)�ҷ����� ���
#include<windows.h> //  �ܼ� ���� ����� ���--system("cls") ���� ���̺귯��
//��ǥ: <1>�� ������ ������ Ȯ���� ����Ѵ�.
//2.
int main(){
  srand(time(0));
  int room[10][10]={{0}};
  int a,b;
  int count=0;
  int tap=0;

  while(1){
    a=(rand()%10);
    b=(rand()%10);
    room[a][b]=1;
    tap++;
    printf("  1 2 3 4 5 6 7 8 9 10\n1 ");
    for(int x=0;x<10;x++){
      for(int y=0;y<10;y++){
        printf("%d ",room[x][y]);
        if(room[x][y]==1){
          count++;
        }
      }
      printf("\n%d ",x+2);
      if(x == 8){
        printf("\r0 ");
      }
      else if(x==9){
        printf("\r");
      }
    }
    printf("������� %d��\n",tap);
    printf("1�� ������ %d��\n",count);
    /*printf("�ٽ� �����ðڽ��ϱ�?: 1. ��/2. ��/default. ��");
    int zz,dd;
    scanf("%d %d",&zz,&dd);*/

    if(count >= 90){
      printf("����!\n");
      printf("�� ���� Ƚ�� : %d\n",tap);
      break;
      return 0;
    }
    count = 0;
    system("cls");
  }
}
