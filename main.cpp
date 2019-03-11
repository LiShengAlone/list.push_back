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
		cout <<"lp.front()的地址：" <<&(lp.front())<<' ';
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
