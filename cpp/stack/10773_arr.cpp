#include<iostream>
using namespace std;
int main(){
  int arr[100001] = {0,};
  int n,limit=0,input;
  int output=0;
  cin>>n;
  while(n--){
    cin>>input;
    if(!input&&limit){  //input�� �ݵ�� 0�̿����ϰ�, limit�� 0�� �ƴϾ���Ѵ�
      limit--;
    }
    else if(input){   //0���� �޴´ٸ� �� �۾��� ������ �� ����
      arr[limit] = input;
      limit++;
    }
  }//���������� limit�� ������ŭ ������ ����[1,2,3]�̸� limit�� 3
  while(limit){
    output += arr[limit-1];
    limit--;
  }
  cout << output;
}
