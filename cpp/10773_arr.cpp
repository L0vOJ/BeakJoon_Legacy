#include<iostream>
using namespace std;
int main(){
  int arr[100001] = {0,};
  int n,limit=0,input;
  int output=0;
  cin>>n;
  while(n--){
    cin>>input;
    if(!input&&limit){  //input은 반드시 0이여야하고, limit은 0이 아니어야한다
      limit--;
    }
    else if(input){   //0값을 받는다면 이 작업은 시항할 수 없음
      arr[limit] = input;
      limit++;
    }
  }//최종적으로 limit의 개수만큼 가지고 있음[1,2,3]이면 limit은 3
  while(limit){
    output += arr[limit-1];
    limit--;
  }
  cout << output;
}
