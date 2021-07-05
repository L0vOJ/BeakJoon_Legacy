#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int n,output=0;
  cin>>n;
  for(int a=n-100*(int)log10((double)n);a<n;a++){   //가능한 최저값부터 확인
    int buffer=a;                 //현재값 추가
    for(int b=1;b<=n;b*=10){
      buffer += (a%(10*b))/b;     //각 자릿수를 구하여 buffer에 더한다
    }
    if(buffer == n){              //전부 더한 값이 원래 값과 일치하는가
      cout<<a;                    //찾았음
      return 0;
    }
  }
  cout<<"0";
}
