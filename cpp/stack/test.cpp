#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> line;
//  line.push(5);
  while(line.size()){
    cout<<line.size()<<","<<line.front()<<endl;
    line.pop();
  }
}
