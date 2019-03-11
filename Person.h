#pragma once
#include<string>
using namespace std;
class Person
{
public:
	Person();
	Person(string Mname,int age);
//	Person& operator = (Person& people);
	void print();
	virtual ~Person();
private:
	string name;
	int age;
};

