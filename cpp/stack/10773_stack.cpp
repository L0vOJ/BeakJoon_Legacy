#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack <int> jamin;
  int n,input,output=0;
  cin>>n;
  while(n--){
    cin>>input;
    if(input) jamin.push(input);
    else jamin.pop();
  }
  while(jamin.size()){
    output += jamin.top();
    jamin.pop();
  }
  cout << output;
}
