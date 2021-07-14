#include<iostream>
#include<algorithm>
using namespace std;
bool desc(int a, int b){
  return a > b;
}

int main(){
  int arr[2][51];
  int n,output=0;
  cin>>n;
  for(int z=0;z<n;z++){
    scanf("%d",&arr[0][z]);
  }
  for(int z=0;z<n;z++){
    scanf("%d",&arr[1][z]);
  }
  sort(arr[0],arr[0]+n);
  sort(arr[1],arr[1]+n,desc);
  for(int z=0;z<n;z++){
    output+=arr[0][z] * arr[1][z];
  }
  cout<<output;
}
