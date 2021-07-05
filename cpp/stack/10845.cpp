#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
  int n,s_push,first=0,last=0,outs=0;
  int stack[10001];
  int output[10001];
  string input;
  cin>>n;
  while(n--){
    cin>>input;
    switch (input[0]) {
      case 'p':
        if(input[1]=='u'){
          cin>>s_push;
          stack[last] = s_push;
          last++;
        }
        else{ //input[1] = 'o'
          if(last-first){
            output[outs++] = stack[first++];
          }
          else{
            output[outs++] = -1;
          }
        }
      break;
      case 's':
        output[outs++] = last - first;
      break;
      case 'e':
        output[outs++] = last - first ? 0 : 1;
      break;
      case 'f':
        if(last - first){
          output[outs++] = stack[first];
        }
        else{
          output[outs++] = -1;
        }
      break;
      case 'b':
        if(last - first){
          output[outs++] = stack[last-1];
        }
        else{
          output[outs++] = -1;
        }
      break;
    }
  }
  for(int z=0;z<outs;z++){
    cout << output[z] << endl;
  }
}
