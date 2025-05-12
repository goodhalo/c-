#include "2.3.1ʱ�������.h"

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

	// ��һ���Ѿ����ڵĶ����ʼ����һ������  -- ���캯��
	Date d4 = d2;  // �ȼ��� Date d4(d2);

	//�Ѿ����ڵ���������֮�临�ƿ���        -- ��������غ���
	d4 = d1;

	//int i = 0, j = 1;
	//j += i += 10;
}

void TestDate2()
{
	Date d1(2023, 4, 26);
	// ��Ҫ++��ǰ��++����++�Ժ�Ķ��󣬺���++����++֮ǰ�Ķ���
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

	// ������
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
	d1.Print(); //�����Աû�г�������ʱ���ڵ��ó�Ա��������ʽ���d1.print(&d1);����print(Data* this)�������м����Data* this����ʽ���ݣ����Ҳ�����ʾ��

	const Date d2(2023, 5, 5);
	d2.Print(); //�����Ա�г�������ʱ���ڵ��ó�Ա����Ҳ������������d2.print(&d2)�����ݸ�print(Data* this)����
				//������d2�ǲ����޸ĵ�const���Σ�������thisû�г������Σ�����������this�޸ģ�����һ��Ȩ�޷Ŵ�Ĺ��̣����Ǵ�ֵʱȨ��ֻ����С����ƽ��
				//�ʴ�ʱ����Ҫ��ɴ���print(const Data* this)���������������Ǹ���ʽ�ĺ�����������ʾд
				//���ֻ���ں�������ʱ��print( )const����const���������ζ������Data* this
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