#include <iostream>
using namespace std;
int decc[2][10] = {{0,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0}};
int main(){
  int input;
  int output=0;
  cin>>input;
  while(input--){
    for(int a=0;a<10;a++){
      decc[1][a] = decc[0][a];
    }
    decc[0][0] = decc[1][1];
    decc[0][9] = decc[1][8];
    for(int a=1;a<9;a++){
      decc[0][a] = (decc[1][a-1]+decc[1][a+1])%1000000000;
    }
  }
  for(int a=0;a<10;a++){
    output = (output + decc[1][a])%1000000000;
  }
  cout<<output;
}
