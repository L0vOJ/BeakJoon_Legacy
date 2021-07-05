#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
stack<int> stick;
stack<int> buffer;
queue<int> line;
string instr;
string outstr;

int main(){
  int size,del,inbuf,c;
  cin>>size>>del;
  scanf("%*c", c);
  while(size--){
    line.push(getc(stdin)-48);
  }
  while(!line.empty()){
    cout<<line.front()<<",";
    line.pop();
  }
}






/*
int main(){
  int size,del,input,output=0;
  cin>>size>>del;
  cin>>instr;
  for(int a=0;a<instr.size();a++){
    line.push(instr.at(a)-48);
  }
  cout<<outstr;
}

/*
거꾸로, 다 지우고 남은 숫자가 어떤 숫자인지를 추측하자
가장 높은 자릿수의 숫자가 가장 큰 숫자가 되어야한다
그 다음으로 높은 자릿수의 숫자 또한 최대한 커야 한다
순서의 중요도를 잘 따지는 것이 매우 중요하다

100개의 자릿수 중에 10개를 지워야 한다
ㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌ
먼저, 앞 11자리 중에서 9 내지는 가장 큰 수를 찾는다
9가 있다면, 9 앞에 있는 것들을 전부 지운다
8이 가장 크다면 8 앞에 있는 것들을 전부 지운다
ㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌ

가장 큰 것이라고 여겨지는 것이 2개 이상 있다면 앞에 있는 것을 선택한다
(compare를 통해 쌓고 있었다면 >로 처리할 테니 걱정할 이유는 없다)
만약 지우고 더 지울 수 있다면, 남긴 첫번째 숫자 뒤로 위와 같은 과정을 지울 수 있는 만큼 반복한다
모든 자리를 검사하기 전에 지워야 하는 숫자의 갯수가 동나면 끝

만약 모든 자리를 검사했는데도 지워야 하는 숫자의 갯수가 남아있다면
100개 중에 99개를 지워야 한다면
남을리가 없나
999999999999999999991
88888888888888878888
987654321
ㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌ
한 번 돌았을 때 아무것도 지워지지 않았다면 뒤에서부터 지운다
아니면 앞으로 순서대로 출력한다
ㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌㅌ
ouptut,buffer,input <<--
마음대로 다루려면 그냥 수열 쓰는게 맞을지도

1213121211321321321321124218
단 두번 지울 수 있다면
스택이 맞구만
근데 어떻게 반환하지
두번 거쳐 가는게 답인가


*/
