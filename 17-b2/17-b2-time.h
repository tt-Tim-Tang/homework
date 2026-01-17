//2453805 唐先泽 大数据
#pragma once

#include <iostream>
using namespace std;

/* 如果有其它全局函数需要声明，写于此处 */
bool is_valid_time(int h, int m, int s);
/* Time类的声明 */
class Time {
protected:
	/* 除这三个以外，不允许再定义任何数据成员 */
	int hour;
	int minute;
	int second;
public:
	/* 允许需要的成员函数及友元函数的声明 */
	Time();
	Time(int h, int m, int s);
	Time(int s); // 转换构造函数
	operator int() const; // 转换函数，转换为秒数
	Time& operator++();          // 前置++
	Time operator++(int);    // 后置++
	Time& operator--();          // 前置--
	Time operator--(int);    // 后置--
	int operator-(const Time& t) const;
	bool operator==(const Time& t) const;
	bool operator!=(const Time& t) const;
	bool operator<(const Time& t) const;
	bool operator<=(const Time& t) const;
	bool operator>(const Time& t) const;
	bool operator>=(const Time& t) const;
	void show() const;
	void set(int h = 0, int m = 0, int s = 0);
	void get(int& h, int& m, int& s);
	friend ostream& operator<<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);
	friend Time operator+(const Time& t, int n);
	friend Time operator+(int n, const Time& t);
	friend Time operator-(const Time& t, int n);
	/* 允许加入友元声明（如果有必要） */

};
