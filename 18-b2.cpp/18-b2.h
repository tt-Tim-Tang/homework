//2453805 唐先泽 大数据
#pragma once

#include <iostream>
using namespace std;
/* 1、给出各种类的定义
   2、不允许定义全局变量（不含const和#define）
   3、不允许添加其它系统头文件
*/
class integral {
protected:
	double a; //积分下限
	double b; //积分上限
	int name; //函数名称
	int n;    //划分数
public:
	virtual double value() const = 0;
	friend istream& operator>>(istream& in, integral& intg);
};

class integral_sin : public integral {
public:
	integral_sin();
	virtual double value() const;
};

class integral_cos : public integral {
public:
	integral_cos();
	virtual double value() const;
};

class integral_exp : public integral {
public:
	integral_exp();
	virtual double value() const;
};	

