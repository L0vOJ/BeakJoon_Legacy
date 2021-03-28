#include<stdio.h>
#include<math.h>
#include<windows.h>
/*여기서 좀 더 다듬어야 할 것
1.var_calc의 연선 효율 증가를 위해, 이전 값을 저장 후 gg++ 연산 뒤 val_calc에 그 값을 적용시키는 작업을 추가한다.
2.확률의 총합, 평균, 분산 및 표준편차의 각 함수와, while 함수를 모두 main 함수 밖으로 분리한 후, table 개수와, 충족 조건을 입력 받기 위해
위의 값을 상수로부터 변수로 분리한다.
3.몇번 테스트해보면서, 프로그램이 부담 받지 않도록 입력 변수의 최대값을 설정한다.
*/

double var_calc(int,double);
void back_to_startline();

int main(){
  double allc=1;  //90번의 시행만으로 90번 1 뽑을 확률
                  //평균값 -->컴터의 근사를 이용해 대충 구할 생갹임
  for(double base=2;base<10;base++){
    allc = allc * (base/10);        //색 안칠한 것만 골라 칠할 확률(9번의 시행으로 성공할 확률)
  }
  printf("%.10f=allc\n",allc);
  double e; //평균값(이걸로 구하고자하는 최총값)
  int check;
  while(1){
    printf("평균값을 구하고 싶다면 1번, 확률의 총합을 구하고 싶다면 2번, 분산 및 표준편차를 구하고 싶다면 3번을 입력하세요:");
    scanf("%d",&check);

    if(check==1){
      e=9*allc; //시행 수(변수값) * 최소 시행 성공을 위한 베이스 확률(색 안칠한 것만 골라 칠할 확률)
      for(int gg=0;gg<40;gg++){
        e+=(gg+10)*allc*var_calc(gg+1,1);
        printf("%.10f,%d번째\n",e,gg+10);
      }
      printf("49번 뽑아야 목표를 달성할 확률까지 종합해 구한 평균의 근사값은 %f이다\n",e);
      back_to_startline();
    }
    else if(check == 2){
      e=allc; // 최소 시행 성공을 위한 베이스 확률(색 안칠한 것만 골라 칠할 확률)
      for(int gg=0;gg<40;gg++){
        e+=allc*var_calc(gg+1,1);
        printf("%.10f,%d번째\n",e,gg+1);
      }
      printf("확률만 모두 더한 값:%f 이정도면 꽤나 신뢰성 있다 ㅎㅎ\n",e);
      back_to_startline();
    }
    else if(check == 3){
      e=9*9*allc; //시행 수(변수값) * 최소 시행 성공을 위한 베이스 확률(색 안칠한 것만 골라 칠할 확률)
      for(int gg=0;gg<40;gg++){
        e+=(gg+10)*(gg+10)*allc*var_calc(gg+1,1);
        printf("%.10f,%d번째\n",e,gg+10);
      }
      e -= pow(19.246652,2);
      printf("분산 값:%f\n",e);
      printf("표준 편차값:%f\n",sqrt(e));
      back_to_startline();
    }
    else{
      printf("잘못된 값을 입력하셨습니다. 다시 입력해주세요.\n");
      back_to_startline();
    }
  }
}
double var_calc(int depth,double progress){
  double mid=0;
  double res=0;
  if(depth == 1){
    for(;progress<9;progress++){
      mid += (progress/10);
    }
    return mid;
  }
  else{
    for(;progress<9;progress++){
      res += (progress/10) * var_calc(depth-1,progress);  //깊이 3, 진행 2라면
    }
  }
  return res;
}
void back_to_startline(){
  int check;
  printf("새로 구하고자 한다면 any키를 입력하시오");
  scanf("%d",&check);
  system("cls");
}

/*
목표!--10개의 공에 한번의 시행마다 완전 무작위로 하나의 공을 색칠을 한다.(고른 공이 색칠된 공이라도 일단 칠하고 본다)
이와 같은 과정을 반복할때, 평균 몇번의 시행을 반복해야 9개의 공을 색칠할 수 있을까?

원래는 100개의 공, 90개의 목표로 설정했는데, 이 상태로 돌려보니 속도가 답이 없다
자금 이것도 겨우 간당간당하게 근사값을 얻을 수 있었다

지금 이 문제를 눈으로 확인하고싶다면 같은 파일에 있는 turn_over.c 파일을 실행시켜보라

실행 결과:
49번 뽑아야 목표를 달성할 확률까지 종합해 구한 평균의 근사값은 19.246652이다
확률만 모두 더한 값:0.999203 이정도면 꽤나 신뢰성 있다 ㅎㅎ
분산 값:35.005143
표준 편차값:5.916514

*/
