# list.push_back
关于 list.pushu_back 究竟把什么放在了list中的研究---list.pushu_back 其实复制了一份（）中的对象插进了list

练习list 的push_back时发现对象被析构了两次，就想研究一下push_back到底做了什么，见代码。

//文件：Preson.h



```c++
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
```

//文件：Person.cpp

```c++
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
```
文件：main.cpp
```c++
#include<iostream>
#include<list>
#include"Person.h"
using namespace std;

void test()
{
	Person p1("李刚",19);
	Person p2("小明", 24);
	Person p3 = p2, p4("王超", 18);

	{//list作用域
		list<Person> lp;

		lp.push_back(p1);
		lp.push_back(p2);
		lp.push_back(p3);
		lp.push_back(p4);
		cout <<"lp.front()的地址："<< &(lp.front())<<' ';
		lp.front().print();

	/*
	for (list<Person>::iterator it = lp.begin(); it != lp.end(); it++)
	{
		(*it).print();
	}*/

	}
	cout << "........................." << endl;
	cout <<"p1的地址:"<< &p1 << ' ';
	p1.print();
}

int main()
{
	test();
	
	cin.get();

	return 0;
}
```
```c++
输出：

传参 constructer 被调用
传参 constructer 被调用
传参 constructer 被调用
lp.front()的地址：01489830 姓名：李刚   年龄19
姓名：李刚      年龄19  析构函数被调用！
姓名：小明      年龄24  析构函数被调用！
姓名：小明      年龄24  析构函数被调用！
姓名：王超      年龄18  析构函数被调用！
.........................
p1的地址:00FDF9E4 姓名：李刚    年龄19
姓名：王超      年龄18  析构函数被调用！
姓名：小明      年龄24  析构函数被调用！
姓名：小明      年龄24  析构函数被调用！
姓名：李刚      年龄19  析构函数被调用！
```
lp.front()的地址和p1的地址不同，所以list的push_back()是把对象拷贝了一份放进了list中，所以是两组对象被析构了两次。
