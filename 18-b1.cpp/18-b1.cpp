//2453805 唐先泽 大数据
//允许添加需要的系统头文件及命名空间
#include "18-b1.h"
#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159;

//此处给出五个类的成员函数的实现


// Circle类成员函数的实现
void Circle::ShapeName() {
	cout << "Circle" << endl;
}

Circle::Circle(double r) : radius(r) {}

double Circle::area() {
	if (radius <= 0) 
		return 0;
	return pi * radius * radius;
}

// Square类成员函数的实现
void Square::ShapeName() {
	cout << "Square" << endl;
}

Square::Square(double s) : side(s) {}

double Square::area() {
	if (side <= 0) 
		return 0;
	return side * side;
}

// Rectangle类成员函数的实现
void Rectangle::ShapeName() {
	cout << "Rectangle" << endl;
}

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

double Rectangle::area() {
	if (length <= 0 || width <= 0) 
		return 0;
	return length * width;
}

// Trapezoid类成员函数的实现
void Trapezoid::ShapeName() {
	cout << "Trapezoid" << endl;
}

Trapezoid::Trapezoid(double a1, double b1, double h1) : a(a1), b(b1), h(h1) {}

double Trapezoid::area() {
	if (a <= 0 || b <= 0 || h <= 0) 
		return 0;
	return (a + b) * h / 2;
}

// Triangle类成员函数的实现
void Triangle::ShapeName() {
	cout << "Triangle" << endl;
}

Triangle::Triangle(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}

double Triangle::area() {
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) 
		return 0;
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}