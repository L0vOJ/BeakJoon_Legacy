#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
  stack<int> here;
  queue<int> line;
  queue<char> output;
  int n,ncopy,upper=1;
  int input;
  cin>>n;
  ncopy=n;
  while(ncopy--){
    cin>>input;
    line.push(input);
  }
  while(!line.empty()){
    if(line.front()>=upper){
      here.push(upper++);
      output.push('+');
    }
    else if(line.front()==here.top()){
      here.pop();
      line.pop();
      output.push('-');
    }
    else{
      cout<<"NO";
      return 0;
    }
  }
  while(!output.empty()){
    printf("%c\n",output.front());
    output.pop();
  }
}
