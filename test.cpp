#include<iostream>
#include<string>
using namespace std;
int main(){
  int a=-1; //-1은 a에 걸린다 !a에 걸리는 건 무조건 0
  if(a){
    cout<<"a"<<endl;
  }
  if(!a){
    cout<<"!a";
  }
}
