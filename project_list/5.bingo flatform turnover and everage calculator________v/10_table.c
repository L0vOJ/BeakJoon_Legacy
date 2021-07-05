//연습장연습장연습장연습장연습장연습장연습장
#include<stdio.h>
#include<stdlib.h>  //rand, srand 내장된 라이브러리
#include<time.h>    //지금 시간(초)불러오는 기능
#include<windows.h> //  콘솔 전부 지우는 기능--system("cls") 내포 라이브러리
//목표: <1>이 나오는 지점을 확인해 출력한다.
//2.
int main(){
  srand(time(0));
  int room[10]={0};
  int a;
  int ma[50]={0};  //ma는 열 정보, mb는 행 정보 저장용 필요없음
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
    printf("시행수는 %d번\n",tap);
    printf("1의 개수는 %d개\n",count);
    /*printf("다시 뽑으시겠습니까?: 1. 네/2. 네/default. 네");
    int zz,dd;
    scanf("%d %d",&zz,&dd);*/

    if(count >= 9){
      printf("종료!\n");
      printf("총 시행 횟수 : %d\n",tap);
      break;
      return 0;
    }
    count = 0;
    system("cls");
  }

}
