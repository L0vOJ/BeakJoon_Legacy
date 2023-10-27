#include <iostream>
#include<string>

using namespace std;

class student {
private:
	string name;
	int age;
	string hobby;
public:
	student();
	student(string iname,int iage,string ihobby);
	void ShowInfo();
	void SetInfo(string _name, int _age, string _hobby);
	void Study();
	void Sleep();
};

student::student(){
	name = 47;
	age=47;
	hobby="sweeper";
}

student::student(string iname,int iage,string ihobby):name(iname),age(iage),hobby(ihobby){
	cout<<"overloading"<<endl;
};


void student::ShowInfo()
{
	cout << "이름: " << name << ", 나이: " << age << ", 취미: " << hobby << endl;
}

void student::SetInfo(string _name, int _age, string _hobby)
{
	name = _name;
	age = _age;
	hobby = _hobby;
}

void student::Study()
{
	cout << "공부!" << endl;
}

void student::Sleep()
{
	cout << "잠!" << endl;
}

int main()
{
	student stu;

	stu.SetInfo("charge", 16, "hello");
	stu.ShowInfo();

	student another("mike",22,"overload");
	another.ShowInfo();

	student blank;
	blank.ShowInfo();
	/*
	while(true) {
		stu.Study();
		stu.Sleep();
	}
	*/
	return 0;
}