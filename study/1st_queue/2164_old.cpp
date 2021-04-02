#include<iostream>
using namespace std;
typedef struct{
  int* arr;
  int first;
  int last;
}queue;
int main(){
  queue deck;
  deck.arr = (int*)calloc(1000001,sizeof(int));     //50만의 두배
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
    deck.first++;                                   //앞의 한 장을 버린다
    if(deck.first==deck.last)break;                 //한장밖에 안남으면 끝낸다
    deck.arr[deck.last+1] = deck.arr[deck.first];   //가장 앞 장을 맨 뒤로 보낸다
    deck.first++;                                   //앞의 한 장을 버린다
    deck.last++;                                    //뒤로 한 장이 보내졌으니 자리를 만든다
    if(deck.first==deck.last)break;                 //한장 남았는지 판별
  }
  cout << deck.arr[deck.first]+1;                   //마지막 남은 한 장을 출력한다//배열 넘버대로 0부터 쌓았으니깐 +1해서 출력
}

//first in first out
//pop은 가장 위에 있는
