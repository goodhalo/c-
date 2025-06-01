#include "sourse.h"

template<typename T>
//template<typename/class 模板名>
//函数模板的本质是编译器在后台把该同名函数全部用不同数据类型进行函数重载
//即相当于写出void swap(int& a, int& b),void swap(double& a, double& b)等函数

void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
}

template<typename T>
T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}

//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.2, d = 2.2;
//
//	Swap(a, b);  //这俩函数不是同一个函数,这个是void swap(int& a, int& b)
//	Swap(c, d);  //这个是void swap(double& a, double& b)
//
//	int* p1 = &a, * p2 = &b;
//
//	swap(p1, p2);  //这里是把地址交换
//
//	cout << *p1 <<"	" << *p2 << endl;
//
//	cout << a << b << endl;
//	cout << c << d << endl;
//
//
//	/*template<typename T>      
//	T Add(const T & x1, const T & x2)  //这里传参必须要用const修饰，因为下面传参发生了强制类型转换，而强制类型转换的本质是发生了临时变量，临时变量具有常性，如果不用const就会发生权限放大
//	{
//		return x1 + x2;
//	}*/
//	cout << Add<int>(a, c) << endl;  //显示实例化
//	cout << Add(a, (int)c) << endl;  //强制类型转换
//	
//	return 0;
//}



// 类模板,在普通的类中，类型和类名是相同的
//但是在类模板中，类名和类型是不同的
// 普通类，类名和类型是一样
// 类模板，类名和类型不一样
// 类名：Stack
// 类型：Stack<T>

template<class T>
class Stack
{
public:
	Stack(size_t capacity = 3);  //类模板中，构造和析构都还是用类名

	void Push(const T& data);

	// 其他方法...

	~Stack();

private:
	T* _array;
	int _capacity;
	int _size;
};


template<class T>
Stack<T>::Stack(size_t capacity)  //但是在类外的函数中，必须要用类型名，即Stack<T>：：这个是构造函数，这里必须显示实例化
{
	/*_array = (T*)malloc(sizeof(T) * capacity);
	if (NULL == _array)
	{
		perror("malloc申请空间失败!!!");
		return;
	}*/
	cout << "构造函数" << endl;
	_array = new T[capacity];

	_capacity = capacity;
	_size = 0;
}

template<class T>
Stack<T>::~Stack()  //类外定义析构函数
{
	cout << "析构函数" << endl;
	if (_array)
	{
		free(_array);
		_array = NULL;
		_capacity = 0;
		_size = 0;
	}
}

template<class T>
void Stack<T>::Push(const T& data)  //像这种类外定义的成员函数，首先是返回类型void，然后是在哪个类中定义的stack<T>,最后是函数名push
{
	// CheckCapacity();
	_array[_size] = data;
	_size++;
}

// 普通类，类名和类型是一样
// 类模板，类名和类型不一样
// 类名：Stack
// 类型：Stack<T>

//int main()
//{
//	Stack<int> st(20); //实例化时必须要显示实例化
//	return 0;
//}