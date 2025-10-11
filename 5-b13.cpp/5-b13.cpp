//2453805 唐先泽 电信
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	char a[10][26] = { 0 };
	//生成随机数
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 50; i++) {
		int random_num = 0;
		random_num = rand() % 260;
		if (a[random_num / 26][random_num % 26] == '*') {
			i--;
		}
		else {
			a[random_num / 26][random_num % 26] = '*';
		}
	}
	//生成数字
	// 3*3区域
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 25; j++) {
			if (a[i][j] == '*') {
				continue;
			}
			else {
				a[i][j] = '0';
				for (int m = i - 1; m <= i + 1; m++) {
					for (int n = j - 1; n <= j + 1; n++) {
						if (a[m][n] == '*') {
							a[i][j] += 1;
						}
					}
				}
			}

		}
	}
	//上下两条边:不含顶点
	for (int i = 1; i < 25; i++) {
		if (a[0][i] == '*') {
			continue;
		}
		else {
			a[0][i] = '0';
			for (int m = 0; m <= 1; m++) {
				for (int n = i-1; n <= i+1; n++) {
					if (a[m][n] == '*') {
						a[0][i] += 1;
					}
				}
			}
		}
	}
	for (int i = 1; i < 25; i++) {
		if (a[9][i] == '*') {
			continue;
		}
		else {
			a[9][i] = '0';
			for (int m = 8; m <= 9; m++) {
				for (int n = i-1; n <= i+1; n++) {
					if (a[m][n] == '*') {
						a[9][i] += 1;
					}
				}
			}
		}
	}
	//左右两条边,不含顶点
	for (int i = 1; i <= 8; i++) {
		if (a[i][0] == '*') {
			continue;
		}
		else {
			a[i][0] = '0';
			for (int m = i - 1; m <= i + 1; m++) {
				for (int n = 0; n <= 1; n++) {
					if (a[m][n] == '*') {
						a[i][0] += 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 8; i++) {
		if (a[i][25] == '*') {
			continue;
		}
		else {
			a[i][25] = '0';
			for (int m = i - 1; m <= i + 1; m++) {
				for (int n = 24; n <= 25; n++) {
					if (a[m][n] == '*') {
						a[i][25] += 1;
					}
				}
			}
		}
	}
	// 四个顶点
	if (a[0][0] != '*') {
		a[0][0] = '0';
		for (int i = 0; i <= 1;i++) {
			for (int j = 0; j <= 1; j++) {
				if (a[i][j] == '*') {
					a[0][0] += 1;
				}
			}
		}
	}
	if (a[0][25] != '*') {
		a[0][25] = '0';
		for (int i = 0; i <= 1; i++) {
			for (int j = 24; j <= 25; j++) {
				if (a[i][j] == '*') {
					a[0][25] += 1;
				}
			}
		}
	}
	if (a[9][0] != '*') {
		a[9][0] = '0';
		for (int i = 8; i <= 9; i++) {
			for (int j = 0; j <= 1; j++) {
				if (a[i][j] == '*') {
					a[9][0] += 1;
				}
			}
		}
	}
	if (a[9][25] != '*') {
		a[9][25] = '0';
		for (int i = 8; i <= 9; i++) {
			for (int j = 24; j <= 25; j++) {
				if (a[i][j] == '*') {
					a[9][25] += 1;
				}
			}
		}
	}
	//输出全图
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}