#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int> s;
  int arr[100001];
  char output[300001];
  int a,n,os=0,hold=0,stop=0;
  cin>>n;
  for(a=0;a<n;a++){
    cin>>arr[a];
  }
  for(a=0;a<n;){
    if(!os||arr[a]>s.top()){
      s.push(os-hold+1);
      output[os]='+';
      os++;
    }
    else if(arr[a]==s.top()){
      s.pop();
      output[os]='-';
      os++;
      hold++;
      a++;
    }
    else{
      stop++;
      break;
    }
  }
  if(stop){
    cout<<"NO";
    return 0;
  }
  for(a=0;a<os;a++){
    cout<<output[a]<<endl;
  }
} //아직 해 없을때 작동 안함
