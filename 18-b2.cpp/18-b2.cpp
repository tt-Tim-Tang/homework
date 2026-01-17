//2453805 唐先泽 大数据
#include <iostream>
#include <cmath>
#include "18-b2.h"
using namespace std;

/* 1、给出各种类的实现（体外实现）
   2、不允许定义全局变量（不含const和#define）
   3、不允许添加其它系统头文件
*/

istream& operator>>(istream& in, integral& intg) {
	cout << "请输入";
	if (intg.name == 0) {
		cout << "sinxdx";
	}
	else if (intg.name == 1) {
		cout << "cosxdx";
	}
	else if (intg.name == 2) {
		cout << "e^xdx";
	}
	cout << "的下限、上限及区间划分数量" << endl;
	in >> intg.a >> intg.b >> intg.n;
	return in;
}



// integral_sin类成员函数的实现
integral_sin::integral_sin() {
	name = 0;
}


double integral_sin::value() const {
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		double x = a + i * h;
		sum += sin(x);
	}
	double val = sum * h;
	cout << "sinxdx[" << a << "~" << b << "/n=" << n << "] : " << val << endl;
	return val;
}


// integral_cos类成员函数的实现
integral_cos:: integral_cos() {
	name = 1;
}



double integral_cos::value() const {
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		double x = a + i * h;
		sum += cos(x);
	}
	double val = sum * h;
	cout <<"cosxdx[" << a << "~" << b << "/n=" << n << "] : " << val << endl;
	return val;
}


// integral_exp类成员函数的实现
integral_exp:: integral_exp() {
	name = 2;
}


double integral_exp::value() const {
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		double x = a + i * h;
		sum += exp(x);
	}
	double val = sum * h;
	cout << "e^xdx[" << a << "~" << b << "/n=" << n << "] : " << val << endl;
	return val;
}

