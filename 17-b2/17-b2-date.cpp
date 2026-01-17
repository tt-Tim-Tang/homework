//2453805 唐先泽 大数据
#include <iostream>
#include <iomanip>
#include "17-b2-date.h"
using namespace std;

/* --- 给出Date类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */

bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month)
{
	if(month == 2) {
		return is_leap_year(year) ? 29 : 28;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

bool is_valid_date(int year, int month, int day) {
	if (year < 1900 || year > 2099) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	int dim = days_in_month(year, month);
	if (day < 1 || day > dim) {
		return false;
	}
	return true;
}

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	if(is_valid_date(y, m, d)) {
		year = y;
		month = m;
		day = d;
	} 
	else {
		year = 1900;
		month = 1;
		day = 1;
	}
}

Date::Date(int d)
{
	while (d < 0) {
		d += 73049;
	}

	d = d % 73049 + 1; // 有效d的范围是1~73049

	year = 1900;
	while(d > 0) {
		int day_in_year = is_leap_year(year) ? 366 : 365;
		if (d > day_in_year) {
			d -= day_in_year;
			year++;
		}
		else {
			break;
		}
	}
	month = 1;
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (is_leap_year(year)) {
		days_in_month[1] = 29;
	}
	while( d > days_in_month[month - 1]) {
		d -= days_in_month[month - 1];
		month++;
	}
	day = d;

}

void Date::show() const
{
	cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << setfill(' ') << endl;
}

void Date::set(int y, int m, int d)
{
	if(is_valid_date(y, m, d)) {
		year = y;
		month = m;
		day = d;
	} 
	else {
		year = 1900;
		month = 1;
		day = 1;
	}
}

void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

Date::operator int() const
{
	int days = 0;
	for (int y = 1900; y < year; ++y) {
		days += is_leap_year(y) ? 366 : 365;
	}
	for (int m = 1; m < month; ++m) {
		days += days_in_month(year, m);
	}
	days += day;
	days -= 1;
	return days;
}





ostream& operator<<(ostream& out, const Date& d)
{
	out << d.year << "-" << setfill('0') << setw(2) << d.month << "-" << setfill('0') << setw(2) << d.day << setfill(' ');
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d.year >> d.month >> d.day;
	if (is_valid_date(d.year, d.month, d.day)) {
		return in;
	}
	else {
		d.year = 1900;
		d.month = 1;
		d.day = 1;
		return in;
	}
}

Date operator+(const Date& d, int n)
{
	return Date(int(d) + n);
}

Date operator+(int n, const Date& d)
{
	return Date(int(d) + n);
}

Date operator-(const Date& d, int n)
{
	return Date(int(d) - n);
}

Date& Date::operator++() // 前置++
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int) // 后置++
{
	Date temp = *this;
	*this = *this + 1;
	return temp;
}
Date& Date::operator--() // 前置--
{
	*this = *this - 1;
	return *this;
}	
Date Date::operator--(int) // 后置--
{
	Date temp = *this;
	*this = *this - 1;
	return temp;
}

bool Date::operator==(const Date& d) const
{
	return (year == d.year) && (month == d.month) && (day == d.day);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator<(const Date& d) const
{
	if((int)*this < (int)d) {
		return true;
	} 
	else {
		return false;
	}
}

bool Date::operator<=(const Date& d) const
{
	if ((int)*this <= (int)d) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator>(const Date& d) const
{
	if((int)*this > (int)d) {
		return true;
	} 
	else {
		return false;
	}
}

bool Date::operator>=(const Date& d) const
{
	if ((int)*this >= (int)d) {
		return true;
	}
	else {
		return false;
	}
}

int Date::operator-(const Date& d) const
{
	return int(*this) - int(d);
}