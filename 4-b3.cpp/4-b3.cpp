//2453805 唐先泽 电信
#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	int c;
	int w;
	int y1;
	c = y / 100;
	y1 = y - c * 100;
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

void calendar(int year, int month)
{
	int w;
	int m;
	m = 0;
	int i,j;
	/* 按需添加代码 */
	w = zeller(year, month, 1);
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		m = 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		m = 30;
	}
	else if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
			m = 29;
		}
		else {
			m = 28;
		}
	}
	switch (w) {
	case 0:
		for (i = 1; i <= m; i++) {
			cout << "  " << setw(2) << i << "  ";
			if (i % 7 == 0) {
				if (i == m) {
					cout << "  " ;
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 1:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 8; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 1) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 2:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 16; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 2) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 3:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 24; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 3) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 4:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 32; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 4) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 5:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 40; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 5) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	case 6:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 48; j++) {
					cout << " ";
				}
			}
			cout << "  " << setw(2) << i << "  ";
			if ((i + 6) % 7 == 0) {
				if (i == m) {
					cout << "  ";
				}
				else {
					cout << "  " << endl;
				}
			}
			else {
				cout << "  ";
			}
		}
		break;
	}


	cout << endl;
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}


int main()
{
	int y, m;
	bool flag = true;
	while (flag) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;
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
			flag = false;
		}
	}

	calendar(y, m);

	return 0;
}