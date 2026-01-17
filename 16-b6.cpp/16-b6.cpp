//2453805 唐先泽 大数据
#include <iostream>
#include "16-b6.h"
#include <string>
using namespace std;

ostream& operator<<(ostream& out,const week& d)
{
	switch (d)
	{
	case week::sun:
		out << "星期日";
		break;
	case week::mon:
		out << "星期一";
		break;
	case week::tue:
		out << "星期二";
		break;
	case week::wed:
		out << "星期三";
		break;
	case week::thu:
		out << "星期四";
		break;
	case week::fri:
		out << "星期五";
		break;
	case week::sat:
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
		d = week::sun;
	}
	else if(str == "mon") {
		d = week::mon;
	}
	else if (str == "tue") {
		d = week::tue;
	}
	else if (str == "wed") {
		d = week::wed;
	}
	else if (str == "thu") {
		d = week::thu;
	}
	else if (str == "fri") {
		d = week::fri;
	}
	else if (str == "sat") {
		d = week::sat;
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

// 重载+
week operator+(const week& d, int n)
{
	int val = (int)d;
	val = (val + n) % 7;
	if (val < 0) {
		val += 7;
	}
	return static_cast<week>(val);
}

// 重载-
week operator-(const week& d, int n)
{
	int val = (int)d;
	val = (val - n) % 7;
	if (val < 0) {
		val += 7;
	}
	return static_cast<week>(val);
}

// 重载+=
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

// 重载-=
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