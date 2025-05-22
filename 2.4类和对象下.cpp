#include "sourse.h"
#include <string>
#include <list>
//���캯������֮�󣬶������Ѿ�����һ����ʼֵ�����ǲ��ܽ����Ϊ�Զ����г�Ա�����ĳ�ʼ����
//���캯�����е����ֻ�ܽ����Ϊ����ֵ�������ܳ�����ʼ������Ϊ��ʼ��ֻ�ܳ�ʼ��һ�Σ������캯����
//�ڿ��Զ�θ�ֵ��

//��ʼ���б���һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�ÿ��"��Ա����"�����һ��������
//���еĳ�ʼֵ����ʽ��

//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//���ó�Ա����
//const��Ա����
//�Զ������ͳ�Ա(�Ҹ���û��Ĭ�Ϲ��캯��ʱ,Ĭ�Ϲ��캯��������1.��д��ʾĬ�Ϲ��죬2.ȫȱʡĬ�Ϲ��캯��3.�޲ι��캯��)

//����ʹ�ó�ʼ���б��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ����
//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�

//���ǳ�ʼ������ɲ������е����飬�����ʼ��һ������

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
//	// ��ʼ���б�����ĳ�Ա�����λ��
//	B(int a,  int ref)
//		:_ref(ref)
//		,_n(1)
//		,_x(2)
//		,_aobj(a) 
//	{
//		//�������ڲ������Զ�̬��������֮��Ļ�
//		//�Լ���̬���ٵĿռ��Ƿ񱻿��ٽ��м��
//		//_n = 0;
//		//_ref = ref;
//	}
//
//
//private:
//	// ����
//	A _aobj;	  // û��Ĭ�Ϲ��캯��
//
//	// �����������ڶ����ʱ���ʼ��
//	//���ñ����ڳ�ʼ���б��г�ʼ���������ڹ��캯�����ڸ�ֵ��
//	//const ���������ڳ�ʼ���б��г�ʼ���������ڹ��캯�������޸ġ�
//
//	int& _ref;	  // ����
//	const int _n; // const
//
//	int _x = 1;  // ����1��ȱʡֵ��ȱʡֵ�Ǹ���ʼ���б��
//};
//
//int main()
//{
//	// �������嶨��
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
	// ��ʼ���б�����ĳ�Ա�����λ��
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
	// ����
	A _aobj;	  // û��Ĭ�Ϲ��캯��

	// �����������ڶ����ʱ���ʼ��
	int& _ref;	  // ����
	const int _n; // const

	int _x = 1;  // ����1��ȱʡֵ��ȱʡֵ�Ǹ���ʼ���б��
};

// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc����ռ�ʧ��");
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

//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//�������ǽ��飺�����ͳ�ʼ����˳�򱣳�һ�¡�

class A1
{
public:
	A1(int a)
		:_a1(a)
		, _a2(_a1)  //�������ȳ�ʼ��_a2������a2�����ֵ��a1������ʼ��
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
//	A aa2 = 2; // ��ʽ����ת��������ת�����Զ�������]
//		// 2����һ��A����ʱ������ʱ�����ٿ�������aa2 -->�Ż���2ֱ�ӹ���
//	
//		// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��A &��
//		//A& aa3 = 2;
//	const A& aa3 = 2;  //����Ϳ��ԣ���Ϊ��������ʱ�������г��ԣ����ԾͿ��Ա�const������
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
//	string name1("����");
//	string name2 = "����";
//
//	list1 lt1;
//	string name3("����");
//	lt1.push_back(name3);
//
//	lt1.push_back("����");  //����ͷ�������ʽ����ת�����ڴ�ֵ�Ĺ����г���const string& str = "����"
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
		// �Ǿ�̬�ܷ���þ�̬������
		GetCCount();
	}

	void Func2()
	{
		++_a1;
	}

	//��̬��Ա���� û��thisָ�룬ָ������ͷ����޶����Ϳ��Է���
	static int GetCCount() 
	{ 
		// ��̬�����ܷ���÷Ǿ�̬�����������ԡ��Ǿ�̬�ĳ�Ա����������Ҫthisָ�룬��û��this
		// Func2();

		//_a1++;
		return _scount;
	}
private:
	// ��Ա���� -- ����ÿ��һ������󣬴洢��������,��Ա�������ڵ�����һ����
	int _a1 = 1;
	int _a2 = 2;
//public:
	// ��̬��Ա���� -- �����࣬�������ÿ���������洢�ھ�̬��
	static int _scount;
};

//��̬��Ա�������� ȫ��λ�ã������涨��
int C::_scount = 0;

C aa0;

void Func()
{
	static C aa2;
	cout << __LINE__ << ":" << aa2.GetCCount() << endl;

	// ȫ�ֱ��������ƣ��κεط�����������ı�
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

// ���һ���࣬��������ֻ����ջ�ϴ�������
// ���һ���࣬��������ֻ���ڶ��ϴ�������
class D
{
public:
	static D GetStackObj()  //��̬�ĺ������ڷ��ھ�̬����ָ������ͷ����޶����Ϳ��Է���
	{
		D aa;
		return aa;
	}

	static D* GetHeapObj()
	{
		return new D;
	}
private:
	D()  //�����캯����������private�У�������Ķ��������˶���
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};

//int main()
//{
//	//static D aa1;   //  ��̬��
//	//D aa2;          //  ջ 
//	//D* ptr = new D; //  ��
//	D::GetStackObj(); //��ʱ���þ�̬��Ա�������Ϳ��Դ�����������Ϊ��̬��Ա�����������ڣ����Է���private�������贴���¶���ֻ��Ҫָ������Ϳ���
//	D::GetHeapObj();
//
//	return 0;
//}

//������һ���ඨ������һ������ڲ�������ڲ���ͽ����ڲ��ࡣ�ڲ�����һ���������࣬����������
//���࣬������ͨ���ⲿ��Ķ���ȥ�����ڲ���ĳ�Ա���ⲿ����ڲ���û���κ���Խ�ķ���Ȩ�ޡ�
//ע�⣺�ڲ�������ⲿ�����Ԫ�࣬�μ���Ԫ��Ķ��壬�ڲ������ͨ���ⲿ��Ķ�������������ⲿ����
//�����г�Ա�������ⲿ�಻���ڲ������Ԫ��
//���ԣ�
//1. �ڲ�����Զ������ⲿ���public��protected��private���ǿ��Եġ�
//2. ע���ڲ������ֱ�ӷ����ⲿ���е�static��Ա������Ҫ�ⲿ��Ķ��� / ������
//3. sizeof(�ⲿ��) = �ⲿ�࣬���ڲ���û���κι�ϵ��

class teacher
{
public:
	int age;
	teacher()
	{
		cout << "�޲ι���" << endl;
	}
	teacher(const teacher& a1)
	{
		cout << "��������" << endl;
	}

	~teacher()
	{
		cout << "����" << endl;
	}

private:
	class student  //�ڲ����������ⲿ�����Ԫ
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
	return aa;  //�˴����ص���aa����ʱ�������ʴ˴�������ʱ�������ÿ������캯��������ʱ�������г���
}

teacher& func4()
{
	teacher aaa;
	return aaa; //���������÷��أ��ʲ��ٵ��ÿ������캯�����ӿ������ٶ�
}

//��������ͬһ����������������򿽱����죬��϶�Ϊһ����д��ʼ��ʱ���д��ͬһ��

int main()
{
	//teacher tea1;

	//teacher(); //������������������������ֻ�ڸ��У�������������г���

	//const teacher& tea2 = teacher();  //�����ǿ����չ�������ڣ�����������չ���˵�ǰ��������������

	const teacher& tea3 = func3(); //�˴���Ҫ��ǰ���const�����ܷ���ֵ����ʱ������
	/*func2(tea1);*/
	Solution().Sum_Solution(10);  //�������������ã����������ü�����
}