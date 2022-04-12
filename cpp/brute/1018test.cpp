#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main(){
	int in=0;
	for(int a=0;a<4;a++){
		in++;
		in=in<<2;
	}
	in=in>>2;
	cout<<in<<","<<bitset<8>(in);
}