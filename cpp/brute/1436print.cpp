#include <iostream>
#include <fstream>      //File I/O header file
using namespace std;
ofstream fout("1436_answer.txt"); 
int main(){
	int paste,check,six,stack=0;
	for(int a=0;stack<10000;a++){
		six = a;
		check=0;
		while(true){
			if(six%10==6){
				if(++check>2){
					fout<<a<<",";
					stack++;
					break;
				}
				if(six<10)break;
			}
			else{
				if(six<10)break;
				check=0;
			}
			six/=10;
		}
	}
	fout.close();
}