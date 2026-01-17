//2453805 唐先泽 大数据
#pragma once

class Shape {
protected:
    //根据需要加入相应的成员，也可以为空
public:
    virtual void ShapeName() = 0; //此句不准动
    //根据需要加入相应的成员，也可以为空
    virtual double area() { return 0; };
};

//此处给出五个类的定义(成员函数采用体外实现形式)
class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double r);
    virtual void ShapeName();
    virtual double area();
};

class Square : public Shape {
protected:
    double side;
public:
    Square(double s);
    virtual void ShapeName();
	virtual double area();
};

class Rectangle : public Shape {
protected:
    double length;
	double width;
public:
    Rectangle(double l, double w);
    virtual void ShapeName();
	virtual double area();
};

class Trapezoid : public Shape {
protected:
    double a;
    double b;
	double h;
public:
    Trapezoid(double a1, double b1, double h1);
    virtual void ShapeName();
    virtual double area();
};

class Triangle : public Shape {
protected:
    double a;
    double b;
    double c;
public:
    Triangle(double a1, double b1, double c1);
	virtual void ShapeName();
	virtual double area();
};






