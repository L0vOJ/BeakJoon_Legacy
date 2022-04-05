#include <array>
#include<iostream>
using namespace std;
typedef array<int,101> myarr;
int main(){
	myarr arr = {};
	for (auto &element : arr) 
		cout << element;
	cout<<"\n";
	arr.fill(1);
	for (auto &element : arr) 
		cout << element;
}