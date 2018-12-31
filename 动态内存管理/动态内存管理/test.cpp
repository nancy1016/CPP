#include<iostream>
using namespace std;
#include<stdlib.h>
//设计一个类，该类只能在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly*create_obj()
//	{
//		HeapOnly* p;
//		p = new HeapOnly;
//		return p;	
//	}
//	/*HeapOnly(HeapOnly&hp)
//	{
//		cout << "kaobei" << endl;
//	}*/
//
//	
//	//HeapOnly(const HeapOnly&) = delete;//C++11中禁止外部用户调用拷贝构造函数
//private:
//	//int _a;
//	/*HeapOnly()
//	{}*/
//
//	//HeapOnly(const HeapOnly&);//C++98中禁止外部用户调用拷贝构造函数
//};
//
//
//
//int main()
//{
//	//HeapOnly d;
//	//HeapOnly* d = HeapOnly::create_obj();
//	//HeapOnly d2(*d);
//	//HeapOnly d();
//	system("pause");
//	return 0;
//}




//定位new表达式
//在已经存在的空间上执行构造函数
//class Test
//{
//public:
//	Test()
//	{
//		cout << "Test()" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test()" << this << endl;
//	}
//private:
//
//};
//
//void*allocate(size_t size)
//{
//	return malloc(size);
//}
//
//int main()
//{
//	Test*pt = (Test*)allocate(sizeof(Test));
//	new(pt)Test;//new(地址）类型构造函数
//	system("pause");
//	return 0;
//}



//设计一个类，该类只能在栈上创建对象
//class StackOnly
//{
//public:
//	static StackOnly OnCreateInstrance(int param)
//	{
//		return StackOnly(param);
//	}
//
//private:
//	StackOnly(int param)
//	{}
//	void*operator new(size_t size);
//	void operator delete(void*);
//};
//
//void*operator new(size_t size,char*name)
//{
//	return malloc(size);
//}

//StackOnly t;




//int main()
//{
//
//
//	//StackOnly d;
//	//StackOnly*p = new StackOnly;
//	
//	//StackOnly*pt = (StackOnly*)malloc(sizeof(StackOnly));
//	//new(pt)StackOnly;
//
//	//StackOnly t;
//	//StackOnly o (StackOnly:: OnCreateInstrance(10));
//	system("pause");
//	return 0;
//}


//自己写的：只能在栈上创建对象
//思考的几个要点：
//（1）只能在栈，说明不能在堆上创建，考虑堆上创建对象的两种方法-->new和定位new表达式,原理-->先调用operator new开空间,然后执行构造函数
//所以屏蔽掉operator new（即放成私有）这样就排斥了直接new和定位new表达式
//注意：上面的方法只能排斥掉在堆上创建，但是在全局区仍然可以
//（2）防止在全局区创建：构造函数设为私有（但这样一来在栈上直接创建也不行了）
//解决办法：提供一个接口,创建栈上的对象（存在问题：成员只能用对象调用，但是栈上的对象都创建不出）
//(解决办法->)将这个接口设为静态的，这样就不依赖于对象调用

class StackOnly
{
public:
	static StackOnly CreateStackobj()
	{
		return  StackOnly();
	}
private:
	StackOnly()
	{
	}

	void*operator new(size_t size);
	void operator delete(void*p);
};

//StackOnly p;
int main()
{
	//StackOnly*p = (StackOnly*)malloc(sizeof(StackOnly));
	//new(p)StackOnly;//定位new表达式
	//StackOnly*pt = new StackOnly;
	//StackOnly p;//在栈上创建
	StackOnly::CreateStackobj();//通过调用静态方法创建
	system("pause");
	return 0;
}




//自己写的：只能在堆上创建对象
//思路：说明不能在栈上创建对象，考虑到栈上创建对象会发生哪些事：
//(1)构造函数（2）拷贝构造 
//所以先屏蔽掉构造函数，即设为私有。存在问题：在堆上创建对象也会调用构造函数，设为私有对其有影响
//解决：提供成员函数接口，在成员函数中创建堆对象。存在问题：成员函数需要对象来调用，现在无法创建对象
//解决办法：设为静态成员函数，这样就不依赖于对象调用
//以上基本解决一般情况，但是还存在一些问题：（1）利用堆上创建的对象进行拷贝构造，构造出的对象是栈上的
//解决办法：在拷贝构造也要写成私有
//对于全局对象，也构建不出来，满足题意
//class HeapOnly
//{
//public:
//	static HeapOnly*CreateHeapobj()//提供创建堆对象的接口
//	{
//		HeapOnly*p = new HeapOnly;
//		return p;
//	}
//	
//private:
//	HeapOnly()
//	{
//
//	}
//	HeapOnly(HeapOnly&hp);
//};
//
////HeapOnly p;
//int main()
//{
//	//HeapOnly h;
//	//HeapOnly*p = new HeapOnly;
//	//HeapOnly*pt = HeapOnly::CreateHeapobj();
//	//HeapOnly h(*pt);//利用堆上创建的对象拷贝构造
//	system("pause");
//	return 0;
//}