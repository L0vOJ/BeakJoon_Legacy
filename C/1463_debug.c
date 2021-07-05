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
    printf("비교중 현 goal = %d\n",*goal);
    return 0;
  }
  if(current % 3 == 0){
    printf("3슬%d\n",current);
    tree(current/3,try+1,goal);
  }
  if(current % 2 == 0){
    printf("2슬%d\n",current);
    tree(current/2,try+1,goal);
  }
  printf("빼기%d\n",current);
  tree(current-1,try+1,goal);
  return 0;
}


//1.연산을 시행할때마다 바뀌는 값과 몇 번 바뀌었는지를 기록한다
//2.모든 가짓수를 재귀식을 통해 모두 훓게 만든 뒤 원하는 최고값만 살아남게 만든다
//완전 작성 뒤 이 주석을 지울 것
//돌고 도는 값을 struct -> pointer로서 들게 만들지 말고
//value 값을 가지게 만들어 동적인 움직임을 보이도록 만들어야 한다

//**try가 goal을 넘어서면 바로 컷
