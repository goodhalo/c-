#include "sourse.h"

template<typename T>
//template<typename/class ģ����>
//����ģ��ı����Ǳ������ں�̨�Ѹ�ͬ������ȫ���ò�ͬ�������ͽ��к�������
//���൱��д��void swap(int& a, int& b),void swap(double& a, double& b)�Ⱥ���

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
//	Swap(a, b);  //������������ͬһ������,�����void swap(int& a, int& b)
//	Swap(c, d);  //�����void swap(double& a, double& b)
//
//	int* p1 = &a, * p2 = &b;
//
//	swap(p1, p2);  //�����ǰѵ�ַ����
//
//	cout << *p1 <<"	" << *p2 << endl;
//
//	cout << a << b << endl;
//	cout << c << d << endl;
//
//
//	/*template<typename T>      
//	T Add(const T & x1, const T & x2)  //���ﴫ�α���Ҫ��const���Σ���Ϊ���洫�η�����ǿ������ת������ǿ������ת���ı����Ƿ�������ʱ��������ʱ�������г��ԣ��������const�ͻᷢ��Ȩ�޷Ŵ�
//	{
//		return x1 + x2;
//	}*/
//	cout << Add<int>(a, c) << endl;  //��ʾʵ����
//	cout << Add(a, (int)c) << endl;  //ǿ������ת��
//	
//	return 0;
//}



// ��ģ��,����ͨ�����У����ͺ���������ͬ��
//��������ģ���У������������ǲ�ͬ��
// ��ͨ�࣬������������һ��
// ��ģ�壬���������Ͳ�һ��
// ������Stack
// ���ͣ�Stack<T>

template<class T>
class Stack
{
public:
	Stack(size_t capacity = 3);  //��ģ���У����������������������

	void Push(const T& data);

	// ��������...

	~Stack();

private:
	T* _array;
	int _capacity;
	int _size;
};


template<class T>
Stack<T>::Stack(size_t capacity)  //����������ĺ����У�����Ҫ������������Stack<T>��������ǹ��캯�������������ʾʵ����
{
	/*_array = (T*)malloc(sizeof(T) * capacity);
	if (NULL == _array)
	{
		perror("malloc����ռ�ʧ��!!!");
		return;
	}*/
	cout << "���캯��" << endl;
	_array = new T[capacity];

	_capacity = capacity;
	_size = 0;
}

template<class T>
Stack<T>::~Stack()  //���ⶨ����������
{
	cout << "��������" << endl;
	if (_array)
	{
		free(_array);
		_array = NULL;
		_capacity = 0;
		_size = 0;
	}
}

template<class T>
void Stack<T>::Push(const T& data)  //���������ⶨ��ĳ�Ա�����������Ƿ�������void��Ȼ�������ĸ����ж����stack<T>,����Ǻ�����push
{
	// CheckCapacity();
	_array[_size] = data;
	_size++;
}

// ��ͨ�࣬������������һ��
// ��ģ�壬���������Ͳ�һ��
// ������Stack
// ���ͣ�Stack<T>

//int main()
//{
//	Stack<int> st(20); //ʵ����ʱ����Ҫ��ʾʵ����
//	return 0;
//}