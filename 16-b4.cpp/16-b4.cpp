//2453805 唐先泽 大数据
#include <iostream>
#include "16-b4.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */

/* 如果有需要的其它全局函数的实现，可以写于此处 */
Date::Date() {
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	// 范围1900.1.1-2099.12.31
	// 年非法，用2000替代
	if (year < 1900 || year > 2099) {
		year = 2000;
	}
	// 月非法，用1替代
	if (month < 1 || month > 12) {
		month = 1;
	}
	// 日非法，用1替代
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// 闰年2月29天
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (day < 1 || day > days_in_month[month - 1]) {
		day = 1;
	}
}

void Date::show() const {
	cout << year << "年" << month << "月" << day << "日" << endl;
}

void Date::set(int y, int m, int d) {
	if (y != 0) {
		year = y;
	}

	if (year < 1900 || year > 2099) {
		year = 2000;
	}

	if (m != 0) {
		month = m;
	}

	if (month < 1 || month > 12) {
		month = 1;
	}

	if (d != 0) {
		day = d;
	}
	
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (day < 1 || day > days_in_month[month - 1]) {
		day = 1;
	}

}

void Date::get(int& y, int& m, int& d) {
	y = year;
	m = month;
	d = day;
}

ostream& operator<<(ostream& out, const Date& d) {
	out<< d.year << "年" << d.month << "月" << d.day << "日";
	return out;
}

istream& operator>>(istream& in, Date& d) {
	in >> d.year >> d.month >> d.day;
	if (d.year < 1900 || d.year > 2099) {
		d.year = 2000;
	}
	// 月非法，用1替代
	if (d.month < 1 || d.month > 12) {
		d.month = 1;
	}
	// 日非法，用1替代
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// 闰年2月29天
	if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (d.day < 1 || d.day > days_in_month[d.month - 1]) {
		d.day = 1;
	}
	return in;
}

Date::Date(int d) {
	if (d <= 1) {
		year = 1900;
		month = 1;
		day = 1;
	}
	else if (d >= 73049) {
		year = 2099;
		month = 12;
		day = 31;
	}
	else {
		year = 1900;
		while(d > 0) {
			// 判断闰年
			int day_in_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 366 : 365;
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
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			days_in_month[1] = 29;
		}
		while( d > days_in_month[month - 1]) {
			d -= days_in_month[month - 1];
			month++;
		}

		day = d;
	}
}

Date::operator int() const{
	int days = 0;
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int y = 1900; y < year; ++y) {
		// 判断闰年
		days += (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 366 : 365;
	}
	for (int m = 1; m < month; ++m) {
		// 判断闰年
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			days_in_month[1] = 29;
		}
		else {
			days_in_month[1] = 28;
		}
		days += days_in_month[m - 1];
	}
	days += day;
	return days;
}

Date operator+(const Date& d, int n) {
	return Date(int(d) + n);
}

Date operator+(int n, const Date& d) {
	return Date(int(d) + n);
}

Date operator-(const Date& d, int n) {
	return Date(int(d) - n);
}

int Date::operator-(const Date& d) const {
	return int(*this) - int(d);
}

Date& Date::operator++() { // 前缀++
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int) { // 后缀++
	Date temp = *this;
	*this = *this + 1;
	return temp;
}

Date& Date::operator--() { // 前缀--
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int) { // 后缀--
	Date temp = *this;
	*this = *this - 1;
	return temp;
}