#include "2.3.1时间计算器.h"

void TestDate1()
{
	Date d1(2023, 4, 26);
	d1 += 100;
	d1.Print();

	Date d2(2023, 4, 26);
	//Date d3(d2 + 100);
	Date d3 = d2 + 100;
	d2.Print();
	d3.Print();

	// 用一个已经存在的对象初始化另一个对象  -- 构造函数
	Date d4 = d2;  // 等价于 Date d4(d2);

	//已经存在的两个对象之间复制拷贝        -- 运算符重载函数
	d4 = d1;

	//int i = 0, j = 1;
	//j += i += 10;
}

void TestDate2()
{
	Date d1(2023, 4, 26);
	// 都要++，前置++返回++以后的对象，后置++返回++之前的对象
	++d1; // d1.operator++()
	d1++; // d1.operator++(0)

	Date d2(2023, 4, 26);
	Date d3(2023, 4, 26);

	bool ret1 = d2 < d3;

	int i = 1, j = 2;
	bool ret2 = i < j;
}

void TestDate3()
{
	Date d1(2023, 5, 5);
	d1 -= 50;
	d1.Print();

	Date d2(2023, 5, 5);
	d2 -= 100;
	d2.Print();

	Date d3(2023, 5, 5);
	d3 -= 1000;
	d3.Print();

	Date d4(2023, 5, 5);
	d4 -= 10000;
	d4.Print();
}

void TestDate4()
{
	Date d1(2023, 5, 5);
	d1 += 100;
	d1.Print();

	Date d2(2023, 5, 5);
	d2 += -100;
	d2.Print();

	Date d3(2023, 5, 5);
	d3 -= -100;
	d3.Print();
}

void TestDate5()
{
	Date d1(2023, 5, 5);
	Date ret1 = d1--; // d1.operator--(&d1, 0);
	ret1.Print();
	d1.Print();

	Date d2(2023, 5, 5);
	Date ret2 = --d2; // d1.operator--(&d1);
	ret2.Print();
	d2.Print();
}

void TestDate6()
{
	Date d1(2023, 5, 5);
	Date d2(1949, 10, 1);

	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}

void TestDate7()
{
	Date d1(2023, 5, 5);
	d1 += 100;

	// 流插入
	cout << d1; // operator<<(cout, d1);
	operator<<(cout, d1);

	//d1 << cout; // d1.operator<<(cout); 
	//d1.operator<<(cout);


	Date d2(2023, 5, 5);
	Date d3(1949, 10, 1);

	//d1 = d2 = d3;

	cout << d2 << d3 << d1;

	cin >> d1 >> d2;
	cout << d2 << d1;

	//Date d4(2023, 13, 1);
	//cout << d4;
}

void TestDate8()
{
	Date d1(2023, 5, 5);
	d1.Print(); //当类成员没有常量修饰时，在调用成员函数会隐式变成d1.print(&d1);传给print(Data* this)函数，中间这个Data* this是隐式传递，并且不可显示的

	const Date d2(2023, 5, 5);
	d2.Print(); //当类成员有常量修饰时，在调用成员函数也会变成上面那样d2.print(&d2)，传递给print(Data* this)函数
				//但是你d2是不可修改的const修饰，但是你this没有常量修饰，反而可以用this修改，这是一种权限放大的过程，但是传值时权限只能缩小或者平替
				//故此时必须要变成传给print(const Data* this)函数，但是这又是个隐式的函数，不能显示写
				//最后只能在函数声明时有print( )const，把const放在最后意味着修饰Data* this
	d1 + 100;
	d2 + 100;

	d1 < d2;
	d2 < d1;
}

int main()
{
	TestDate8();

	return 0;
}