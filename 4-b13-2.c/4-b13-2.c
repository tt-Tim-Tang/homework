//2453805 唐先泽 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
int sum = 0;
void hanoi(int n, char src, char tmp, char dst)
{

    if (n == 1) {
        sum++;
        printf("%5d:", sum);
        printf("%3d# %c-->%c\n", 1, src, dst);
    }
    else if (n == 2) {
        sum++;
        printf("%5d:", sum);
        printf("%3d# %c-->%c\n", 1, src, tmp);
        sum++;
        printf("%5d:", sum);
        printf("%3d# %c-->%c\n", 2, src, dst);
        sum++;
        printf("%5d:", sum);
        printf("%3d# %c-->%c\n", 1, tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        sum++;
        printf("%5d:", sum);
        printf("%3d# %c-->%c\n", n, src, dst);

        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;//汉诺塔层数
    char src, dst, tmp;//起始柱、目标柱
    tmp = ' ';
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
        int ret = scanf("%d",&n);
        if (ret==0) {
            while (getchar() != '\n');
            continue;
        }
        else {
            if (n < 1 || n>16) {
                while (getchar() != '\n');
                continue;
            }
            else {
                while (getchar() != '\n');
                break;
            }
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        int ret = scanf("%c", &src);
        if (ret==0) {
            while (getchar() != '\n');
            continue;
        }
        else {
            if (src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
                while (getchar() != '\n');
                break;
            }
            else {
                while (getchar() != '\n');
                continue;
            }
        }
    }
    while (1) {
        printf("请输入目标柱(A-C)\n");
        int ret = scanf("%c", &dst);
        if (ret==0) {
            while (getchar() != '\n');
            continue;
        }
        else {
            if (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c') {

                if ((src == 'A' || src == 'a') && (dst == 'A' || dst == 'a')) {
                    while (getchar() != '\n');
                    printf("目标柱(A)不能与起始柱(A)相同\n");
                    continue;
                }
                else if ((src == 'B' || src == 'b') && (dst == 'B' || dst == 'b')) {
                    while (getchar() != '\n');
                    printf("目标柱(B)不能与起始柱(B)相同\n");
                    continue;
                }
                else if ((src == 'C' || src == 'c') && (dst == 'C' || dst == 'c')) {
                    while (getchar() != '\n');
                    printf("目标柱(C)不能与起始柱(C)相同\n");
                    continue;
                }

                else {
                    while (getchar() != '\n');
                    break;
                }
            }
            else {
                while (getchar() != '\n');
                continue;
            }
        }
    }
    if ((src == 'A' || src == 'a') && (dst == 'B' || dst == 'b')) {
        src = 'A';
        dst = 'B';
        tmp = 'C';
    }
    if ((src == 'A' || src == 'a') && (dst == 'C' || dst == 'c')) {
        src = 'A';
        dst = 'C';
        tmp = 'B';
    }
    if ((src == 'B' || src == 'b') && (dst == 'A' || dst == 'a')) {
        src = 'B';
        dst = 'A';
        tmp = 'C';
    }
    if ((src == 'B' || src == 'b') && (dst == 'C' || dst == 'c')) {
        src = 'B';
        dst = 'C';
        tmp = 'A';
    }
    if ((src == 'C' || src == 'c') && (dst == 'A' || dst == 'a')) {
        src = 'C';
        dst = 'A';
        tmp = 'B';
    }
    if ((src == 'C' || src == 'c') && (dst == 'B' || dst == 'b')) {
        src = 'C';
        dst = 'B';
        tmp = 'A';
    }

    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}