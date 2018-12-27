#include<iostream>
using namespace std;
#include<stdlib.h>
class Date
{
	friend ostream& operator<< (ostream&_cout, const Date&d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		//检测日期合法性
		if (!(_year > 0 && (_month > 0 &&_month<13)
			&& (_day>0 && _day <=getMonthday(_year, _month, _day))))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//拷贝构造
	Date(const Date&d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "kaoebeigouzao" << endl;
	}
	//赋值运算符重载
	Date&operator=(const Date&d)
	{
		if (this != &d)//防止自己给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << "fuzhi" << endl;
		return *this;
	}

	//加上天数
	Date operator+(int days)
	{
		Date tmp(*this);
		tmp._day += days;
		int dayofmonth = getMonthday(_year, _month, _day);
		while (tmp._day > dayofmonth)
		{
			dayofmonth = getMonthday(tmp._year, tmp._month,tmp. _day);//这一句一定要加，因为加的天数过多，会出现跨好几个年的问题（其中可能会有闰年）
			tmp._day -= dayofmonth;
			if (tmp._month == 12)
			{
				tmp._month = 1;
				tmp._year++;
			}
			else
			{
				tmp._month++;
			}
		}
		return tmp;
	}

	//减去天数
	//关键点：计算前一个月的天数
	Date operator-(int days)
	{
		Date tmp(*this);
		tmp._day -= days;
		while (tmp._day <=0)
		{
			//int before_month = getMonthday(_year, _month-1, _day);//不能直接这样计算前一个月天数，当_month为1月时，_month-1等于0了，而正确的应该是12月
			//tmp._day = tmp._day + before_month;
			if (tmp._month == 1)
			{
				tmp._month = 12;
				tmp._year--;
			}
			else
			{
				tmp._month--;
				
			}
			tmp._day = tmp._day + getMonthday(tmp._year, tmp._month, tmp._day);
		}
		return tmp;
	}

	
	//前置++
	Date&operator++()
	{
		_day += 1;
		int dayofmonth = getMonthday(_year, _month, _day);
		if (_day > dayofmonth)
		{
			_day = _day - dayofmonth;//这里一定要注意计算当前月天数
			if (_month == 12)
			{
				_month = 1;
				_year++;
			}
			else
			{
				_month++;
			}	
		}
		return *this;
	}
	//后置++
	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		int dayofmonth = getMonthday(_year, _month, _day);
		if (_day > dayofmonth)
		{
			_day = _day - dayofmonth;//这里一定要注意计算当前月天数
			if (_month == 12)
			{
				_month = 1;
				_year++;
			}
			else
			{
				_month++;
			}
		}
		return tmp;
	}
	//前置--
	Date&operator--()
	{
		_day -= 1;
		if (_day <= 0)
		{
			if (_month == 1)
			{
				_month = 12;
				_year--;
			}
			else
			{
				_month--;
			}
			_day = _day + getMonthday(_year, _month, _day);
		}
		return *this;
	}
	//后置--
	Date operator--(int)
	{
		Date tmp(*this);
		_day -= 1;
		if (_day <= 0)
		{
			if (_month == 1)
			{
				_month = 12;
				_year--;
			}
			else
			{
				_month--;
			}
			_day = _day + getMonthday(_year, _month, _day);
		}
		return tmp;
	}
	//>重载
	bool operator>(Date&d)
	{
		if ((_year > d._year) || (_year == d._year&&_month > d._month) || (_year == d._year&&_month == d._month&&_day > d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//<重载
	bool operator<(Date&d)
	{
		if ((_year < d._year) || (_year == d._year&&_month < d._month) || (_year == d._year&&_month == d._month&&_day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//==重载
	bool operator==(Date&d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//!=重载
	bool operator!=(Date&d)
	{
		if (!(_year == d._year&&_month == d._month&&_day == d._day))
		{
			return true;
		}
		return false;
	}
	
	//>=重载
	bool operator>=(Date&d)
	{
		return (!operator<(d));
	}
	//<=重载
	bool operator<=(Date&d)
	{
		return (!operator>(d));
	}

	//两个日期之间相差的天数
	//思路：利用较小日期逐渐累加直到等于较大日期
	//(1)首先判断谁是较小日期
	//(2)设置一个计数器，将较小的日期不断累加，同时记下累加的次数，直到等于较大日期
	int operator-( Date&d)
	{
		Date& min = *this;
		Date& max = d;
		int count = 0;
		if (*this >d)
		{
			min = d;
			max = *this;
		}
		while (min != max)
		{
			min++;
			count++;
		}
		return count;
	}
private:
	//判断闰年
	int isLeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 1;
		}
		return 0;
	}
	//获取每月的天数
	int getMonthday(int year, int month, int day)
	{
		int dayofMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (isLeapYear(year) == 1&&month==2)
		{
			dayofMonth[month] = 29;
		}
		return dayofMonth[month];
	}

	
private:
	int _year;
	int _month;
	int _day;
};


//重载<<
ostream& operator<< (ostream&_cout,const Date&d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int main()
{
	Date d1(2018,12,27);
	Date d2(2019, 3, 30);
	//cout<<d1<<d2;
	//Date d2(2018,1,23);
	//d1 != d2;
	//Date tmp=d1++;
	//d1 -666;
	//Date d2;
	//d2 = d1;
	//cout<<(d1 <= d2)<<endl;
	d1 - d2;
	system("pause");
	return 0;
}