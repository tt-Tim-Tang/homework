//2453805 唐先泽 大数据

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "16-b5.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
int TString::length() const
{
	return len;
}

const char* TString::c_str() const
{
	if (content == nullptr || len == 0)
		return "<EMPTY>";
	else
		return content;
}


TString::TString(const char* s)
{
	if (s == nullptr || strlen(s) == 0) {
		content = nullptr;
		len = 0;
	}
	else {
		len = strlen(s);
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s);
	}
}

TString::TString(const TString& s)
{
	if(s.length() == 0) {
		content = nullptr;
		len = 0;
	}
	else {
		len = s.length();
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s.c_str());
	}
}

TString::~TString()
{
	if (content)
		delete[] content;
}

char& TString::operator[](int index)
{
	if(index < 0 || index >= len) {
		// 越界访问，返回第一个字符的引用（虽然不合理，但测试程序会这样做）
		return content[0];
	}
	return content[index];
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */

// 重载<<运算符
ostream& operator<<(ostream& out, const TString& s)
{
	if (s.c_str() == nullptr) {
		out << "<EMPTY>";
	}
	else {
		out << s.c_str();
	}
	return out;
}

// 重载>>运算符
istream& operator>>(istream& in, TString& s)
{
	if(s.c_str() != nullptr || s.length() != 0) {
		delete[] s.content;
	}

	char* buffer = nullptr;
	int size = 0;
	char ch;
	while (in.get(ch) && ch != ' ' && ch != '\n') {
		char* new_buff = new(nothrow) char[size + 2];
		if (new_buff == nullptr) {
			exit(-1);
		}
		if(buffer != nullptr) {
			strcpy(new_buff, buffer);
			delete[] buffer;
		}
		new_buff[size] = ch;
		new_buff[size + 1] = '\0';
		buffer = new_buff;
		size++;
	}
	if (buffer == nullptr) {
		s.content = nullptr;
		s.len = 0;
	}
	else {
		s.content = buffer;
		s.len = size;
	}
	return in;
}

// 重载+运算符
TString operator+(const TString& s1, const TString& s2)
{
	TString result;
	if(s1.length() == 0 && s2.length() == 0) {
		return result;
	}
	else if(s1.length() == 0) {
		result.len = s2.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s2.c_str());
		return result;
	}
	else if(s2.length() == 0) {
		result.len = s1.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		return result;
	}
	else {
		result.len = s1.length() + s2.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		strcat(result.content, s2.c_str());
		return result;
	}
}

TString operator+(const TString& s1, const char* s2)
{
	TString result;
	if(s1.length() == 0 && (s2 == nullptr || strlen(s2) == 0)) {
		return result;
	}
	else if(s1.length() == 0) {
		result.len = strlen(s2);
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s2);
		return result;
	}
	else if(s2 == nullptr || strlen(s2) == 0) {
		result.len = s1.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		return result;
	}
	else {
		result.len = s1.length() + strlen(s2);
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		strcat(result.content, s2);
		return result;
	}
}

TString operator+(const char* s1, const TString& s2)
{
	TString result;
	if((s1 == nullptr || strlen(s1) == 0) && s2.length() == 0) {
		return result;
	}
	else if(s1 == nullptr || strlen(s1) == 0) {
		result.len = s2.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s2.c_str());
		return result;
	}
	else if(s2.length() == 0) {
		result.len = strlen(s1);
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1);
		return result;
	}
	else {
		result.len = strlen(s1) + s2.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1);
		strcat(result.content, s2.c_str());
		return result;
	}
}

TString operator+(char c, const TString& s2)
{
	TString result;
	if(s2.length() == 0) {
		result.len = 1;
		result.content = new(nothrow) char[2];
		if (result.content == nullptr)
			exit(-1);
		result.content[0] = c;
		result.content[1] = '\0';
		return result;
	}
	else {
		result.len = 1 + s2.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		result.content[0] = c;
		strcpy(result.content + 1, s2.c_str());
		return result;
	}
}

TString operator+(const TString& s1, char c)
{
	TString result;
	if(s1.length() == 0) {
		result.len = 1;
		result.content = new(nothrow) char[2];
		if (result.content == nullptr)
			exit(-1);
		result.content[0] = c;
		result.content[1] = '\0';
		return result;
	}
	else {
		result.len = s1.length() + 1;
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		result.content[s1.length()] = c;
		result.content[s1.length() + 1] = '\0';
		return result;
	}
}

// 重载+=运算符
TString& TString:: operator+=(const TString& s)
{
	if (s.length() == 0) {
		return *this;
	}
	else if (len == 0) {
		len = s.length();
		if(content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s.c_str());
		return *this;
	}
	else {
		int new_len = len + s.length();
		char* new_content = new(nothrow) char[new_len + 1];
		if (new_content == nullptr)
			exit(-1);
		strcpy(new_content, content);
		strcat(new_content, s.c_str());
		delete[] content;
		content = new_content;
		len = new_len;
		return *this;
	}
}

TString& TString:: operator+=(const char* s)
{
	if(s == nullptr || strlen(s) == 0) {
		return *this;
	}
	else if (len == 0) {
		len = strlen(s);
		if(content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s);
		return *this;
	}
	else {
		int new_len = len + strlen(s);
		char* new_content = new(nothrow) char[new_len + 1];
		if (new_content == nullptr)
			exit(-1);
		strcpy(new_content, content);
		strcat(new_content, s);
		delete[] content;
		content = new_content;
		len = new_len;
		return *this;
	}
}

TString& TString:: operator+=(char c)
{
	if (len == 0) {
		len = 1;
		if(content)
			delete[] content;
		content = new(nothrow) char[2];
		if (content == nullptr)
			exit(-1);
		content[0] = c;
		content[1] = '\0';
		return *this;
	}
	else {
		int new_len = len + 1;
		char* new_content = new(nothrow) char[new_len + 1];
		if (new_content == nullptr)
			exit(-1);
		strcpy(new_content, content);
		new_content[len] = c;
		new_content[len + 1] = '\0';
		delete[] content;
		content = new_content;
		len = new_len;
		return *this;
	}
}

//append函数实现
TString& TString:: append(const TString& s)
{
	*this += s;
	return *this;
}
TString& TString:: append(const char* s)
{
	*this += s;
	return *this;
}
TString& TString:: append(char c)
{
	*this += c;
	return *this;
}

// 重载=运算符
TString& TString:: operator=(const TString& s)
{

	if(this == &s) {
		return *this;
	}

	if (s.length() == 0) {
		if (content)
			delete[] content;
		content = nullptr;
		len = 0;
		return *this;
	}
	else {
		len = s.length();
		if(content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s.c_str());
		return *this;
	}
}

TString& TString:: operator=(const char* s)
{
	if (s == nullptr || strlen(s) == 0) {
		if (content)
			delete[] content;
		content = nullptr;
		len = 0;
		return *this;
	}
	else {
		len = strlen(s);
		if(content)
			delete[] content;
		content = new(nothrow) char[len + 1];
		if (content == nullptr)
			exit(-1);
		strcpy(content, s);
		return *this;
	}
}

// 重载-运算符
int find_substr_pos(const TString& s1, const TString& s2)
{
	int pos = -1;
	const char* p1 = s1.c_str();
	const char* p2 = s2.c_str();
	if(s1.length() == 0 || s2.length() == 0 || s2.length() > s1.length()) {
		return pos;
	}
	else {
		for(int i = 0; i <= s1.length() - s2.length(); i++) {
			int j;
			for(j = 0; j < s2.length(); j++) {
				if(p1[i + j] != p2[j]) {
					break;
				}
			}
			if(j == s2.length()) {
				pos = i;
				break;
			}
		}
		return pos;
	}
}

TString operator-(const TString& s1, const TString& s2)
{
	TString result;
	if (find_substr_pos(s1, s2) == -1) {
		result = s1;
		return result;
	}
	else {
		int pos = find_substr_pos(s1, s2);
		int new_len = s1.length() - s2.length();
		result.len = new_len;
		result.content = new(nothrow) char[new_len + 1];
		if(result.content == nullptr)
			exit(-1);
		int i = 0;
		for(int j = 0; j < s1.length(); j++) {
			if(j >= pos && j < pos + s2.length()) {
				continue;
			}
			else {
				result.content[i++] = s1.c_str()[j];
			}
		}
		result.content[new_len] = '\0';
		return result;
	}
}

int find_substr_pos(const TString& s1, const char* s)
{
	int pos = -1;
	const char* p1 = s1.c_str();
	const char* p2 = s;
	if (s1.length() == 0 || strlen(s) == 0 || (int)strlen(s) > s1.length()) {
		return pos;
	}
	else {
		for (int i = 0; i <= s1.length() - (int)strlen(s); i++) {
			int j;
			for (j = 0; j < (int)strlen(s); j++) {
				if (p1[i + j] != p2[j]) {
					break;
				}
			}
			if (j == (int)strlen(s)) {
				pos = i;
				break;
			}
		}
		return pos;
	}
}

TString operator-(const TString& s1, const char* s)
{
	TString result;
	if (find_substr_pos(s1, s) == -1) {
		result = s1;
		return result;
	}
	else {
		int pos = find_substr_pos(s1, s);
		int new_len = s1.length() - strlen(s);
		result.len = new_len;
		result.content = new(nothrow) char[new_len + 1];
		if (result.content == nullptr)
			exit(-1);
		int i = 0;
		for (int j = 0; j < s1.length(); j++) {
			if (j >= pos && j < pos + (int)strlen(s)) {
				continue;
			}
			else {
				result.content[i++] = s1.c_str()[j];
			}
		}
		result.content[new_len] = '\0';
		return result;
	}
}

int find_char_pos(const TString& s1, char c)
{
	int pos = -1;
	const char* p1 = s1.c_str();
	if (s1.length() == 0) {
		return pos;
	}
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (p1[i] == c) {
				pos = i;
				break;
			}
		}
		return pos;
	}
}

TString operator-(const TString& s1, char c)
{
	TString result;
	if (find_char_pos(s1, c) == -1) {
		result = s1;
		return result;
	}
	else {
		int pos = find_char_pos(s1, c);
		int new_len = s1.length() - 1;
		result.len = new_len;
		result.content = new(nothrow) char[new_len + 1];
		if (result.content == nullptr)
			exit(-1);
		int i = 0;
		for (int j = 0; j < s1.length(); j++) {
			if (j == pos) {
				continue;
			}
			else {
				result.content[i++] = s1.c_str()[j];
			}
		}
		result.content[new_len] = '\0';
		return result;
	}
}


// 重载-=运算符
TString& TString:: operator-=(const TString& s)
{
	if(find_substr_pos(*this, s) == -1) {
		return *this;
	}
	else {
		*this = *this - s;
		return *this;
	}
}

TString& TString:: operator-=(const char* s)
{
	if (find_substr_pos(*this, s) == -1) {
		return *this;
	}
	else {
		*this = *this - s;
		return *this;
	}
}

TString& TString:: operator-=(char c)
{
	if (find_char_pos(*this, c) == -1) {
		return *this;
	}
	else {
		*this = *this - c;
		return *this;
	}
}

// 重载*运算符
TString operator*(const TString& s1, int n)
{
	TString result;
	if (s1.length() == 0 || n <= 0) {
		return result;
	}
	else {
		result.len = s1.length() * n;
		result.content = new(nothrow) char[result.len + 1];
		if(result.content == nullptr)
			exit(-1);
		strcpy(result.content, s1.c_str());
		for(int i = 1; i < n; i++) {
			strcat(result.content, s1.c_str());
		}
		return result;
	}
}

// 重载*=运算符
TString& TString:: operator*=(int n)
{
	*this = *this * n;
	return *this;
}

// 重载!运算符
TString operator!(const TString& s1)
{
	TString result;
	if (s1.length() == 0) {
		return result;
	}
	else {
		result.len = s1.length();
		result.content = new(nothrow) char[result.len + 1];
		if (result.content == nullptr)
			exit(-1);
		for (int i = 0; i < s1.length(); i++) {
			result.content[i] = s1.c_str()[s1.length() - 1 - i];
		}
		result.content[result.len] = '\0';
		return result;
	}
}

// 重载>运算符
int operator>(const TString& s1, const TString& s2)
{
	if(s1.length() == 0 && s2.length() == 0) {
		return 0;
	}
	const char* p1 = s1.c_str();
	const char* p2 = s2.c_str();
	if(p1 != nullptr && p2 != nullptr) {
		if(strcmp(p1, p2) > 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if(p1 != nullptr && p2 == nullptr) {
		return 1;
	}
	else {
		return 0;
	}
}

// 重载<运算符
int operator<(const TString& s1, const TString& s2)
{
	if(s1.length() == 0 && s2.length() == 0) {
		return 0;
	}
	const char* p1 = s1.c_str();
	const char* p2 = s2.c_str();
	if (p1 != nullptr && p2 != nullptr) {
		if (strcmp(p1, p2) < 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (p1 == nullptr && p2 != nullptr) {
		return 1;
	}
	else {
		return 0;
	}
}

// 重载==运算符
int operator==(const TString& s1, const TString& s2)
{
	if(s1.length() == 0 && s2.length() == 0) {
		return 1;
	}
	const char* p1 = s1.c_str();
	const char* p2 = s2.c_str();
	if(p1 != nullptr && p2 != nullptr) {
		if(strcmp(p1, p2) == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

// 重载>=运算符
int operator>=(const TString& s1, const TString& s2)
{
	if(s1 > s2 || s1 == s2) {
		return 1;
	}
	else {
		return 0;
	}
}

// 重载<=运算符
int operator<=(const TString& s1, const TString& s2)
{
	if(s1 < s2 || s1 == s2) {
		return 1;
	}
	else {
		return 0;
	}
}

// 重载!=运算符
int operator!=(const TString& s1, const TString& s2)
{
	if(!(s1 == s2)) {
		return 1;
	}
	else {
		return 0;
	}
}


// 全局函数 TStringLen 实现
int TStringLen(const TString& s)
{
	return s.length();
}
