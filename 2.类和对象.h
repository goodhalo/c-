#pragma once
#include "sourse.h"

class Stack  //û��ʵ��������ʱ�����ﶼ��������������ռ1byte���ֽڴ�С
{
public:
	// ��Ա����
	void Init(int defaultCapacity = 4);        /*�����Ͷ���ȫ�����������У���ע�� : ��Ա������������ж��壬���������ܻὫ�䵱��������������*/
												/*����������.h�ļ��У���Ա�����������.cpp�ļ��У�ע�⣺��Ա������ǰ��Ҫ������::*/
												//�����ȱʡֵ��ȱʡֵ��������
	/*Stack(Stack& const sk) {
		this->a = (int*)malloc(sizeof(int)*sk.capacity);
		this->top = sk.top;
		this->capacity = sk.capacity;
	}*/



	void Push(int x)
	{
		//...
		a[top++] = x;
	}

	void Destroy()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}

	~Stack()
	{
		free(this->a);
		a = nullptr;
		top = 0;
		capacity = 0;
	}
	// ....
//private:
	// ��Ա����
	int* a;   //���������ʲ����ռ䣬������ռ䣬�ͱ�ɶ����ˣ�����ֻ��ʵ������ʱ��Żᶨ��
	int top;  //���������cadͼֽ��ֻ��ʵ�����Ż�ѷ��������
	int capacity = 0; //��Ȼ��Ҳ���Ը�ȱʡֵ����Ĭ�Ϲ��캯���õģ����û�г�ʼ����Ա�������ͻ��Զ���ֵ�������ȱʡֵ
};

