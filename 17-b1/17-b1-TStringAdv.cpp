//2453805 唐先泽 大数据

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "17-b1-TStringAdv.h"
using namespace std;


// operator=重载
TStringAdv& TStringAdv::operator=(const TStringAdv& ts2)
{
	TString::operator=(ts2);
	return *this;
}
TStringAdv& TStringAdv::operator=(const char* s)
{
	TString::operator=(s);
	return *this;
}


TStringAdv& TStringAdv::operator=(const TString& s)
{
	TString::operator=(s);
	return *this;
}



// assign函数等价于=操作
TStringAdv& TStringAdv::assign(const TStringAdv& ts2)
{
	if (this == &ts2) {
		return *this;
	}

	if (ts2.length() == 0) {
		if (content)
			delete[] content;
		content = nullptr;
		len = 0;
		return *this;
	}
	else {
		len = ts2.length();
		if (content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, ts2.c_str());
		return *this;
	}
}

TStringAdv& TStringAdv::assign(const char* s) {
	if (s == nullptr || strlen(s) == 0) {
		if (content)
			delete[] content;
		content = nullptr;
		len = 0;
		return *this;
	}
	else {
		if(s == content) {
			return *this;
		}
		len = (int)strlen(s);
		if (content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s);
		return *this;
	}

}
// append函数等价于+=操作
TStringAdv& TStringAdv::append(const TStringAdv& ts2)
{
	TString::operator+=(ts2);
	return *this;
}
TStringAdv& TStringAdv::append(const char* s)
{
	TString::operator+=(s);
	return *this;
}
TStringAdv& TStringAdv::append(const char& c)
{
	TString::operator+=(c);
	return *this;
}
// insert函数在指定位置插入字符串或字符
TStringAdv& TStringAdv::insert(const TStringAdv& ts2, int pos)
{
	return insert(ts2.c_str(), pos);
}
TStringAdv& TStringAdv::insert(const char* s, int pos)
{
	if(pos < 1 || pos > len + 1) {
		return *this;
	}

	if(s == nullptr || strlen(s) == 0) {
		return *this;
	}

	int old_len = len;
	int insert_len = (int)strlen(s);
	int new_len = old_len + insert_len;
	
	char* new_content = new(nothrow) char[new_len + 1];
	if(new_content == nullptr) {
		exit(-1);
	}
	int insert_idx = pos - 1;

	memcpy(new_content, content, insert_idx);
	memcpy(new_content + insert_idx, s, insert_len);
	memcpy(new_content + insert_idx + insert_len, content + insert_idx, old_len - insert_idx);

	new_content[new_len] = '\0';

	if (content) {
		delete[] content;
	}
	content = new_content;
	len = new_len;
	return *this;
}
TStringAdv& TStringAdv::insert(const char& c, int pos)
{
	if(pos < 1 || pos > len + 1) {
		return *this;
	}

	if(c == '\0') {
		if (pos == 1) {
			if (content) {
				delete[] content;
			}
			content = nullptr;
			len = 0;
			return *this;
		}
		int new_len = pos - 1;
		char* new_content = new(nothrow) char[new_len + 1];
		if(new_content == nullptr) {
			exit(-1);
		}
		memcpy(new_content, content, new_len);
		new_content[new_len] = '\0';
		if (content) {
			delete[] content;
		}
		content = new_content;
		len = new_len;
		return *this;
	}


	int old_len = len;
	int new_len = old_len + 1;
	
	char* new_content = new(nothrow) char[new_len + 1];
	if(new_content == nullptr) {
		exit(-1);
	}
	int insert_idx = pos - 1;
	memcpy(new_content, content, insert_idx);
	new_content[insert_idx] = c;
	memcpy(new_content + insert_idx + 1, content + insert_idx, old_len - insert_idx);
	new_content[new_len] = '\0';
	if (content) {
		delete[] content;
	}
	content = new_content;
	len = new_len;
	return *this;
}
// erase函数删除第一个匹配的子串，等价于-=操作
TStringAdv& TStringAdv::erase(const TStringAdv& ts2)
{
	TString::operator-=(ts2);
	return *this;
}
TStringAdv& TStringAdv::erase(const char* s)
{
	TString::operator-=(s);
	return *this;
}
TStringAdv& TStringAdv::erase(const char& c)
{
	TString::operator-=(c);
	return *this;
}
// substr函数返回子串
const TStringAdv TStringAdv::substr(const int pos, const int len)
{
	TStringAdv result;
	if(len <= 0 || pos < 1 || pos > this->len) {
		result.content = nullptr;
		result.len = 0;
		return result;
	}
	else {
		int start = pos - 1;
		int max_len = this->len - start;
		int sub_len = (len > max_len) ? max_len : len;
		result.len = sub_len;
		result.content = new(nothrow) char[sub_len + 1];
		if(result.content == nullptr) {
			exit(-1);
		}
		memcpy(result.content, this->content + start, sub_len);
		result.content[sub_len] = '\0';
		return result;
	}
}
// at函数返回指定位置的字符,等价于[]
char& TStringAdv::at(const int n)
{
	return TString::operator[](n);
}
// TStringAdvLen函数返回字符串长度,功能同TStringLen
int TStringAdvLen(const TStringAdv& s)
{
	return s.length();
}
