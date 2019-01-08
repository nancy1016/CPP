#include<iostream>
using namespace std;
#include<stdlib.h>
#include<vector>

//测试const与const_iterator修饰迭代器
void test1()
{
	vector<int> v;
	vector<int> v2(6, 15);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);
	const vector<int>::iterator it = v2.begin();//const修饰的是迭代器本身，即它不能再指向别的对象，相当于int*const p
	//*it = 1;//编译通过，迭代器中的内容可以改变
	//++it;//编译不通过，迭代器已被const修饰，不能指向其他对象

	const vector<int> v5(5, 13);
	vector<int>::const_iterator it2 = v2.begin();//const_iterator该类型只能用于读取容器内元素，但不能改变其值,相当于const int*p
	//*it2 = 3;//编译不通过
	++it2;//编译通过
}



//void test2()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//
//
//	vector<int>::iterator it = v.begin();
//	//vector<int>::iterator pos = find(v.begin(), v.end(), 2);
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		if (*it == 2)
//		{
//			v.erase(it);
//		}
//		++it;
//	}
//	
//
//	/*vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit <<" " <<&rit<< endl;
//		++rit;
//	}*/
//	
//	
//}

int find(int a[],int key)
{
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}
void move(int a[])
{
	for (int i = 1; i < 2; i++)
	{
		a[i] = a[i + 1];
	}
}



//void test3()
//{
//	vector<int> v;
//	int size = v.capacity();
//	cout << size << endl;
//	v.reserve(100);
//	for (int i = 0; i < 100; i++)
//	{
//		v.push_back(i);
//		/*if (size != v.capacity())
//		{
//			size = v.capacity();
//			cout << "capacity changed:" << size << endl;
//		}*/
//		cout << i << endl;
//		cout <<"size:"<<v.size()<< "capacity changed:" << v.capacity() << endl;
//	}
//	
//	//v.push_back(100);
//	//v.reserve(20);
//	cout << "size:" << v.size() << "capacity changed:" << v.capacity() << endl;
//	cout << "----------------" << endl;
//	
//	v.resize(5);
//	cout << "size:" << v.size() << "capacity changed:" << v.capacity() << endl;
//	v.resize(8,100);
//	cout << "size:" << v.size() << "capacity changed:" << v.capacity() << endl;
//	v.resize(200);
//}


//void test4()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 66);
//	//cout << *pos << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//
//
//	/*v.pop_back();
//	v.pop_back();*/
//	/*v.push_back(6);
//	v.push_back(7);
//	v.push_back(8);*/
//}


void test5()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	cout << *pos << endl;
	//v.resize(10);
	//cout << v.size() << endl;

	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}*/

	/*for (auto x : v)
	{
		cout << x << " ";
	}*/
	//cout << endl;
}



int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();

	int a[] = { 1, 2, 3 };
	
	int pos = find(a,2);
	int*begin = a;
	int*p = a;
	cout << a << endl;
	int*end = p + 3;
	p = &a[pos];
	/*for (int i = pos; i < 2; i++)
	{
		a[i] = a[i + 1];
	}
	++p;*/



	for (p = &a[pos]; p!=end; ++p)
	{
		move(a);
		//++p;
	}


	//int arr[] = { 5,6,7};
	//const int*p = arr;
	//p++;

	//int*const pp = arr;
	//*pp = 1;
	//pp++;
	//++it;

	/*while (it != v2.end())
	{
		cout << *it <<" ";
		++it;
	}*/
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	system("pause");
	return 0;
}