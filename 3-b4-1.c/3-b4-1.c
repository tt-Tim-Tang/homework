//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	const float Pi = 3.14159f;
	int a, b, c;
	float s;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d", &a, &b, &c);
	s = 0.5f * a * b * sinf(c / 180.0f * Pi);
	printf("%s %.3f", "三角形面积为 :", s);
	return 0;

}