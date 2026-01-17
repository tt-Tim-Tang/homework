//2453805 唐先泽 大数据
#include <iostream>
#include <iomanip>
#include "17-b2-datetime.h"
using namespace std;

/* --- 给出DateTime类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */
const long long MAX_SEC = 73049LL * 86400LL; // 从1900-01-01 00:00:00到2099-12-31 23:59:59的总秒数

bool is_valid_datetime(int y, int mo, int d, int h, int mi, int s) {
	return is_valid_date(y, mo, d) && is_valid_time(h, mi, s);
}

DateTime::DateTime() :Date(), Time() 
{
}

DateTime::DateTime(int y, int m, int d, int h, int min, int s)
{
	if(is_valid_datetime(y, m, d, h, min, s)) {
		year = y;
		month = m;
		day = d;
		hour = h;
		minute = min;
		second = s;
	}
	else {
		year = 1900;
		month = 1;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
	}
}

DateTime::DateTime(long long s):Date((int)(((s% MAX_SEC + MAX_SEC) % MAX_SEC) / 86400LL)),
Time((int)(((s% MAX_SEC + MAX_SEC) % MAX_SEC) % 86400LL))
{
}

void DateTime::show() const
{
	cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << setfill(' ')<< " "
		<< setfill('0') << setw(2) << hour << ":"
		<< setfill('0') << setw(2) << minute << ":"
		<< setfill('0') << setw(2) << second << setfill(' ') << endl;
}

void DateTime::set(int y, int m, int d, int h, int min, int s)
{
	Date::set(y, m, d);
	Time::set(h, min, s);
}	

void DateTime::get(int& y, int& m, int& d, int& h, int& min, int& s)
{
	Date::get(y, m, d);
	Time::get(h, min, s);
}

DateTime::operator long long() const
{
	long long total_days = Date::operator int(); // 转换为天数
	long long total_seconds = Time::operator int(); // 转换为秒数
	return total_days * 86400LL + total_seconds;
}

ostream& operator<<(ostream& out, const DateTime& dt)
{
	out << dt.year << "-" << setfill('0') << setw(2) << dt.month << "-" << setfill('0') << setw(2) << dt.day << setfill(' ') << " "
		<< setfill('0') << setw(2) << dt.hour << ":"
		<< setfill('0') << setw(2) << dt.minute << ":"
		<< setfill('0') << setw(2) << dt.second << setfill(' ') ;
	return out;
}



istream& operator>>(istream& in, DateTime& dt)
{
	int y, m, d, h, min, s;
	in >> y >> m >> d >> h >> min >> s;
	if(is_valid_datetime(y, m, d, h, min, s)) {
		dt.year = y;
		dt.month = m;
		dt.day = d;
		dt.hour = h;
		dt.minute = min;
		dt.second = s;
	}
	else {
		dt.year = 1900;
		dt.month = 1;
		dt.day = 1;
		dt.hour = 0;
		dt.minute = 0;
		dt.second = 0;
	}
	return in;
}

DateTime DateTime::operator+(long long n) const
{
	return DateTime(static_cast<long long>(*this) + n);
}

DateTime DateTime::operator+(int n) const
{
	return DateTime(static_cast<long long>(*this) + n);
}

DateTime DateTime::operator-(long long n) const
{
	return DateTime(static_cast<long long>(*this) - n);
}

DateTime DateTime::operator-(int n) const
{
	return DateTime(static_cast<long long>(*this) - n);
}

DateTime& DateTime::operator++() // 前置++
{
	*this = *this + 1LL;
	return *this;
}

DateTime DateTime::operator++(int) // 后置++
{
	DateTime temp = *this;
	*this = *this + 1LL;
	return temp;
}

DateTime& DateTime::operator--() // 前置--
{
	*this = *this - 1LL;
	return *this;
}

DateTime DateTime::operator--(int) // 后置--
{
	DateTime temp = *this;
	*this = *this - 1LL;
	return temp;
}

bool DateTime::operator==(const DateTime& dt) const
{
	return static_cast<long long>(*this) == static_cast<long long>(dt);
}

bool DateTime::operator!=(const DateTime& dt) const
{
	return !(*this == dt);
}

bool DateTime::operator<(const DateTime& dt) const
{
	return static_cast<long long>(*this) < static_cast<long long>(dt);
}

bool DateTime::operator<=(const DateTime& dt) const
{
	return static_cast<long long>(*this) <= static_cast<long long>(dt);
}

bool DateTime::operator>(const DateTime& dt) const
{
	return static_cast<long long>(*this) > static_cast<long long>(dt);
}

bool DateTime::operator>=(const DateTime& dt) const
{
	return static_cast<long long>(*this) >= static_cast<long long>(dt);
}

DateTime operator+(long long n, const DateTime& dt)
{
	return DateTime(static_cast<long long>(dt) + n);
}

DateTime operator+(int n, const DateTime& dt)
{
	return DateTime(static_cast<long long>(dt) + n);
}

long long DateTime::operator-(const DateTime& dt) const
{
	return static_cast<long long>(*this) - static_cast<long long>(dt);
}