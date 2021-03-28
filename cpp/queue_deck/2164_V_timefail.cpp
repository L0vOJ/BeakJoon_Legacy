#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
  int n,seize,buffer,total;
  cin >>n;
  for(int a=0;a<n;a++){ //0 1 2 3 4 5 6 7 8 9
    v.push_back(a);
  }
  //이하 남는게 1일때까지 무한반복
  while(v.size()!=1){
    total = v.size();
    for(int a=0;a<v.size();a++){
      v.erase(v.begin()+a);
    }
    if(total%2){ //남은 요소들의 갯수가 홀수면 맨 앞에 있는 놈을 맨 뒤로 넘겨야 한다  //이전 사이즈값이어야함 지금의 사이즈값이면 안됨
      buffer = v.front();
      for(int a=0;a<v.size()-1;a++){
        v.at(a) = v.at(a+1);
      }
      v.back() = buffer;
    }
  }
  cout << v.front()+1;
}
//괜히 복잡하게 하지 말고
//자료구조랑 내부 값 전부 같게 만든 다음에
//제출할 값에 1만 더하면 된다

/*체크용 함수

*/
//    cout << "--------" << endl; //줄치기 함수
