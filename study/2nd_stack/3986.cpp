#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> stick;
string letter;
int main(){
  int size,output=0;
  cin>>size;
  while(size--){
    cin>>letter;
    for(int a=0;a<letter.size();a++){
      if(stick.size() == 0 || stick.top() != letter.at(a)){
        stick.push(letter.at(a));
      }
      else{
        stick.pop();
      }
    }
    if(!stick.empty()){
      while(!stick.empty()) stick.pop();
    }
    else{
      output++;
    }
  }
  cout<<output;
}
//직전에 쌓은 글자가 같은 글자가 아니면 쌓는다
//같으면 직전에 쌓은 글자까지 포함해 지운다
//모두 적용한 뒤 아무것도 없으면 좋음 아니면 안좋음
