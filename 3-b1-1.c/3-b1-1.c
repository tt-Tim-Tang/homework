//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    const double Pi = 3.14159;
    double r, h;
    printf("请输入半径和高度\n");
    scanf("%lf %lf", &r, &h);
    printf("%-11s: %.2f\n", "圆周长", 2 * Pi * r);
    printf("%-11s: %.2f\n", "圆面积", Pi * r * r);
    printf("%-11s: %.2f\n", "圆球表面积", 4 * Pi * r * r);
    printf("%-11s: %.2f\n", "圆球体积", 4.0 / 3 * Pi * r * r * r);
    printf("%-11s: %.2f\n", "圆柱体积", Pi * r * r * h);

    return 0;
}