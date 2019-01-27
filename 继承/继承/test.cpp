#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
//class Person
//{
//public:
//	int _tel = 123;
//	void print()
//	{
//		cout << "age:"<<_age << endl;
//		cout <<"name:"<< _name << endl;
//	}
//protected:
//	int _age=18;
//	string _name="nana";
//};
//
//class Student :protected  Person
//{
//public:
//	void fun()
//	{
//		//cout << "tel:" << _tel << endl;
//
//	}
//private:
//	int _stuid;
//};



//class Base
//{
//public:
//	Base(int b = 10)
//		:_b(b)
//	{
//		cout << "Base" << endl;
//	}
//private:
//	int _b;
//};
//
//class Der :public Base
//{
//public:
//	Der()
//		:_d(20)
//	{
//		cout << "Der" << endl;
//	}
//
//private:
//	int _d;
//};


//////////////////////////////////////////////////////
//class B
//{
//public:
//	int _b;
//};
//
//class C1 : virtual public B
//{
//public:
//	int _c1;
//};
//
//class C2 :virtual public B
//{
//public:
//	int _c2;
//};
//
//class D :public C1, public C2
//{
//public:
//	int _d;
//};
//
//class A
//{
//public:
//	int _a;
//};
//class M:virtual public A
//{
//public:
//	int _m;
//};



//单继承
//class A
//{
//public:
//	int _a;
//};
//
//class B :public  A
//{
//public:
//	int _b;
//};
//
//class C :public B
//{
//public:
//	int _c;
//};


//菱形继承
//class B
//{
//public:
//	int _b;
//};
//class C1:virtual public B
//{
//public:
//	int _c1;
//};
//class C2:virtual public B
//{
//public:
//	int _c2;
//};
//class D :public  C1,public C2
//{
//public:
//	int _d;
//};


//class A
//{
//public:
//	int _a;
//};
//
//class B:virtual public A
//{
//public:
//	int _b;
//};
int main()
{
	/*B b;
	b._a = 1;
	b._b = 2;

	cout << "b:" << sizeof(b) << endl;*/
	//d._b = 1;//错误，对_b的访问不明确
	D d;
	C1 c1;
	c1._b = 8;
	C2 c2;
	c2._b = 9;

	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;




	

	//cout << "d:" << sizeof(d) << endl;
	/*c._a = 1;
	c._b = 2;
	c._c = 3;*/

	//cout << "c:" << sizeof(c) << endl;
	/*B b;
	b._a = 1;
	b._b = 2;
	cout << "b::" << sizeof(b) << endl;*/
	//B b;
	//C1 c1;
	//C2 c2;
	//D d;
	//B b;
	//b._b = 1;
	////d._b = 10;//错误，对_b调用不明确
	//d.C1::_b = 1;
	//d.C2::_b = 2;
	////d._b = 1;
	//d._c1 = 3;
	//d._c2 = 4;
	//d._d = 5;

	//M m;
	//m._a = 1;
	//m._m = 2;
	//
	//cout << "m :" << sizeof(m) << endl;

	//cout << "b :" << sizeof(b) << endl;
	//cout << "c1 :" << sizeof(c1) << endl;
	//cout << "c2 :" << sizeof(c2) << endl;
	//cout << "d :"<<sizeof(d) << endl;

	/*Person p;
	p.print();*/
	//Student s;
	//s.fun();
	//s.fun();

	//Der d;

	system("pause");
	return 0;
}