#include<iostream>
#include<string>
using namespace std;
int main(){
  int* arr;
  arr = (int*)malloc(100*sizeof(int));
  for(int a=0;a<10;a++){
    arr[a]=1;
  }
  for(int a=0;a<arr.size();a++){
    cout<<arr[a]<<endl;
  }
}
