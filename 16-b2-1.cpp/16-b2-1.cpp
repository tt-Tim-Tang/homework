//2453805 唐先泽 大数据
#include <iostream>
using namespace std;

#include "16-b2-1.h" //16-b2-1.h在编译时会被替换，不需要提交，自己测试时可以任意改动

class matrix {
private:
	int value[ROW][COL];
	//除此之外不允许再添加数据成员
public:
	matrix(const int(*p)[COL]);	//构造函数，用数组初始化矩阵

#if OPERATOR_IS_MENBER_FUNCTION
	//给出+的成员函数实现方式的声明
	matrix operator+(const matrix& m) const;
#else
	//给出+的友元函数实现方式的声明
	friend matrix operator+ (const matrix& a, const matrix& b);
#endif

	/* ----根据需要添加其它成员函数的定义和友元函数的声明，数量不限---- */
	matrix(); //默认构造函数，初始化为全0矩阵
	friend ostream& operator << (ostream& out, const matrix& a);
	friend istream& operator >> (istream& in, matrix& a);
};

/* ---- 给出成员函数的体外实现/友元函数的实现，其中+的实现有成员和友元两种形式，要求放在下面的预编译中 ---- */

matrix::matrix(const int(*p)[COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			value[i][j] = p[i][j];
		}
	}

}
matrix::matrix() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			value[i][j] = 0;
		}
	}
}

ostream& operator << (ostream& out, const matrix& a) {
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			out << a.value[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator >> (istream& in, matrix& a) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			in >> a.value[i][j];
		}
	}
	return in;
}
#if OPERATOR_IS_MENBER_FUNCTION
//给出+的成员函数方式的体外实现
matrix matrix:: operator+(const matrix& m) const {
	matrix temp;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp.value[i][j] = this->value[i][j] + m.value[i][j];
		}
	}
	return temp;
}
#else
//给出+的友元函数方式的体外实现
matrix operator+ (const matrix& a, const matrix& b) {
	matrix temp;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp.value[i][j] = a.value[i][j] + b.value[i][j];
		}
	}
	return temp;
}
#endif


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
//	int a[ROW][COL] = { { 1,2,3 },{ 4,5,6 } };
//	int b[ROW][COL] = { { 2,4,6 },{ 3,6,9 } };
//   a/b两个二维数组具体见16-b2-1.h，作业检查时会被替换

	matrix m1(a), m2(b), m3; //m3的初值为全0

	/* 下面为定值测试 */
	cout << "初始矩阵m1的值" << endl;
	cout << m1 << endl;
	cout << "初始矩阵m2的值" << endl;
	cout << m2 << endl;

	m3 = m1 + m2;
	cout << "相加后矩阵m3的值" << endl;
	cout << m3 << endl;

	cout << "------------------" << endl;

	/* 下面为键盘输入测试 */
	cout << "请输入初始矩阵m1" << endl;
	cin >> m1;
	cout << "请输入初始矩阵m2" << endl;
	cin >> m2;

	cout << "初始矩阵m1的值" << endl;
	cout << m1 << endl;
	cout << "初始矩阵m2的值" << endl;
	cout << m2 << endl;
	cout << "相加后矩阵m3的值" << endl;
	cout << (m3 = m1 + m2) << endl;

	return 0;
}
