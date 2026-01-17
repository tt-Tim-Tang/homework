//2453805 唐先泽 大数据
#pragma once

#include <iostream>
using namespace std;

/* 如果有其它全局函数需要声明，写于此处 */
bool is_leap_year(int year);
int days_in_month(int year, int month);
bool is_valid_date(int year, int month, int day);
/* Date类的声明 */
class Date {
protected:
	/* 除这三个以外，不允许再定义任何数据成员 */
	int year;
	int month;
	int day;
public:
	/* 允许需要的成员函数及友元函数的声明 */
	Date();
	Date(int y, int m, int d);
	Date(int d);
	void show() const;
	void set(int y, int m = 1, int d = 1);
	void get(int& y, int& m, int& d);
	operator int() const;
	Date& operator++();          // 前置++
	Date operator++(int);    // 后置++
	Date& operator--();          // 前置--
	Date operator--(int);    // 后置--
	int operator-(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	/* 允许加入友元声明（如果有必要） */
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	friend Date operator+(const Date& d, int n);
	friend Date operator+(int n, const Date& d);
	friend Date operator-(const Date& d, int n);
};