#include "sourse.h"

//int main1()
//{
//    // C
//    int* p1 = (int*)malloc(sizeof(int));
//    free(p1);
//
//    // CPP
//    int* p2 = new int;
//    delete p2;
//
//    // C
//    int* p3 = (int*)malloc(sizeof(int)*10);
//    free(p3);
//
//    // CPP ����10��int�����飬����Ŀռ���ڶ�������p4����ջ��
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP ����һ��������ʼ��Ϊ10
//    int* p5 = new int(10);
//    delete p5;
//
//    //����ĳ�ʼ������Ҫ��[]�����{ }
//    int* p6 = new int[10]{1,2,3}; //���ֳ�ʼ����ĳЩδ��ʼ����ȫ����ֵΪ����ȫδ��ʼ����Ϊ���ֵ
//    delete[] p6;
//
//    return 0;
//}

struct ListNode
{
    int _val;
    struct ListNode* _next;

    ListNode(int x)
        :_val(x)
        , _next(NULL)
    {}
};

struct ListNode* BuyListNode(int x)
{
    // �������ռ�
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // ���
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

class text_1
{
public:
    text_1()
    {
        cout << "text_1�Ĺ��캯��" << endl;
    }
    ~text_1()
    {
        cout << "text_1����������" << endl;
    }
};

//int main2()
//{
//    struct ListNode* n1 = BuyListNode(1);
//    struct ListNode* n2 = BuyListNode(2);
//    struct ListNode* n3 = BuyListNode(3);
//
//    // ���ռ�+���ù��캯����ʼ��
//    ListNode* nn1 = new ListNode(1);
//    ListNode* nn2 = new ListNode(2);
//    ListNode* nn3 = new ListNode(3);
//
//    text_1* Aa = new text_1;  //newΪ�Զ��������ǻ���ù��캯����new���ȿ��ռ��ٵ��ù��캯��
//    delete Aa; //deleteΪ�Զ���������Ϊ����������delete�����������ͷſռ�
//
//    text_1* Aa1 = new text_1[5];  //��Ȼ����һ��5��������ͻ����5�ι��캯��
//    delete[] Aa1;
//
//    return 0;
//}

class A
{
public:
    //A(int a = 0)
    A(int a = 0, int b = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }

    A(const A& aa)
        : _a(aa._a)
    {
        cout << "A(const A& aa):" << this << endl;
    }

    ~A()
    {
        cout << "~A():" << this << endl;
    }

private:
    int _a;
};

 //ԭ��new��deleteһ��Ҫƥ��ʹ��
//int main3()
//{
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1,1);
//	free(p1);
//	delete p2;
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	//A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3) };
//	A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3),A(4,4) };  //����������ʱ������ʼ�������õ��ǹ��캯�����ǿ������죬����������캯������Ĭ�Ϲ������ȫȱʡ���ͱ���Ҫ��ʼ��������������ͬ
//	free(p5);
//	delete[] p6;
//
//	return 0;
//}

//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	// ��ʾ���ù��캯��
//	new(p1)A(1);  // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
//
//    //�ṹ��new(��ָ�룩����(���캯�����β�����
//
//	p1->~A();  //��ʾ������������
//    //ΪʲôҪ��ʾ�����������
//    //��ʱp1���������ͣ���ָ�������ָ�������
//	free(p1);
//
//	return 0;
//}


