#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
  stack <int> bal;
  int output[500001];
  string input;
  int stop,a;
  for(a=0;;a++){
    stop=0;
    while( !bal.empty() ) bal.pop();
    getline(cin,input);
    if(input[0]=='.'&&input.size()==1){
      for(int c=0;c<a;c++){
        if(output[c]){
          cout<<"no"<<endl;
        }
        else{
          cout<<"yes"<<endl;
        }
      }
      return 0;
    }
    for(int b=0;;b++){
      switch (input[b]) {
        case '.':
          stop++;
        break;
        case '(':
          bal.push('(');
        break;
        case ')':
          if(bal.empty()||bal.top()=='['){
            output[a]=1;
          }
          else{
            bal.pop();
          }
        break;
        case '[':
          bal.push('[');
        break;
        case ']':
          if(bal.empty()||bal.top()=='('){
            output[a]=1;
          }
          else{
            bal.pop();
          }
        break;
      }
      if(output[a]){
        break;
      }
      if(stop){
        if(!bal.empty()){
          output[a]=1;
        }
        break;
      }
    }
  }
}
