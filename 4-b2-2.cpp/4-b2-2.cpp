//2453805 唐先泽 电信
#include<iostream>
#include<limits>
using namespace std;
/*
w:星期
c：世纪-1 （4位年份前2位）
y：年（4位年份后2位）
m：月（3<=m<=14，某年1，2月要看作上一年的13、14月来计算）
d：日
公式：
w=y+【y/4】+【c/4】-2c+【13（m+1）/5】+d-1
算出来的w（若w为负数则加7的倍数后转为正数）除以7，余数是几就是星期几
*/
int zeller(int y, int m, int d)
{
	int c;
	int w;
	int y1;
	c = y / 100;
	y1 = y - c*100;
	if (m == 1) {
		m = 13;
		y = y - 1;
		c = y / 100;
		y1 = y - c * 100;

	}
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y1 = y - c * 100;
	}
	w = y1 + y1 / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0) {
		while (1) {
			w += 7;
			if (w >= 0) {
				w = w % 7;
				break;
			}
		}
	}
	else {
		w = w % 7;
	}

	return w;
}
int main()
{
	int y, m, d;
	bool flag = true;
	while (flag) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else {
			if (y < 1900 || y>2100) {
				cout << "年份不正确，请重新输入" << endl;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		    if (m < 1 || m>12) {
				cout << "月份不正确，请重新输入" << endl;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			switch (m) {
				case 12:
				case 10:
				case 8:
				case 7:
				case 5:
				case 3:
				case 1:
					if (d < 1 || d>31) {
						cout << "日不正确，请重新输入" << endl;
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					else {
						flag = false;
					}
					break;
				case 11:
				case 9:
				case 6:
				case 4:
					if (d < 1 || d>30) {
						cout << "日不正确，请重新输入" << endl;
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					else {
						flag = false;
					}
					break;
				case 2:
					if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) {
						if (d < 1 || d>29) {
							cout << "日不正确，请重新输入" << endl;
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						else {
							flag = false;
						}
					}
					else {
						if (d < 1 || d>28) {
							cout << "日不正确，请重新输入" << endl;
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						else {
							flag = false;
						}

					}
					break;

			}

			

		
		}
	}

	switch (zeller(y,m,d)) {
	case 6:
		cout << "星期六" << endl;
		break;
	case 5:
		cout << "星期五" << endl;
		break;
	case 4:
		cout << "星期四" << endl;
		break;
	case 3:
		cout << "星期三" << endl;
		break;
	case 2:
		cout << "星期二" << endl;
		break;
	case 1:
		cout << "星期一" << endl;
		break;
	case 0:
		cout << "星期日" << endl;
		break;
	}



	return 0;

}