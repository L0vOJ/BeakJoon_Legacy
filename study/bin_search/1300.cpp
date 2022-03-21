#include <iostream>
using namespace std;
int arA[100][100];
int arB[10000];

int main(){
  int input[2];
  cin>>input[0]>>input[1];
  for(int a = 0;a<input[0]+1;a++){
    for(int b=0;b<input[0]+1;b++){
      arA[a][b] = a*b;
      cout<<arA[a][b]<<'\t';
    }
    cout<<'\n';
  }
}
