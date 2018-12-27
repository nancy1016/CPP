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
		//������ںϷ���
		if (!(_year > 0 && (_month > 0 &&_month<13)
			&& (_day>0 && _day <=getMonthday(_year, _month, _day))))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//��������
	Date(const Date&d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "kaoebeigouzao" << endl;
	}
	//��ֵ���������
	Date&operator=(const Date&d)
	{
		if (this != &d)//��ֹ�Լ����Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << "fuzhi" << endl;
		return *this;
	}

	//��������
	Date operator+(int days)
	{
		Date tmp(*this);
		tmp._day += days;
		int dayofmonth = getMonthday(_year, _month, _day);
		while (tmp._day > dayofmonth)
		{
			dayofmonth = getMonthday(tmp._year, tmp._month,tmp. _day);//��һ��һ��Ҫ�ӣ���Ϊ�ӵ��������࣬����ֿ�ü���������⣨���п��ܻ������꣩
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

	//��ȥ����
	//�ؼ��㣺����ǰһ���µ�����
	Date operator-(int days)
	{
		Date tmp(*this);
		tmp._day -= days;
		while (tmp._day <=0)
		{
			//int before_month = getMonthday(_year, _month-1, _day);//����ֱ����������ǰһ������������_monthΪ1��ʱ��_month-1����0�ˣ�����ȷ��Ӧ����12��
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

	
	//ǰ��++
	Date&operator++()
	{
		_day += 1;
		int dayofmonth = getMonthday(_year, _month, _day);
		if (_day > dayofmonth)
		{
			_day = _day - dayofmonth;//����һ��Ҫע����㵱ǰ������
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
	//����++
	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		int dayofmonth = getMonthday(_year, _month, _day);
		if (_day > dayofmonth)
		{
			_day = _day - dayofmonth;//����һ��Ҫע����㵱ǰ������
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
	//ǰ��--
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
	//����--
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
	//>����
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
	//<����
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
	//==����
	bool operator==(Date&d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//!=����
	bool operator!=(Date&d)
	{
		if (!(_year == d._year&&_month == d._month&&_day == d._day))
		{
			return true;
		}
		return false;
	}
	
	//>=����
	bool operator>=(Date&d)
	{
		return (!operator<(d));
	}
	//<=����
	bool operator<=(Date&d)
	{
		return (!operator>(d));
	}

	//��������֮����������
	//˼·�����ý�С�������ۼ�ֱ�����ڽϴ�����
	//(1)�����ж�˭�ǽ�С����
	//(2)����һ��������������С�����ڲ����ۼӣ�ͬʱ�����ۼӵĴ�����ֱ�����ڽϴ�����
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
	//�ж�����
	int isLeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 1;
		}
		return 0;
	}
	//��ȡÿ�µ�����
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


//����<<
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