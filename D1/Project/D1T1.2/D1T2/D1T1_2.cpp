// D1T2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class Member
{
	friend ostream & operator<<(ostream &out, Member &obj);
private:
	string name;
	int age;
public:
	Member(string n = "?", int a = 0)
	{
		name = n;
		age = a;
	}
	string getName() { return name; }
	int getAge() { return age; }
};
class MemberList
{
private:
	Member * member;
	int num;
public:
	MemberList(Member* m, int n)
	{
		member = m;
		num = n;
	}

	int& operator[](string n)
	{
		int age = 0;
		for (int i = 0; i < num; i++)
		{
			if (n == member[i].getName())
			{
				age = member[i].getAge();
				break;
			}
		}
		return age;
	}
};
ostream & operator<<(ostream &out, Member &obj)
{
	out << setw(10) << obj.name << " " << obj.age;
	return out;
}
int main()
{
	Member newCommers[5] = { Member("Zhang San", 22),
		Member("Li Si", 19),
		Member("Wang Wu", 18),
		Member("Zhao Liu", 24) };
	for (int i = 0; i < 5; i++)
	{
		cout << newCommers[i] << endl;
	}
	string name[5] = { "Zhang San", "Li Si", "Wang Wu", "Zhao Liu", "Pin Yin" };
	MemberList list(newCommers, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << list[name[i]] << endl;
	}
	return 0;
}