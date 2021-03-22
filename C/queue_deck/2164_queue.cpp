#include<iostream>
using namespace std;
typedef struct{
  int* arr;
  int first;
  int last;
}queue;
int main(){
  queue deck;
  deck.arr = (int*)calloc(1000001,sizeof(int));
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
    deck.first++;
    if(deck.first==deck.last)break;
    deck.arr[deck.last+1] = deck.arr[deck.first];
    deck.first++;
    deck.last++;
    if(deck.first==deck.last)break;
  }
  cout << deck.arr[deck.first]+1;
}


/*
for(int a=0;a<n;a++){       //üũ
  cout << deck.arr[a] << endl;
}
*/
/*
for(int a=deck.first;a<=deck.last;a++){       //üũ
  cout << deck.arr[a] << endl;
}
cout << "-----------" << endl;
*/
