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
  //���� ���°� 1�϶����� ���ѹݺ�
  while(v.size()!=1){
    total = v.size();
    for(int a=0;a<v.size();a++){
      v.erase(v.begin()+a);
    }
    if(total%2){ //���� ��ҵ��� ������ Ȧ���� �� �տ� �ִ� ���� �� �ڷ� �Ѱܾ� �Ѵ�  //���� ������̾���� ������ ������̸� �ȵ�
      buffer = v.front();
      for(int a=0;a<v.size()-1;a++){
        v.at(a) = v.at(a+1);
      }
      v.back() = buffer;
    }
  }
  cout << v.front()+1;
}
//���� �����ϰ� ���� ����
//�ڷᱸ���� ���� �� ���� ���� ���� ������
//������ ���� 1�� ���ϸ� �ȴ�

/*üũ�� �Լ�

*/
//    cout << "--------" << endl; //��ġ�� �Լ�
