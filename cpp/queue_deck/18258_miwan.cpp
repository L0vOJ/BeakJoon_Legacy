#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
  queue<int> here;
  int n;
  string input;
  cin>>n;
  while(n--){
    cin>>input;
    switch (input[0]) {
      case 'p':
        if(input[1]=='u'){
          cin>>n;
          here.push(n);
        }
        else{
          if(!here.size()){
            cout<<-1<<endl;
          }
          else{
            cout<<here.front()<<endl;
            here.pop();
          }
        }
      break;
      case 's':
        cout<<here.size()<<endl;
      break;
      case 'e':
        cout<<here.empty()<<endl;
      break;
      case 'f':
        if(!here.size()){
          cout<<-1<<endl;
        }
        else{
          cout<<here.front()<<endl;
        }
      break;
      case 'b':
        if(!here.size()){
          cout<<-1<<endl;
        }
        else{
          cout<<here.back()<<endl;
        }
      break;
    }
  }
}
