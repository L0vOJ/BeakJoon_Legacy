#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<pair<int,int>> snake;
  snake.push(make_pair(1,1));
  int apple[101][2];
  int rotate[101][2];
  int n,k,l;
  int a1,a2;
  int in_num;char in_ch;
  cin>>n>>k;
  for(int a=0;a<k;a++){
    cin>>a1>>a2;
    apple[a][0] = a1;
    apple[a][1] = a2;
  }
  cin>>l;
  for(int a=0;a<l;a++){
    cin>>in_num>>in_ch;
    rotate[a][0] = in_num;
    if(in_ch=='D'){
      rotate[a][1] = 1;
    }
    else{
      rotate[a][1] = -1
    }
  }
  for(int t=0;;t++){
    if()
  }

}

for(int t=0;;t++){
  //cout<<a1<<","<<a2<<","<<move[step][0]<<","<<move[step][1]<<","<<sense<<endl;
  if(!a1||!a2||a1==n+1||a2==n+1||feild[a1][a2]>0){     //��迡 ��ų� ��ü�� ������
    cout<<t;
    return 0;
  }
  else if(feild[a1][a2]!=-1){                               //�ȴ������
    for(int a=1;a<=n;a++){
      for(int b=1;b<=n;b++){
        if(feild[a][b]>0){
          feild[a][b]--;
        }
      }
    }
  }
  else yummy++;
  if(move[step][0]==t){      //���� �ٲ� �ð� �Ǻ�
    sense+=move[step++][1];
    if(sense<0){             //���� ������ ������ �� %= ������ �˾Ƽ� +�� ������ش� ***** �ݵ�� ������� *****
      sense+=4;
    }
    sense%=4;
  }
  switch (sense) {           //������ �ð�
    case 0:
      feild[a1][a2++]=yummy;
    break;
    case 1:
      feild[a1++][a2]=yummy;
    break;
    case 2:
      feild[a1][a2--]=yummy;
    break;
    case 3:
      feild[a1--][a2]=yummy;
    break;
  }
}
