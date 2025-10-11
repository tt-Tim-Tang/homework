//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int sudu[9][9] = { 0 };
	for (int i = 0; i < 9; i++) {
		int j = 0;
		while (j < 9) {
			cin >> sudu[i][j];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				continue;
			}
			else {
				if (sudu[i][j] > 9 || sudu[i][j] < 1) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else {
					++j;
				}
			}
		}
	}
	// 检查行
	for (int i = 0; i < 9; i++) {
		int sum = 0;
		for (int m = 1; m < 10; m++) {
			for (int j = 0; j < 9; j++) {
				if (m == sudu[i][j]) {
					sum += 1;
					break;
				}
			}
		}
		if (sum != 9) {
			cout << "不是数独的解" << endl;
			return 0;
		}
	}
	// 检查列
	for (int j = 0; j < 9; j++) {
		int sum = 0;
		for (int m = 1; m < 10; m++) {
			for (int i = 0; i < 9; i++) {
				if (m == sudu[i][j]) {
					sum += 1;
					break;
				}
			}
		}
		if (sum != 9) {
			cout << "不是数独的解" << endl;
			return 0;
		}
	}
	//检查九宫格
	for (int n = 0; n < 3; n++) {
		int sum_1=0, sum_2=0, sum_3 = 0;
		for (int i = (3 * n); i < (3 * n + 3); i++) {
			for (int m = 1; m < 10; m++) {
				for (int j = 0; j < 3; j++) {
					if (m == sudu[i][j]) {
						sum_1 += 1;
						break;
					}
				}
				for (int j = 3; j < 6; j++) {
					if (m == sudu[i][j]) {
						sum_2 += 1;
						break;
					}
				}
				for (int j = 6; j < 9; j++) {
					if (m == sudu[i][j]) {
						sum_3 += 1;
						break;
					}
				}
			}
		}
		if (sum_1 != 9 || sum_2 != 9 || sum_3 != 9) {
			cout << "不是数独的解" << endl;
			return 0;
		}
	}
	cout << "是数独的解" << endl;

	return 0;
}