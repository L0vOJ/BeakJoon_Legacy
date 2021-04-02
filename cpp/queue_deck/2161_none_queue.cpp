#include<iostream>
using namespace std;
int main(){
  int table[5001];
  int output[5001];
  int n,step;     //입력 대상
  int turn=0,left;  //turn = 몇 번 움직였는지 카운트 left = 몇 명 남았는지 카운트
  int move = 0;   //move = 현재 어디를 확인하는지
  cin>>n>>step;
  for(int z=0;z<n;z++){
    table[z]=1;
  }
  table[n]=-1;
  left=n;
  while(1){
    if(table[move]){        //0 제외
      if(table[move]==-1){  //-1일때, 즉 끝 도달
        move=0;
        continue;           //처음부터 시작
      }
      else{                 //1일때
        turn++;             //detect
        if(step == turn){
          output[n-left] = move+1;   //해당 대상 기록, 제거, turn 초기화
          table[move] = 0;
          turn = 0;
          if(!--left){             //아무도 안남으면
            break;                 //끝
          }
        }
      }
    }
    move++;
  }
  cout<<"<";
  for(int z=0;z<n-1;z++){
    cout<<output[z]<<", ";
  }
  cout<<output[n-1]<<">";
}
