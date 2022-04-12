#include<iostream>
#include<math.h>
#include <fstream>      //File I/O header file

using namespace std;
ofstream fout("1038_answer.txt"); 
int checkout(long long test);
int main(){
	int stack=0;
	for(long long a=0;a<9876543211;a++){
		if(checkout(a)) fout<<a<<',';
	}
	fout.close();
}

int checkout(long long test){
	if(test%10<test/10%10||test<10){
		if(test>9){
			if(checkout(test/10)) return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}