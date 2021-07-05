#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int gogo(int,int);
int main(){
  printf("~~ant array~~\n");
  while(1){
    printf("수열의 첫 자리에 들어갈 숫자 한자리를 적어주세요\n");
    int fn; // first number
    scanf("%d",&fn);
    while(fn > 9 || fn < 1){
      printf("잘못된 답변입니다. 다시 입력해 주시기 바랍니다\n");
      scanf("%d",&fn);
    }
    printf("몇 개의 수열을 출력할까요?(최대 15개까지)\n");
    int lastarray;
    scanf("%d",&lastarray);
    while(lastarray > 15 || lastarray < 1){
      printf("잘못된 답변입니다. 다시 입력해 주시기 바랍니다\n");
      scanf("%d",&lastarray);
    }
    gogo(fn,lastarray);
  }
}
int gogo(int fn,int lastarray){
  printf("-------------------------\n");
  int arr[100] = {0};
  arr[0]=fn;
  printf("%d\t(1개)\n",arr[0]);
  for(int a=1;a<lastarray;a++){
    int read = 0;
    while(arr[read]!=0){  //한 바퀴 순회
      int run;    run = read;  //순회 초기->run=read=0 //순회 중기 ->run이 읽어나가는 시작점과 초기화됨
      int count=1;
      while(arr[run]==arr[run+1]){  //1.같은값 읽어나감
        count++;
        run++;
      }     //다른 값이 나오면 마지막 같은 숫자가 위치한 곳이 run 저장값이다
      run++;  //이제 다른값 첫번째에 위치한다
      switch (count) {         //2.라인 정렬
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
      arr[read+1] = count;  //3.count 값 집어넣기
      read+=2;
    }                               //printf("%d,%d\n",fn,lastarray); <-확인용
    int write=0;
    while(arr[write]!=0){
      printf("%d",arr[write]);
      write++;
    }
    printf("\t(%d개)",write);
    printf("\n");
  }
}
