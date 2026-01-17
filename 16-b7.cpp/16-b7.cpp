//2453805 唐先泽 大数据
#include <iostream>
#include<string>
#include "16-b7.h"
using namespace std;

ostream& operator<<(ostream& out, const week& d)
{
	switch (d)
	{
	case sun:
		out << "星期日";
		break;
	case mon:
		out << "星期一";
		break;
	case tue:
		out << "星期二";
		break;
	case wed:
		out << "星期三";
		break;
	case thu:
		out << "星期四";
		break;
	case fri:
		out << "星期五";
		break;
	case sat:
		out << "星期六";
		break;
	default:
		out << "错误";
		break;
	}
	return out;
}


string to_lower(const string& str)
{
	string result;
	for (char ch : str) {
		if(ch >= 'A' && ch <= 'Z') {
			result += ch + ('a' - 'A');
		} else {
			result += ch;
		}
	}
	return result;
}

istream& operator>>(istream& in, week& d)
{
	string str;
	in >> str;
	str = to_lower(str);
	if (str == "sun") {
		d = sun;
	}
	else if(str == "mon") {
		d = mon;
	}
	else if (str == "tue") {
		d = tue;
	}
	else if (str == "wed") {
		d = wed;
	}
	else if (str == "thu") {
		d = thu;
	}
	else if (str == "fri") {
		d = fri;
	}
	else if (str == "sat") {
		d = sat;
	}
	else {
		d = static_cast<week>(-1); // 错误值
	}
	return in;
}

// 前缀++
week& operator++(week& d)
{
	int val = (int)d;
	val = (val + 1) % 7;
	d = static_cast<week>(val);
	return d;
}

// 后缀++
week operator++(week& d, int)
{
	week old = d;
	++d;
	return old;
}

// 前缀--
week& operator--(week& d)
{
	int val = (int)d;
	val = (val + 6) % 7;
	d = static_cast<week>(val);
	return d;
}

// 后缀--
week operator--(week& d, int)
{
	week old = d;
	--d;
	return old;
}

//重载+运算符
week operator+(const week& d, int n)
{
	int val = (int)d;
	val = (val + n) % 7;
	if (val < 0) {
		val += 7;
	}
	return static_cast<week>(val);
}

//重载-运算符
week operator-(const week& d, int n)
{
	int val = (int)d;
	val = (val - n) % 7;
	if (val < 0) {
		val += 7;
	}
	return static_cast<week>(val);
}

// 重载+=运算符
week& operator+=(week& d, int n)
{
	int val = (int)d;
	val = (val + n) % 7;
	if (val < 0) {
		val += 7;
	}
	d = static_cast<week>(val);
	return d;
}

// 重载-=运算符
week& operator-=(week& d, int n)
{
	int val = (int)d;
	val = (val - n) % 7;
	if (val < 0) {
		val += 7;
	}
	d = static_cast<week>(val);
	return d;
}
