//연습장연습장연습장연습장연습장연습장연습장
#include<stdio.h>
#include<stdlib.h>  //rand, srand 내장된 라이브러리
#include<time.h>    //지금 시간(초)불러오는 기능
#include<windows.h> //  콘솔 전부 지우는 기능--system("cls") 내포 라이브러리
//목표: <1>이 나오는 지점을 확인해 출력한다.
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
    printf("시행수는 %d번\n",tap);
    printf("1의 개수는 %d개\n",count);
    /*printf("다시 뽑으시겠습니까?: 1. 네/2. 네/default. 네");
    int zz,dd;
    scanf("%d %d",&zz,&dd);*/

    if(count >= 90){
      printf("종료!\n");
      printf("총 시행 횟수 : %d\n",tap);
      break;
      return 0;
    }
    count = 0;
    system("cls");
  }
}
