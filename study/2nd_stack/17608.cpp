#include<iostream>
#include<stack>
using namespace std;
stack<int> stick;
int main(){
  int size,input,output=1,compare;
  cin>>size;
  for(int a=0;a<size;a++){
    cin>>input;
    stick.push(input);
  }
  compare = stick.top();
  stick.pop();
  for(int a=1;a<size;a++){
    if(stick.top()>compare){
      compare = stick.top();
      output++;
    }
    stick.pop();
  }
  cout<<output;
}
