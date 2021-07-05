#include<iostream>
using namespace std;
/*
int main(){
  int a,b,c,d;
  cin >> a;
  c = a>10 ? 1 : 0 ;
  cin >> b;
  d = b>10 ? 2 : 0;
  cout<<c+d;
}
*/
int main(){
  int a,b,c=0,d=0;
  cin >> a;
  c ^= a>10;
  c*=2;
  cin >> b;
  c ^= b>10;
  cout<<c;
}
