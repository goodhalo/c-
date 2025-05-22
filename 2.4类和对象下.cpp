#include "sourse.h"
#include <string>
#include <list>
//构造函数调用之后，对象中已经有了一个初始值，但是不能将其称为对对象中成员变量的初始化，
//构造函数体中的语句只能将其称为赋初值，而不能称作初始化。因为初始化只能初始化一次，而构造函数体
//内可以多次赋值。

//初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括
//号中的初始值或表达式。

//1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//2. 类中包含以下成员，必须放在初始化列表位置进行初始化：
//引用成员变量
//const成员变量
//自定义类型成员(且该类没有默认构造函数时,默认构造函数包括：1.不写显示默认构造，2.全缺省默认构造函数3.无参构造函数)

//尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，一定会先使用初始化列表初始化。
//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关

//但是初始化链表干不完所有的事情，比如初始化一个数组

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" <<endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a,  int ref)
//		:_ref(ref)
//		,_n(1)
//		,_x(2)
//		,_aobj(a) 
//	{
//		//函数体内部，可以动态开辟数组之类的活
//		//以及动态开辟的空间是否被开辟进行检查
//		//_n = 0;
//		//_ref = ref;
//	}
//
//
//private:
//	// 声明
//	A _aobj;	  // 没有默认构造函数
//
//	// 特征：必须在定义的时候初始化
//	//引用必须在初始化列表中初始化，不能在构造函数体内赋值。
//	//const 变量必须在初始化列表中初始化，不能在构造函数体内修改。
//
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//int main()
//{
//	// 对象整体定义
//	B bb1(10,20); 
//	//B bb2(11, 2);
//
//
//	return 0;
//}

class A
{
public:
	/*A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}*/
	A(int a)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}
private:
	int _a;
};

class B
{
public:
	// 初始化列表：对象的成员定义的位置
	B(int a, int& ref)
		:_ref(ref)
		, _n(1)
		, _x(2)
		, _aobj(a)
	{
		//_n = 0;
		//_ref = ref;
	}

private:
	// 声明
	A _aobj;	  // 没有默认构造函数

	// 特征：必须在定义的时候初始化
	int& _ref;	  // 引用
	const int _n; // const

	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
};

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			return;
		}

		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

class MyQueue
{
public:
	MyQueue()
	{}

	MyQueue(int capacity)
		:_pushst(capacity)
		,_popst(capacity)
	{}

private:
	Stack _pushst;
	Stack _popst;
};

//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//所以我们建议：声明和初始化的顺序保持一致。

class A1
{
public:
	A1(int a)
		:_a1(a)
		, _a2(_a1)  //这里是先初始化_a2，所以a2是随机值，a1正常初始化
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

//int main() {
//	A1 aa(1);
//	aa.Print();
//
//	A aa1(1);
//	A aa2 = 2; // 隐式类型转换，整形转换成自定义类型]
//		// 2构造一个A的临时对象，临时对象再拷贝构造aa2 -->优化用2直接构造
//	
//		// error C2440: “初始化”: 无法从“int”转换为“A &”
//		//A& aa3 = 2;
//	const A& aa3 = 2;  //这个就可以，因为创建的临时变量具有常性，常性就可以被const给引用
//	
//	
//	int i = 10;
//	double d = i;
//	
//	return 0;
//}


class string1
{
public:
	string1(const char* str)
	{}
};

class list1
{
public:
	void push_back(const string& str)
	{}
};

//int main()
//{
//	string name1("张三");
//	string name2 = "张三";
//
//	list1 lt1;
//	string name3("李四");
//	lt1.push_back(name3);
//
//	lt1.push_back("李四");  //这个就发生了隐式类型转换，在传值的过程中出现const string& str = "李四"
//
//	return 0;
//}

class C
{
public:
	C() 
	{
		++_scount;
	}

	C(const C& t) 
	{
		++_scount;
	}

	~C() 
	{ 
		--_scount;
	}


	void Func1()
	{
		// 非静态能否调用静态：可以
		GetCCount();
	}

	void Func2()
	{
		++_a1;
	}

	//静态成员函数 没有this指针，指定类域和访问限定符就可以访问
	static int GetCCount() 
	{ 
		// 静态函数能否调用非静态变量：不可以。非静态的成员函数调用需要this指针，我没有this
		// Func2();

		//_a1++;
		return _scount;
	}
private:
	// 成员变量 -- 属于每个一个类对象，存储对象里面,成员变量属于单独的一个类
	int _a1 = 1;
	int _a2 = 2;
//public:
	// 静态成员变量 -- 属于类，属于类的每个对象共享，存储在静态区
	static int _scount;
};

//静态成员变量定义 全局位置，类外面定义
int C::_scount = 0;

C aa0;

void Func()
{
	static C aa2;
	cout << __LINE__ << ":" << aa2.GetCCount() << endl;

	// 全局变量的劣势：任何地方都可以随意改变
	//_scount++;
}

//int main()
//{
//	cout <<__LINE__<<":"<< C::GetCCount() << endl;  // 1
//	C aa1;
//	
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
//}

// 设计一个类，在类外面只能在栈上创建对象
// 设计一个类，在类外面只能在堆上创建对象
class D
{
public:
	static D GetStackObj()  //静态的函数由于放在静态区，指定类域和访问限定符就可以访问
	{
		D aa;
		return aa;
	}

	static D* GetHeapObj()
	{
		return new D;
	}
private:
	D()  //而构造函数被放在了private中，故外面的都创建不了对象
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};

//int main()
//{
//	//static D aa1;   //  静态区
//	//D aa2;          //  栈 
//	//D* ptr = new D; //  堆
//	D::GetStackObj(); //此时调用静态成员函数，就可以创建，这是因为静态成员函数仍在类内，可以访问private，且无需创建新对象，只需要指定类域就可以
//	D::GetHeapObj();
//
//	return 0;
//}

//概念：如果一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，它不属于外
//部类，更不能通过外部类的对象去访问内部类的成员。外部类对内部类没有任何优越的访问权限。
//注意：内部类就是外部类的友元类，参见友元类的定义，内部类可以通过外部类的对象参数来访问外部类中
//的所有成员。但是外部类不是内部类的友元。
//特性：
//1. 内部类可以定义在外部类的public、protected、private都是可以的。
//2. 注意内部类可以直接访问外部类中的static成员，不需要外部类的对象 / 类名。
//3. sizeof(外部类) = 外部类，和内部类没有任何关系。

class teacher
{
public:
	int age;
	teacher()
	{
		cout << "无参构造" << endl;
	}
	teacher(const teacher& a1)
	{
		cout << "拷贝构造" << endl;
	}

	~teacher()
	{
		cout << "析构" << endl;
	}

private:
	class student  //内部类天生是外部类地友元
	{
	public:
		int age;
		int grade;
	};
};

class Solution {
public:
    int Sum_Solution(int n) {
        cout << "Sum_Solution" << endl;
        //...
        return n;
    }
};

teacher& func1()
{
	teacher aa;
	return aa;
}

void func2(const teacher& a2)
{

}
teacher func3()
{
	teacher aa;
	return aa;  //此处返回的是aa的临时变量，故此处会让临时变量调用拷贝构造函数，且临时变量具有常性
}

teacher& func4()
{
	teacher aaa;
	return aaa; //由于是引用返回，故不再调用拷贝构造函数，加快运行速度
}

//编译器在同一行中连续拷贝构造或拷贝构造，会合二为一，故写初始化时最好写在同一行

int main()
{
	//teacher tea1;

	//teacher(); //匿名对象，匿名对象生命周期只在该行，且匿名对象具有常性

	//const teacher& tea2 = teacher();  //这个会强行扩展生命周期，生命周期扩展到了当前函数地作用域下

	const teacher& tea3 = func3(); //此处需要在前面加const来接受返回值是临时变量的
	/*func2(tea1);*/
	Solution().Sum_Solution(10);  //匿名对象函数调用，匿名对象即用即销毁
}