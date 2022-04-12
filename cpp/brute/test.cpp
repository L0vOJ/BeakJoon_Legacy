#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int i=0;
	for(int a=0;a<5;a++){
		i++;
		i=i<<1;
		cout<<i<<",";
	}
}