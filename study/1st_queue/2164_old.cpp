#include<iostream>
using namespace std;
typedef struct{
  int* arr;
  int first;
  int last;
}queue;
int main(){
  queue deck;
  deck.arr = (int*)calloc(1000001,sizeof(int));     //50���� �ι�
  int n;
  cin >> n;
  deck.first=0;
  deck.last=n-1;
  if(n==1){
    cout << 1;
    return 0;
  }
  for(int a=0;a<n;a++){
    deck.arr[a] = a;
  }
  while(1){
    deck.first++;                                   //���� �� ���� ������
    if(deck.first==deck.last)break;                 //����ۿ� �ȳ����� ������
    deck.arr[deck.last+1] = deck.arr[deck.first];   //���� �� ���� �� �ڷ� ������
    deck.first++;                                   //���� �� ���� ������
    deck.last++;                                    //�ڷ� �� ���� ���������� �ڸ��� �����
    if(deck.first==deck.last)break;                 //���� ���Ҵ��� �Ǻ�
  }
  cout << deck.arr[deck.first]+1;                   //������ ���� �� ���� ����Ѵ�//�迭 �ѹ���� 0���� �׾����ϱ� +1�ؼ� ���
}

//first in first out
//pop�� ���� ���� �ִ�
