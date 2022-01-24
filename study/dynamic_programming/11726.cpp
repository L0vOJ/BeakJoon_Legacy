#include <iostream>
using namespace std;
int output[3] = {2,1,0};
int main(){
  int input;
  cin>>input;
  if(input<3){
    cout<<input;
    return 0;
  }
  else{
    input-=2;
    while(input--){
      output[2] = output[1];
      output[1] = output[0];
      output[0] = (output[1] + output[2])%10007;
    }
    cout<<output[0];
    return 0;
  }
}
