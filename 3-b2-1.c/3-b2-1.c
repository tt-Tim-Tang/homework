//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int num;
    printf("请输入一个[1..30000]间的整数:\n");
    scanf("%d", &num);
    printf("%-5s: %d\n", "万位", num / 10000);
    printf("%-5s: %d\n", "千位", num / 1000 % 10);
    printf("%-5s: %d\n", "百位", num / 100 % 10);
    printf("%-5s: %d\n", "十位", num / 10 % 10);
    printf("%-5s: %d\n", "个位", num % 10);

    return 0;
}