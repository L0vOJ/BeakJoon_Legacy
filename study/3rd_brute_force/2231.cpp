#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int n,output=0;
  cin>>n;
  for(int a=n-100*(int)log10((double)n);a<n;a++){   //������ ���������� Ȯ��
    int buffer=a;                 //���簪 �߰�
    for(int b=1;b<=n;b*=10){
      buffer += (a%(10*b))/b;     //�� �ڸ����� ���Ͽ� buffer�� ���Ѵ�
    }
    if(buffer == n){              //���� ���� ���� ���� ���� ��ġ�ϴ°�
      cout<<a;                    //ã����
      return 0;
    }
  }
  cout<<"0";
}
