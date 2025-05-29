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
//    // CPP 申请10个int的数组，申请的空间放在堆区，但p4仍在栈区
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP 申请一个数，初始化为10
//    int* p5 = new int(10);
//    delete p5;
//
//    //数组的初始化，需要在[]后面放{ }
//    int* p6 = new int[10]{1,2,3}; //部分初始化而某些未初始化的全部赋值为，若全未初始化则为随机值
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
    // 单纯开空间
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 检查
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

class text_1
{
public:
    text_1()
    {
        cout << "text_1的构造函数" << endl;
    }
    ~text_1()
    {
        cout << "text_1的析构函数" << endl;
    }
};

//int main2()
//{
//    struct ListNode* n1 = BuyListNode(1);
//    struct ListNode* n2 = BuyListNode(2);
//    struct ListNode* n3 = BuyListNode(3);
//
//    // 开空间+调用构造函数初始化
//    ListNode* nn1 = new ListNode(1);
//    ListNode* nn2 = new ListNode(2);
//    ListNode* nn3 = new ListNode(3);
//
//    text_1* Aa = new text_1;  //new为自定义类型是会调用构造函数，new是先开空间再调用构造函数
//    delete Aa; //delete为自定义类型是为析构函数，delete是先析构再释放空间
//
//    text_1* Aa1 = new text_1[5];  //当然创建一个5个的数组就会调用5次构造函数
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

 //原则：new和delete一定要匹配使用
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
//	A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3),A(4,4) };  //这里是用临时变量初始化，调用的是构造函数而非拷贝构造，并且如果构造函数不是默认构造或者全缺省，就必须要初始化跟数组容量相同
//	free(p5);
//	delete[] p6;
//
//	return 0;
//}

//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	// 显示调用构造函数
//	new(p1)A(1);  // 注意：如果A类的构造函数有参数时，此处需要传参
//
//    //结构：new(类指针）类名(构造函数传参参数）
//
//	p1->~A();  //显示调用析构函数
//    //为什么要显示调用这个问题
//    //此时p1是内置类型，即指针变量，指针变量不
//	free(p1);
//
//	return 0;
//}


