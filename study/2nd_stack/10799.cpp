#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> stick;
int main(){
  string input;
  int output=0;
  cin>>input;
  for(int go=0;go<input.size(); go++){
    if(input.at(go) == '('){
      while(stick.size() > 0 && stick.top() == ')'){
        stick.pop();
      }
      stick.push(input.at(go));
    }
    else{
      if(stick.top() == '('){
        stick.pop();
        output += stick.size();
        stick.push(')');
      }
      else if(stick.top() == ')'){
        stick.pop();
        stick.pop();
        stick.push(')');
        output++;
      }
    }
  }
  cout<<output;
}
