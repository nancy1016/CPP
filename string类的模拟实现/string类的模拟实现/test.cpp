#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<assert.h>
//���
//��ʽһ����ͳ��
//class String
//{
//public:
//	
//	//��ȷд��һ��
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
//	//��ȷд��������һ�򵥵�
//	//�ô������õ��Ĵ����ָ������
//	//�������ָ����޲ζ���ʱ��Ҳ���ٿռ䣬һ���ֽڣ���š�\0')
//	//�������вζ���ʱ��ҲҪ�࿪��һ���ֽڵĿռ䣬��š�\0'
//	String(const char*str="")//ע��������"",����" ",�����ĳ��Ȳ�һ������һ������Ϊ0(��Ϊ��������'\0')���ڶ�������Ϊ1
//	{
//		if (str == nullptr)
//		{
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//�������ָ��ʱ��������1��char���͵Ŀռ䣬��\0
//		strcpy(_str, str);
//	}
//
//
//	//����д����String s1(nullptr)������,strlen(str)��������ܶԿ�ָ�����ַ�������
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
//	//��������
//	String(String&s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//
//	//��ֵ��������� ��Ϊ��A=B("hello")
//	//˼·��A��������޲Σ��޲ζ�����ʱֻ������һ��char�ռ䣬�洢'\0',��ôB������ֱ��strcpy������Aʱ�ͻ������
//	//���ԣ���ȷ����Ϊ��
//	//��1���ȿ����¿ռ�char*ptr=new char[strlen(B���ַ�������)+1];
//	//��2����B�е��ַ���������ptrָ��Ŀռ���
//	//��3���ͷ�A����ָ��ָ��ľɿռ�
//	//��4����A������ָ����ָ���ַ����ռ�ָ��Ϊptr(A._str=ptr)
//
//	//�Ľ��㣺������Լ����Լ���ֵ��������ô�鷳��ֱ�ӷ���ԭ����
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
//	//��������
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



//�������
class String
{
public:
	//���η�ʽ��
	//(1)�޲Σ�2�������ָ�루3���в�
	////////////////////////////////////////////
	
	//���ַ�ʽ���ڵ����⣺���ڣ�1���޲� ��û��Ĭ�ϵĹ��캯�����Ե���
	/*String(char*str)
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}*/

	//���ַ�ʽ���ڵ����⣺���ڣ�2�������ָ�� ,strlen(��ָ��)�������
	/*String(char*str="")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}*/


	//���캯��
	//��ȷ��д��ʽ
	//Ҫ���ǵĵ㣺���η�ʽ->(1)�޲Σ�2�������ָ�루3���в�
	String(const char*str="")
	{
		if (str == nullptr)
		{
			str = "";//ע�⣺���ﲻ��д��_str="",һ������д���������ָ��ʱ��str��Ϊ�գ�strlen(str)�����
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//��������
	//˼·������һ����ʱ����tmp,����Ϊs._str�������ǵ��õĹ��캯��
	//ע��Ҫ�㣺_strҪ��ʼ��Ϊ�ա���Ϊ��ǰ�����ָ���������ʼ��Ϊ�գ����Ǹ����ֵ����󽻻���tmp�б���ľ���������ֵ
	String(const String&s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//��ֵ���������(����)
	//˼·��ͬ�����ù�����ʱ����ķ�����ע�����������s,���õ��ǿ������캯��
	//ע��Ҫ�㣺��1����Ϊ���������ã�������ʱ������Ҫ�ֶ�����
	//(2)��ֹ�Լ����Լ���ֵ
	/*String&operator=(const String&s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(_str, tmp._str);
		}
		return *this;
	}*/

	//��ֵ���������(�����)
	//���������(����)�����(�����)���ŵ��ǣ�
	//(1)��������ʱ�����ʱ�������˱���������
	//(2)�����ֶ��ж��Լ����Լ���ֵ�����⣬��Ϊ���õ���ֵ��������Զ�����Լ����Լ���ֵ�����
	String&operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()//���ﲻ���ж�_str�Ƿ�Ϊ�գ���Ϊ���ǹ��캯���Ĵ�����ʹ�����ָ�룬Ҳ������Ϊ��
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