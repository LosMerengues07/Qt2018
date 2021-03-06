// D1T2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
using namespace std;

class Shape
{
public:
	virtual double getarea() = 0;            //纯虚函数
};

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double r) :r(r) {}
	double getarea() { return 3.1416*r*r; }
};

class Rectangle : public Shape
{
private:
	double w, l;
public:
	Rectangle(double w, double l) :w(w), l(l) {}
	double getarea() { return w * l; }
};

class Square : public Shape
{
private:
	double a;
public:
	Square(double a) :a(a) {}
	double getarea() { return a * a; }
};

int main(int argc, char **argv) {
	Shape * shapes[4];
	Circle circle(2.0);
	Rectangle rectangle(3.0, 4.0);
	Square square1(5.0);
	Square square2(4.0);
	shapes[0] = &circle;
	shapes[1] = &rectangle;
	shapes[2] = &square1;
	shapes[3] = &square2;
	for (int k = 0; k < 4; k++) {
		cout << "Area is " << shapes[k]->getarea() << endl;
	}
	return 0;
}

