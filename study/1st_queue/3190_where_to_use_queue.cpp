#include<iostream>
using namespace std;
int main(){
  int feild[103][103];
  int move[101][2];
  int n,k,h;
  int a1,a2;
  int ip_num;
  char ip_ch;
  int sense=0,step=0,yummy=1;
  cin>>n>>k;
  for(int a=0;a<k;a++){
    cin>>a1>>a2;
    feild[a1][a2] = -1;
  }
  cin>>h;
  for(int a=0;a<h;a++){
    cin>>ip_num>>ip_ch;
    move[a][0]=ip_num;
    if(ip_ch=='D'){
      move[a][1]=1;
    }
    else{
      move[a][1]=-1;
    }
  }
  a1=1;
  a2=1;
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
    else{
      yummy++;
    }
    if(move[step][0]==t){      //���� �ٲ� �ð� �Ǻ�
      sense+=move[step++][1];
      if(sense<0){             //0���� -1�� ������ �� %= ������ +�� ������ش� ********** �̷��� �߿��� ����� ������
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
}
