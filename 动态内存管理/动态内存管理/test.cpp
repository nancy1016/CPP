#include<iostream>
using namespace std;
#include<stdlib.h>
//���һ���࣬����ֻ���ڶ��ϴ�������
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
//	//HeapOnly(const HeapOnly&) = delete;//C++11�н�ֹ�ⲿ�û����ÿ������캯��
//private:
//	//int _a;
//	/*HeapOnly()
//	{}*/
//
//	//HeapOnly(const HeapOnly&);//C++98�н�ֹ�ⲿ�û����ÿ������캯��
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




//��λnew���ʽ
//���Ѿ����ڵĿռ���ִ�й��캯��
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
//	new(pt)Test;//new(��ַ�����͹��캯��
//	system("pause");
//	return 0;
//}



//���һ���࣬����ֻ����ջ�ϴ�������
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


//�Լ�д�ģ�ֻ����ջ�ϴ�������
//˼���ļ���Ҫ�㣺
//��1��ֻ����ջ��˵�������ڶ��ϴ��������Ƕ��ϴ�����������ַ���-->new�Ͷ�λnew���ʽ,ԭ��-->�ȵ���operator new���ռ�,Ȼ��ִ�й��캯��
//�������ε�operator new�����ų�˽�У��������ų���ֱ��new�Ͷ�λnew���ʽ
//ע�⣺����ķ���ֻ���ų���ڶ��ϴ�����������ȫ������Ȼ����
//��2����ֹ��ȫ�������������캯����Ϊ˽�У�������һ����ջ��ֱ�Ӵ���Ҳ�����ˣ�
//����취���ṩһ���ӿ�,����ջ�ϵĶ��󣨴������⣺��Աֻ���ö�����ã�����ջ�ϵĶ��󶼴���������
//(����취->)������ӿ���Ϊ��̬�ģ������Ͳ������ڶ������

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
	//new(p)StackOnly;//��λnew���ʽ
	//StackOnly*pt = new StackOnly;
	//StackOnly p;//��ջ�ϴ���
	StackOnly::CreateStackobj();//ͨ�����þ�̬��������
	system("pause");
	return 0;
}




//�Լ�д�ģ�ֻ���ڶ��ϴ�������
//˼·��˵��������ջ�ϴ������󣬿��ǵ�ջ�ϴ�������ᷢ����Щ�£�
//(1)���캯����2���������� 
//���������ε����캯��������Ϊ˽�С��������⣺�ڶ��ϴ�������Ҳ����ù��캯������Ϊ˽�ж�����Ӱ��
//������ṩ��Ա�����ӿڣ��ڳ�Ա�����д����Ѷ��󡣴������⣺��Ա������Ҫ���������ã������޷���������
//����취����Ϊ��̬��Ա�����������Ͳ������ڶ������
//���ϻ������һ����������ǻ�����һЩ���⣺��1�����ö��ϴ����Ķ�����п������죬������Ķ�����ջ�ϵ�
//����취���ڿ�������ҲҪд��˽��
//����ȫ�ֶ���Ҳ��������������������
//class HeapOnly
//{
//public:
//	static HeapOnly*CreateHeapobj()//�ṩ�����Ѷ���Ľӿ�
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
//	//HeapOnly h(*pt);//���ö��ϴ����Ķ��󿽱�����
//	system("pause");
//	return 0;
//}