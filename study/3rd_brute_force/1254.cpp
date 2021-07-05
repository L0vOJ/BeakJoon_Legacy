#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int run(int a);
string input;
int back;
int stack=0;
int buffer=0;
int main(){
  cin>>input;
  if(input.size()<2){
    cout<<input.size();
    return 0;
  }
  else{
    int start = input.size()/2;
    for(int a=start;a<input.size();a++){
      if(run(a)>0){
        cout<< 2 * (a+1) -1 -back;
        return 0;
      }
    }
  }
}

int run(int a){
  if(input.at(a) == input.at(a-1)){
    back=2;
  }
  else{
    back=1;
  }
  int pass=1;
  int b;
  while(1+--back){
    for(b=1;a+b-back <input.size() && a-b >=0;b++){
      //cout<<a-b<<","<<input.at(a-b)<<"//"<<a+b-back<<","<<input.at(a+b-back)<<endl;
      if(input.at(a-b) != input.at(a+b-back)){
        if(back==1){
          pass=0;
          break;
        }
        if(back==0){
          return 0;
        }
      }
    }
    if(pass==1){
      if(back==1 && a-b == -1){
        if(a+b == input.size()+1){
          return a;
        }
        continue;
      }
      return a;
    }
  }
  back=0;
  return a;
}

/*
int run(int a){
  if(input.at(a) == input.at(a-1)){
    int exit=1;
    for(int b=1;a+b<input.size();b++){
      if(input.at(a-b) != input.at(a+b-1)){
        exit=0;
        break;
      }
    }
    if(exit){
      back=1;
      return a;
    }
  }
  for(int b=1;a+b<input.size();b++){
    if(input.at(a-b) != input.at(a+b)){
      return 0;
    }
  }
  back=0;
  return a;
}
*/
