#include<iostream>
using namespace std;
int main(){
  int table[5001];
  int output[5001];
  int n,step;     //�Է� ���
  int turn=0,left;  //turn = �� �� ���������� ī��Ʈ left = �� �� ���Ҵ��� ī��Ʈ
  int move = 0;   //move = ���� ��� Ȯ���ϴ���
  cin>>n>>step;
  for(int z=0;z<n;z++){
    table[z]=1;
  }
  table[n]=-1;
  left=n;
  while(1){
    if(table[move]){        //0 ����
      if(table[move]==-1){  //-1�϶�, �� �� ����
        move=0;
        continue;           //ó������ ����
      }
      else{                 //1�϶�
        turn++;             //detect
        if(step == turn){
          output[n-left] = move+1;   //�ش� ��� ���, ����, turn �ʱ�ȭ
          table[move] = 0;
          turn = 0;
          if(!--left){             //�ƹ��� �ȳ�����
            break;                 //��
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
