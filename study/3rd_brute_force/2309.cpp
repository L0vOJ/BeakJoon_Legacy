#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int input[9];
  int buffer=0;
  for(int a=0;a<9;a++){
    cin>>input[a];
    buffer +=input[a];
  }
  for(int b=1;b<9;b++){
    for(int a=0;a<b;a++){
      if(buffer - input[a]-input[b] ==100){
        input[a]=0;
        input[b]=0;
        sort(input,input+9);
        for(int c=2;c<9;c++){
          cout<<input[c]<<endl;
        }
        return 0;
      }
    }
  }
}
