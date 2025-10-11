//2453805 唐先泽 电信
//2450322 郁峥鸣 2452538 张皓天 2454196 张子原 2451997 周禺辰 2451995 龙思源 2451996 辛泓毅
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[10][26] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	//检验错误1
	int sum_1 = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			if (a[i][j] == '*') {
				sum_1++;
			}
		}
	}
	if (sum_1 != 50) {
		printf("错误1\n");
		return 0;
	}
	//检验错误2
	// 3*3区域
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 25; j++) {
			if (a[i][j] == '*') {
				continue;
			}
			else {
				int sum = 0;
				for (int m = i - 1; m <= i + 1; m++) {
					for (int n = j - 1; n <= j + 1; n++) {
						if (a[m][n] == '*') {
							sum += 1;
						}
					}
				}
				if (sum != a[i][j] - '0') {
					printf("错误2\n");
					return 0;
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
			int sum = 0;
			for (int m = 0; m <= 1; m++) {
				for (int n = i - 1; n <= i + 1; n++) {
					if (a[m][n] == '*') {
						sum += 1;
					}
				}
			}
			if (sum != a[0][i] - '0') {
				printf("错误2\n");
				return 0;
			}
		}
	}
	for (int i = 1; i < 25; i++) {
		if (a[9][i] == '*') {
			continue;
		}
		else {
			int sum = 0;
			for (int m = 8; m <= 9; m++) {
				for (int n = i - 1; n <= i + 1; n++) {
					if (a[m][n] == '*') {
						sum += 1;
					}
				}
			}
			if (sum != a[9][i] - '0') {
				printf("错误2\n");
				return 0;
			}
		}
	}
	//左右两条边,不含顶点
	for (int i = 1; i <= 8; i++) {
		if (a[i][0] == '*') {
			continue;
		}
		else {
			int sum = 0;
			for (int m = i - 1; m <= i + 1; m++) {
				for (int n = 0; n <= 1; n++) {
					if (a[m][n] == '*') {
						sum += 1;
					}
				}
			}
			if (sum != a[i][0] - '0') {
				printf("错误2\n");
				return 0;
			}
		}
	}
	for (int i = 1; i <= 8; i++) {
		if (a[i][25] == '*') {
			continue;
		}
		else {
			int sum = 0;
			for (int m = i - 1; m <= i + 1; m++) {
				for (int n = 24; n <= 25; n++) {
					if (a[m][n] == '*') {
						sum += 1;
					}
				}
			}
			if (sum != a[i][25] - '0') {
				printf("错误2\n");
				return 0;
			}
		}
	}
	// 四个顶点
	if (a[0][0] != '*') {
		int sum = 0;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				if (a[i][j] == '*') {
					sum += 1;
				}
			}
		}
		if (sum != a[0][0] - '0') {
			printf("错误2\n");
			return 0;
		}
	}
	if (a[0][25] != '*') {
		int sum = 0;
		for (int i = 0; i <= 1; i++) {
			for (int j = 24; j <= 25; j++) {
				if (a[i][j] == '*') {
					sum += 1;
				}
			}
		}
		if (sum != a[0][25] - '0') {
			printf("错误2\n");
			return 0;
		}
	}
	if (a[9][0] != '*') {
		int sum = 0;
		for (int i = 8; i <= 9; i++) {
			for (int j = 0; j <= 1; j++) {
				if (a[i][j] == '*') {
					sum += 1;
				}
			}
		}
		if (sum != a[9][0] - '0') {
			printf("错误2\n");
			return 0;
		}
	}
	if (a[9][25] != '*') {
		int sum = 0;
		for (int i = 8; i <= 9; i++) {
			for (int j = 24; j <= 25; j++) {
				if (a[i][j] == '*') {
					sum += 1;
				}
			}
		}
		if (sum != a[9][25] - '0') {
			printf("错误2\n");
			return 0;
		}
	}

	printf("正确\n");
	return 0;

}