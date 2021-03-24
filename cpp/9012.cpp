#include <iostream>
#include <string>
using namespace std;
int main(){
  int* arr;
  int n,a,b,stack=0;
  string input;
  cin>>n;
  arr = (int*)malloc(n*sizeof(int));
  for(a=0;a<n;a++){
    arr[a]=0;
    cin>>input;
    for(b=0;b<input.size();b++){
      if(arr[a]<0){
        arr[a]=100000;
        continue;
      }
      if(input[b]=='('){
        arr[a]++;
      }
      else if(input[b]==')'){
        arr[a]--;
      }
    }
    if(input[b-1]=='('){
      arr[a]=9000000;
    }
  }
  for(a=0;a<n;a++){
    if(arr[a]){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
    }
  }
}
