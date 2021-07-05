#include<iostream>
using namespace std;
int main(){
  int input;
  int output = 99;
  int t=0;
  cin>>input;
  if(input < 100){
    cout<<input;
  }
  else if(input<1000){
    output += ((input/100)-1)*5;
    for(int a = input - input % 100; a <= input;a++){
      int buffer[3];
      for(int b=1;b<=a;b*=10){
        buffer[t++] = (a%(10*b))/b;     //각 자릿수를 구하여 buffer에 더한다
      }
      t=0;
      if(buffer[0] + buffer[2] == 2* buffer[1]){
        output++;
      }
    }
    cout<<output;
  }
  else{
    cout<<144;
  }
}
