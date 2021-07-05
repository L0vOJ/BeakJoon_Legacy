#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> here;
  int n,k,os=0;
  int output[5001];
  cin>>n>>k;
  for(int a=1;a<=n;a++){
    here.push(a);
  }
  while(here.size()){
    for(int a=1;a<k;a++){
      here.push(here.front());
      here.pop();
    }
    output[os++] = here.front();
    here.pop();
  }
  cout<<"<";
  for(int a=0;a<os-1;a++){
    cout<<output[a]<<", ";
  }
  cout<<output[os-1]<<">";
}
