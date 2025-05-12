#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

class Date
{
	// 友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1);

	void Print() const  //const放在成员函数后修饰的是data* this
	{					//详细再2.3.2时间text中text8函数有写
						//只要成员函数内部不修改成员变量最好都加const，因为这样普通成员可以调用，const成员也可以调用
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date(const Date& d)   // 错误写法：编译报错，会引发无穷递归
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& x) const;
	bool operator==(const Date& x) const;
	bool operator<=(const Date& x) const;
	bool operator>(const Date& x) const;
	bool operator>=(const Date& x) const;
	bool operator!=(const Date& x) const;

	int GetMonthDay(int year, int month);

	// d1 + 100
	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;

	// 流插入不能写成成员函数?
	// 因为Date对象默认占用第一个参数，就是做了左操作数
	// 写出来就一定是下面这样子，不符合使用习惯
	//d1 << cout; // d1.operator<<(cout); 
	/*void operator<<(ostream& out);*/

	/*int GetYear()
	{
		return _year;
	}*/
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);
