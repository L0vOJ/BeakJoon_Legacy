#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> stick;
string letter;
int main(){
  int size,output=0;
  cin>>size;
  while(size--){
    cin>>letter;
    for(int a=0;a<letter.size();a++){
      if(stick.size() == 0 || stick.top() != letter.at(a)){
        stick.push(letter.at(a));
      }
      else{
        stick.pop();
      }
    }
    if(!stick.empty()){
      while(!stick.empty()) stick.pop();
    }
    else{
      output++;
    }
  }
  cout<<output;
}
//������ ���� ���ڰ� ���� ���ڰ� �ƴϸ� �״´�
//������ ������ ���� ���ڱ��� ������ �����
//��� ������ �� �ƹ��͵� ������ ���� �ƴϸ� ������
