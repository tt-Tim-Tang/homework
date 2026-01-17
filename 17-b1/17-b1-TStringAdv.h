//2453805 唐先泽 大数据

#pragma once

#include <iostream>
#include <climits>
using namespace std;

#include "17-b1-TString.h"

class TStringAdv : public TString {
public:
	// 构造函数
	TStringAdv() :TString(){}
	TStringAdv(const char* s) : TString(s){}
	TStringAdv(const TStringAdv& ts2) : TString(ts2){}
	TStringAdv(const TString& s) : TString(s){}
	// operator=重载
	TStringAdv& operator=(const TStringAdv& ts2);
	TStringAdv& operator=(const char* s);
	TStringAdv& operator=(const TString& s);
	// assign函数等价于=操作
	TStringAdv& assign(const TStringAdv& ts2);
	TStringAdv& assign(const char* s);
	// append函数等价于+=操作
	TStringAdv& append(const TStringAdv& ts2);
	TStringAdv& append(const char* s);
	TStringAdv& append(const char& c);
	// insert函数在指定位置插入字符串或字符
	TStringAdv& insert(const TStringAdv& ts2, int pos);
	TStringAdv& insert(const char* s, int pos);
	TStringAdv& insert(const char& c, int pos);
	// erase函数删除第一个匹配的子串，等价于-=操作
	TStringAdv& erase(const TStringAdv& ts2);	
	TStringAdv& erase(const char* s);
	TStringAdv& erase(const char& c);
	// substr函数返回子串
	const TStringAdv substr(const int pos, const int len = INT_MAX);
	// at函数返回指定位置的字符,等价于[]
	char& at(const int n);
	// TStringAdvLen函数返回字符串长度,功能同TStringLen
	friend int TStringAdvLen(const TStringAdv& s);
};
// 全局函数声明
int TStringAdvLen(const TStringAdv& s);