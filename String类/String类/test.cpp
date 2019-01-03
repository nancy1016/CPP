#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>




//void test1()
//{
//	string s1("hello");
//	cout << s1[0] << endl;
//	s1[0] = 'm';
//	cout << s1[0] << endl;
//}

//void test2()
//{
//	/*string s1("hello");
//	string s2("lala"); 
//	s2 += 'm';
//	cout << s2.c_str() << endl;*/
//	//s1.push_back('a');
//	//s1.append("lala");
//	//string s1("hello");
//	//string s2(s1,2,3);
//	//s1.append("hello",3);
//	//cout << s2 << endl;
//}


//void test3()
//{
//	/*string url("http://www.cplusplus.com/reference/string/string/npos/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	size_t finish = url.find('/', start + 3);
//	string addr = url.substr(start, finish - start);
//	cout << addr<< endl;
//	addr.erase(0, 3);
//	cout << addr << endl;*/
//
//	/*string s3("hello");
//	cout << s3.size() << endl;*/
//	//string s1("test.mm.cpp");
//	//int pos=s1.find('.');
//	//string s2 = s1.substr(s1.rfind('.')+1);
//	/*string s2("i");
//	string s3;
//	int ret=s1.rfind('i',5);
//	cout << ret << endl;*/
//}


class Solution
{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		//遍历字符串，将每一个字符的ascii码作为数组下标，统计每一个字符出现的次数
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i]] += 1;
		}
		
		//按照字符串字符的顺序从前往后遍历数组，找只出现一次的字符
		//s[i]是字符（有相对应的ascii码)
		//count[s[i]]===>count[ascii码]，值代表字符出现的次数
		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	string s("avab");
	Solution s1;
	int ret=s1.firstUniqChar(s);
	cout << ret << endl;
	//test3();
	//容量
	//string s1("hello");
	//string s2("world");
	//string s3;
	//cout << s1.max_size() << endl;
	/*cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s2.empty() << endl;*/
	//s2.clear();
	/*cout << s2.size() << endl;
	cout << s2.length() << endl;*/

	//测试resize与remove
	
	//s2.resize(7);
	//s2.resize(2, 'c');
	//cout << s2[5] << endl;


	//cout << s2.length() << endl;
	//cout << s2.capacity() << endl;
	//s2.resize(2);
	//s2.reserve(2);
	//s3.reserve(100);
	//s3.push_back('w');
	//s3.push_back('w');
	//cout << s2.length() << endl;
	//cout << s2.capacity() << endl;
	//cout << s3[1] << endl;
	//cout << s3[3] << endl;

	//s2.erase(s2.begin() + 1);

	/*string::iterator it1 = s2.begin();
	cout << *it1 << endl;

	string::iterator it2 = s2.end()-1;
	cout << *it2 << endl;
	s2.erase(1, 8);
	cout << s2 << endl;*/
	/*s1.push_back('w');
	s1.push_back('w');
	s1.push_back('w');
	cout << s1.capacity() << endl;*/

	//构造函数
	/*string s1;
	string s2("hello");
	string s5(s2);
	string s3("hello",3);
	string s4(3, 'h');*/
	system("pause");
	return 0;

}
