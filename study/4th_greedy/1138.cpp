#include <iostream>
#include <queue>
using namespace std;
int main(){
  int arr[11] = {0,};
  int n,input,pos,go;
  cin>>n;
  for(int z=0;z<n;z++){
    cin>>input;
    go=0;
    while(input >= 0){
      if(arr[go++]==0){
        input--;
      }
    }
    arr[--go] = z+1;
  }
  go=0;
  while(n--){
    cout<<arr[go++]<<" ";
  }
}
