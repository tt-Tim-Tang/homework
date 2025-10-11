//2453805 唐先泽 电信
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

int is_leap(int year);
int month(int day_n, int year, int* p);
/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int y, int m, int d)
{
	if (y < 1900 || y > 2099) {
		year = 2000; // 年份不合法，设置为默认值
	}
	else {
		year = y;
	}

	if (m < 1 || m > 12) {
		month = 1;
	}
	else {
		month = m;
	}
	
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //每月的天数
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		a[1] = 29; //闰年二月有29天
	}
	else {
		a[1] = 28; //平年二月有28天
	}
	if (d < 1 || d > a[month - 1]) {
		day = 1; // 日不合法，设置为默认值
	}
	else {
		day = d;
	}
}
Date::Date(int d)
{
	if (d < 0) {
		year = 1900; // 如果天数小于0，设置为默认值
		month = 1;
		day = 1;
		return;
	}
	int d_temp = d; // 临时变量保存输入的天数
	year = 1900; // 默认年份
	while (d_temp >= 365) {
		if (is_leap(year) && d_temp >= 366) {
			d_temp -= 366;
			year++;
		}
		if (is_leap(year) && d_temp == 365) {
			break;
		}
		if (!is_leap(year) && d_temp >= 365) {
			d_temp -= 365;
			year++;
		}
	}
	int* p = &d_temp; // 指向剩余天数的指针
	month = ::month(d_temp, year, p); // 调用全局函数计算月份
	day = *p; 

	if (year > 2099) {
		year = 2099; // 如果年份超过2099，设置为默认值
		month = 12;
		day = 31; // 设置为12月31日
	}
}

void Date::set(int y, int m, int d)
{
	if (y == 0) {
		year = this->year; // 如果年份为0，保持原有年份
	}
	else {
		if (y < 1900 || y > 2099) {
			year = 2000; // 年份不合法，设置为默认值
		}
		else {
			year = y;
		}
	}


	if (m == 0) {
		month = this->month; // 如果月份为0，保持原有月份
	}
	else {
		if (m < 1 || m > 12) {
			month = 1; // 月份不合法，设置为默认值
		}
		else {
			month = m;
		}
	}



	if (d == 0) {
		day = this->day; // 如果日为0，保持原有日
	}
	else {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //每月的天数
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
			a[1] = 29; //闰年二月有29天
		}
		else {
			a[1] = 28; //平年二月有28天
		}
		if (d < 1 || d > a[month - 1]) {
			day = 1; // 日不合法，设置为默认值
		}
		else {
			day = d;
		}
	}
	
	
	
}


void Date::get(int& y, int& m, int& d) const
{
	y = year;
	m = month;
	d = day;
}

void Date::show()
{
	cout << year << "." << month << "." << day << endl;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int is_leap(int year) 
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int month(int day_n, int year, int* p) 
{
	int month = 1;
	if (is_leap(year)) {
		int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < 12; i++) {
			*p -= a[i];
			if (*p <= 0) {
				month += i;
				*p += a[i];
				break;
			}
		}
	}
	if (!is_leap(year)) {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < 12; i++) {
			*p -= a[i];
			if (*p <= 0) {
				month += i;
				*p += a[i];
				break;
			}
		}
	}
	return month;
}