//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	double num;
	int num_1, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, decimal_part, num_11, num_12;
	int num_2;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &num);
	num_1 = (int)(num / 1000000000);
	num_2 = (int)((num - num_1 * 1000000000.0) / 100000000);
	num_3 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0) / 10000000);
	num_4 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0) / 1000000);
	num_5 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0) / 100000);
	num_6 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0) / 10000);
	num_7 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0) / 1000);
	num_8 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0) / 100);
	num_9 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0) / 10);
	num_10 = (int)(num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0);
	decimal_part = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0 - num_10 * 1.0) * 100 + 0.5);
	num_11 = decimal_part / 10;
	num_12 = decimal_part - 10 * num_11;

	printf("%7s: %d\n", "十亿位", num_1);
	printf("%7s: %d\n", "亿位", num_2); 
	printf("%7s: %d\n", "千万位", num_3);
	printf("%7s: %d\n", "百万位", num_4);
	printf("%7s: %d\n", "十万位", num_5);
	printf("%7s: %d\n", "万位", num_6);
	printf("%7s: %d\n", "千位", num_7);
	printf("%7s: %d\n", "百位", num_8);
	printf("%7s: %d\n", "十位", num_9);
	printf("%7s: %d\n", "圆位", num_10);
	printf("%7s: %d\n", "角位", num_11);
	printf("%7s: %d\n", "分位", num_12);

	return 0;


}