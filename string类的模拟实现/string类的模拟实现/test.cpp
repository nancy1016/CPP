#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<assert.h>
//深拷贝
//方式一：传统版
//class String
//{
//public:
//	
//	//正确写法一：
//	/*String(const char*str="")
//	{
//		if (str == nullptr)
//		{
//			_str = new char[1];
//			*_str = '\0';
//		}
//		else
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//	}*/
//
//
//	//正确写法二：比一简单点
//	//好处：不用担心传入空指针问题
//	//当传入空指针和无参对象时，也开辟空间，一个字节（存放‘\0')
//	//当传入有参对象时，也要多开辟一个字节的空间，存放‘\0'
//	String(const char*str="")//注意这里是"",不是" ",它俩的长度不一样，第一个长度为0(因为里面存的是'\0')，第二个长度为1
//	{
//		if (str == nullptr)
//		{
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//当传入空指针时，开辟了1个char类型的空间，放\0
//		strcpy(_str, str);
//	}
//
//
//	//这种写法对String s1(nullptr)不适用,strlen(str)会出错，不能对空指针求字符串长度
//	//String(char*str="")
//	//	:_str(new char[strlen(str)+1])
//	//{
//	//	cout << "gouzao" << endl;
//	//	strcpy(_str, str);
//	//	//_str[strlen(str)] = '\0';
//	//}
//
//
//
//	//拷贝构造
//	String(String&s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//
//	//赋值运算符重载 以为例A=B("hello")
//	//思路：A对象可能无参，无参对象构造时只开辟了一个char空间，存储'\0',那么B中内容直接strcpy拷贝给A时就会出问题
//	//所以，正确步骤为：
//	//（1）先开辟新空间char*ptr=new char[strlen(B的字符串长度)+1];
//	//（2）将B中的字符串拷贝到ptr指向的空间中
//	//（3）释放A对象指针指向的旧空间
//	//（4）将A对象中指针所指的字符串空间指向为ptr(A._str=ptr)
//
//	//改进点：如果是自己给自己赋值，则不用那么麻烦，直接返回原对象
//	/*String&operator=(String&s)
//	{
//		if (this != &s)
//		{
//			char*ptr = new char[strlen(s._str) + 1];
//			strcpy(ptr, s._str);
//			delete[]_str;
//			_str = ptr;
//		}
//		return *this;
//	}*/
//
//
//	String&operator=(String&s)
//	{
//		if (this != &s)
//		{
//			delete[]_str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//
//	//析构函数
//	~String()
//	{
//		cout << "xigou" << this<<endl;
//		/*if (_str)
//		{
//			delete[]_str;
//		}
//		_str = nullptr;*/
//		delete[]_str;
//		_str = nullptr;
//	}
//private:
//	char*_str;
//};



//深拷贝简洁版
class String
{
public:
	//传参方式：
	//(1)无参（2）传入空指针（3）有参
	////////////////////////////////////////////
	
	//这种方式存在的问题：对于（1）无参 ，没有默认的构造函数可以调用
	/*String(char*str)
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}*/

	//这种方式存在的问题：对于（2）传入空指针 ,strlen(空指针)程序崩溃
	/*String(char*str="")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}*/


	//构造函数
	//正确书写方式
	//要考虑的点：传参方式->(1)无参（2）传入空指针（3）有参
	String(const char*str="")
	{
		if (str == nullptr)
		{
			str = "";//注意：这里不能写成_str="",一旦这样写，当传入空指针时，str变为空，strlen(str)会崩溃
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//拷贝构造
	//思路：构造一个临时对象tmp,参数为s._str。这里是调用的构造函数
	//注意要点：_str要初始化为空。因为当前对象的指针如果不初始化为空，则是个随机值，最后交换后，tmp中保存的就是这个随机值
	String(const String&s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//赋值运算符重载(简洁版)
	//思路：同样利用构造临时对象的方法，注意这里参数是s,调用的是拷贝构造函数
	//注意要点：（1）因为传的是引用，所以临时对象需要手动构建
	//(2)防止自己给自己赋值
	/*String&operator=(const String&s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(_str, tmp._str);
		}
		return *this;
	}*/

	//赋值运算符重载(最简洁版)
	//相比于上面(简洁版)，这个(最简洁版)的优点是：
	//(1)将构建临时对象的时机交给了编译器来做
	//(2)不用手动判断自己给自己赋值的问题，因为采用的是值拷贝，永远出现自己给自己赋值的情况
	String&operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()//这里不用判断_str是否为空，因为我们构造函数的处理，即使传入空指针，也不可能为空
	{
		delete[]_str;
		_str = nullptr;
	}
private:
	char*_str;
};


int main()
{
	String s0;
	String s1(nullptr);
	//String s2("hello");
	//String s3("world");
	//s2 = s2;
	//String s3("ww");
	//s2 = s2;
	//s1 = s3;
	/*char*p = "ab";
	int len = strlen(p);
	cout << len << endl;*/
	//system("pause");
	return 0;
}