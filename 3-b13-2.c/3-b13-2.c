//2453805 唐先泽 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day,ret;
	int i, j, m;
	m = 0;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		//cin >> year >> month;
		ret = scanf("%d%d", &year, &month);
		if (ret == 0) {
			while (getchar() != '\n');
			printf("输入非法，请重新输入\n");
			continue;
		}
		else {
			if (year < 2000 || year>2030 || month < 1 || month>12) {
				printf("输入非法，请重新输入\n");
				continue;
			}
			else {
				break;
			}
		}
	}
	while (1) {
		//cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
		//cin >> day;
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		scanf("%d", &day);
		if (ret==0) {
			while (getchar() != '\n');
			printf("输入非法，请重新输入\n");
			continue;
		}
		else {
			if (day < 0 || day>6) {
				printf("输入非法，请重新输入\n");
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("\n");
	//cout << year << "年" << month << "月的月历为:" << endl;
	printf("%d年%d月的月历为:\n",year,month);
		//cout << "星期日" << "  " << "星期一" << "  " << "星期二" << "  " << "星期三" << "  " << "星期四" << "  " << "星期五" << "  " << "星期六" << endl;
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	//判断是否为闰年
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
	switch (day) {
	case 0:
		for (i = 1; i <= m; i++) {
			printf("  %2d  ",i);
			if (i % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 1:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 8; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 1) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 2:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 16; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 2) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 3:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 24; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 3) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 4:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 32; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 4) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 5:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 40; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 5) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	case 6:
		for (i = 1; i <= m; i++) {
			if (i == 1) {
				for (j = 1; j <= 48; j++) {
					printf(" ");
				}
			}
			printf("  %2d  ",i);
			if ((i + 6) % 7 == 0) {
				printf("  \n");
			}
			else {
				printf("  ");
			}
		}
		break;
	}


	printf("\n");
	return 0;
}