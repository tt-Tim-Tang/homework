//2453805 唐先泽 大数据
#include <iostream>
#include <iomanip>
#include "17-b2-time.h"
using namespace std;

/* --- 给出Time类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */

bool is_valid_time(int h, int m, int s) {
	if (h < 0 || h > 23) {
		return false;
	}
	if (m < 0 || m > 59) {
		return false;
	}
	if (s < 0 || s > 59) {
		return false;
	}
	return true;
}

Time::Time() {
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int h, int m, int s) {
	if (is_valid_time(h, m, s)) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		hour = 0;
		minute = 0;
		second = 0;
	}
}

Time::Time(int s) {
	s = s % 86400;
	if (s < 0) {
		s += 86400;
	}
	hour = s / 3600;
	minute = (s % 3600) / 60;
	second = s % 60;
}

Time::operator int() const {
	return hour * 3600 + minute * 60 + second;
}

void Time::show() const {
	cout << setfill('0') << setw(2) << hour << ":"
		<< setfill('0') << setw(2) << minute << ":"
		<< setfill('0') << setw(2) << second << setfill(' ') << endl;
}

void Time::set(int h, int m, int s) {
	if(is_valid_time(h, m, s)) {
		hour = h;
		minute = m;
		second = s;
	} 
	else {
		hour = 0;
		minute = 0;
		second = 0;
	}
}

void Time::get(int& h, int& m, int& s) {
	h = hour;
	m = minute;
	s = second;
}

ostream& operator<<(ostream& out, const Time& t) {
	out << setfill('0') << setw(2) << t.hour << ":"
		<< setfill('0') << setw(2) << t.minute << ":"
		<< setfill('0') << setw(2) << t.second << setfill(' ');
	return out;
}

istream & operator>>(istream& in, Time& t) {
	int h, m, s;
	in >> h >> m >> s;
	if (is_valid_time(h, m, s)) {
		t.hour = h;
		t.minute = m;
		t.second = s;
		return in;
	}
	else {
		t.hour = 0;
		t.minute = 0;
		t.second = 0;
		return in;
	}
}

bool Time::operator==(const Time& t) const {
	return (hour == t.hour) && (minute == t.minute) && (second == t.second);
}

bool Time::operator!=(const Time& t) const {
	return !(*this == t);
}

bool Time::operator<(const Time& t) const {
	return int(*this) < int(t);
}

bool Time::operator<=(const Time& t) const {
	return int(*this) <= int(t);
}

bool Time::operator>(const Time& t) const {
	return int(*this) > int(t);
}

bool Time::operator>=(const Time& t) const {
	return int(*this) >= int(t);
}

Time operator+(const Time& t, int n) {
	return Time(int(t) + n);
}
Time operator+(int n, const Time& t) {
	return Time(int(t) + n);
}
Time operator-(const Time& t, int n) {
	return Time(int(t) - n);
}

Time& Time::operator++() // 前置++
{
	*this = *this + 1;
	return *this;
}

Time Time::operator++(int) // 后置++
{
	Time temp = *this;
	*this = *this + 1;
	return temp;
}

Time& Time::operator--() // 前置--
{
	*this = *this - 1;
	return *this;
}

Time Time::operator--(int) // 后置--
{
	Time temp = *this;
	*this = *this - 1;
	return temp;
}

int Time::operator-(const Time& t) const {
	return int(*this) - int(t);
}