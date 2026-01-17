//2453805 唐先泽 大数据
#pragma once

#include <iostream>
using namespace std;

enum week { sun, mon, tue, wed, thu, fri, sat };

/* 允许添加相应的函数声明 */
ostream& operator<<(ostream& out, const week& d);
istream& operator>>(istream& in, week& d);
week& operator++(week& d);       // 前缀++
week operator++(week& d, int);  // 后缀++
week& operator--(week& d);       // 前缀--
week operator--(week& d, int);  // 后缀--
week operator+(const week& d, int n);
week operator-(const week& d, int n);
week& operator+=(week& d, int n);
week& operator-=(week& d, int n);