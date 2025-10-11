//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int is_run(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		return 1; //是闰年
	} 
	else {
		return 0; //不是闰年
	}
}
int day_out(int month,int day,int num)
{
	int day_out=day;
	// 是闰年
	if (num) {
		int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < month - 1;i++) {
			day_out += a[i];
		}
		return day_out;
	}
	// 不是闰年
	else {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < month - 1; i++) {
			day_out += a[i];
		}
		return day_out;
	}

}
int fifa(int month,int day,int num)//判断日与月的关系非法
{
	//闰年
	if (num) {
		int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		if (day > a[month - 1] || day < 1) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
		else {
			return 1;
		}
	}
	//不是闰年
	else {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (day > a[month - 1] || day < 1) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
		else {
			return 1;
		}
	}

}
int main()
{
	int year, month, day;
	printf("%s", "请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month >= 13 || month <= 0) {
		printf("%s", "输入错误-月份不正确\n");
	}
	else {
		int num = is_run(year);
		int n=fifa(month, day, num);
		if (n) {
			int output = day_out(month, day, num);
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, output);
		}
		else {
			return 0;
		}
	}
	return 0;
}