#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
stack<int> stick;
stack<int> buffer;
queue<int> line;
int main(){
  int size,del,clear;
  cin>>size>>del;
  scanf("%*c", clear);
  while(size--){
    line.push(getc(stdin)-48);
  }
  stick.push(line.front());
  line.pop();
  while(del && !line.empty()){
    if(stick.top()<line.front()){
      stick.pop();
      del--;
      if(stick.empty()){
        stick.push(line.front());
        line.pop();
      }
    }
    else{
      stick.push(line.front());
      line.pop();
    }
  }
  while(del--){
    stick.pop();
  }
  while(!stick.empty()){
    buffer.push(stick.top());
    stick.pop();
  }
  while(!buffer.empty()){
    cout<<buffer.top();
    buffer.pop();
  }
  while(!line.empty()){
    cout<<line.front();
    line.pop();
  }
}
