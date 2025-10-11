//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
int main()
{
	double num;
	int num_50, num_20, num_10, num_5, num_1, num_05, num_01, num_005, num_002, num_001;
	int decimal_part, sum;
	printf("请输入找零值：\n");
	scanf("%lf", &num);
	num_50 = (int)(num / 50);
	num_20 = (int)((num - num_50 * 50.0) / 20);
	num_10 = (int)((num - num_50 * 50.0 - num_20 * 20.0) / 10);
	num_5 = (int)((num - num_50 * 50.0 - num_20 * 20.0 - num_10 * 10.0) / 5);
	num_1 = (int)(num - num_50 * 50.0 - num_20 * 20.0 - num_10 * 10.0 - num_5 * 5.0);
	decimal_part = (int)((num - num_50 * 50.0 - num_20 * 20.0 - num_10 * 10.0 - num_5 * 5.0 - num_1 * 1.0) * 100 + 0.5);
	num_05 = (decimal_part / 50);
	num_01 = ((decimal_part - num_05 * 50) / 10);
	num_005 = ((decimal_part - num_05 * 50 - num_01 * 10) / 5);
	num_002 = ((decimal_part - num_05 * 50 - num_01 * 10 - num_005 * 5) / 2);
	num_001 = (decimal_part - num_05 * 50 - num_01 * 10 - num_005 * 5 - num_002 * 2);
	sum = num_50 + num_20 + num_10 + num_5 + num_1 + num_05 + num_01 + num_005 + num_002 + num_001;
	printf("%s%d%s", "共", sum, "张找零，具体如下：\n");
	if (num_50 != 0) {
		printf("%s%d%s", "50元 : ", num_50, "张\n");
	}
	if (num_20 != 0) {
		printf("%s%d%s", "20元 : ", num_20, "张\n");
	}
	if (num_10 != 0) {
		printf("%s%d%s", "10元 : ", num_10, "张\n");
	}
	if (num_5 != 0) {
		printf("%s%d%s", "5元  : ", num_5, "张\n");
	}
	if (num_1 != 0) {
		printf("%s%d%s", "1元  : ", num_1, "张\n");
	}
	if (num_05 != 0) {
		printf("%s%d%s", "5角  : ", num_05, "张\n");
	}
	if (num_01 != 0) {
		printf("%s%d%s", "1角  : ", num_01, "张\n");
	}
	if (num_005 != 0) {
		printf("%s%d%s", "5分  : ", num_005, "张\n");
	}
	if (num_002 != 0) {
		printf("%s%d%s", "2分  : ", num_002, "张\n");
	}
	if (num_001 != 0) {
		printf("%s%d%s", "1分  : ", num_001, "张\n");
	}
	return 0;
}