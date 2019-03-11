#include "Person.h"
#include<iostream>
using namespace std;


Person::Person()
{
	cout << "default constructer被调用" << endl;
	name = "未初始化";
	age = 0;
}


Person::~Person()
{
	cout <<"姓名：" <<name<<'\t'<<"年龄"<<age<<'\t'<<"析构函数被调用！" << endl;
}


Person::Person(string Mname, int Mage) :name(Mname), age(Mage)
{
	cout << "传参 constructer 被调用" << endl;
}


void Person::print()
{
	cout << "姓名：" << name << '\t' << "年龄" << age << endl;
}
