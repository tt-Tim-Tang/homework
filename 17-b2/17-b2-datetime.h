//2453805 唐先泽 大数据
#pragma once

#include "17-b2-date.h"
#include "17-b2-time.h"

/* 如果有其它全局函数需要声明，写于此处 */

/* DateTime类的基本要求：
	1、不允许定义任何数据成员
	2、尽量少定义成员函数
*/

class DateTime :public Date, public Time {
protected:
	/* 不允许再定义任何数据成员 */

public:
	/* 不允许再定义任何数据成员，允许需要的成员函数及友元函数的声明 */
	DateTime();
	DateTime(int y, int m, int d, int h, int min, int s);
	DateTime(long long s);
	void show() const;
	void set(int y = 1900, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0);
	void get(int& y, int& m, int& d, int& h, int& min, int& s);
	operator long long() const;
	DateTime operator+(long long n)const;
	DateTime operator+(int n)const;
	DateTime operator-(long long n)const;
	DateTime operator-(int n)const;
	long long operator-(const DateTime& dt) const;
	DateTime& operator++();          // 前置++
	DateTime operator++(int);    // 后置++
	DateTime& operator--();          // 前置--
	DateTime operator--(int);    // 后置--
	bool operator==(const DateTime& dt) const;
	bool operator!=(const DateTime& dt) const;
	bool operator<(const DateTime& dt) const;
	bool operator<=(const DateTime& dt) const;
	bool operator>(const DateTime& dt) const;
	bool operator>=(const DateTime& dt) const;
	friend DateTime operator+(long long n, const DateTime& dt);
	friend DateTime operator+(int n, const DateTime& dt);
	friend ostream& operator<<(ostream& out, const DateTime& dt);
	friend istream& operator>>(istream& in, DateTime& dt);
	/* 允许加入友元声明（如果有必要） */

};