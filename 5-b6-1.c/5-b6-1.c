//2453805 唐先泽 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int top_a = 0;
int top_b = 0;
int top_c = 0;

void print() 
{
    printf("A:");
    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) {
            printf("%2d", a[i]);
        }
        else {
            printf("  ");
        }
    }
    printf(" ");
    printf("B:");
    for (int i = 0; i < 10; i++) {
        if (b[i] > 0) {
            printf("%2d", b[i]);
        }
        else {
            printf("  ");
        }
    }
    printf(" ");
    printf("C:");
    for (int i = 0; i < 10; i++) {
        if (c[i] > 0) {
            printf("%2d", c[i]);
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}
void initialization(int n,char src)
{
    printf("初始:                ");
    switch (src) {
        case 'a':
        case 'A':
            for (int i = 0; i < n; i++) {
                a[i] = n - i;
            }
            top_a = n;
            break;
        case 'b':
        case 'B':
            for (int i = 0; i < n; i++) {
                b[i] = n - i;
            }
            top_b = n;
            break;
        case 'c':
        case 'C':
            for (int i = 0; i < n; i++) {
                c[i] = n - i;
            }
            top_c = n;
            break;
    }
    print();

}
void print_num(char decline, char increase)
{
    switch (decline) {
        case 'a':
        case 'A':
            switch (increase) {
                case 'b':
                case 'B':
                    b[top_b++] = a[--top_a];
                    a[top_a] = 0;
                    break;
                case 'c':
                case 'C':
                    c[top_c++] = a[--top_a];
                    a[top_a] = 0;
                    break;

            }
            break;
        case 'b':
        case 'B':
            switch (increase) {
            case 'a':
            case 'A':
                a[top_a++] = b[--top_b];
                b[top_b] = 0;
                break;
            case 'c':
            case 'C':
                c[top_c++] = b[--top_b];
                b[top_b] = 0;
                break;

            }
            break;
        case 'c':
        case 'C':
            switch (increase) {
            case 'a':
            case 'A':
                a[top_a++] = c[--top_c];
                c[top_c] = 0;
                break;
            case 'b':
            case 'B':
                b[top_b++] = c[--top_c];
                c[top_c] = 0;
                break;

            }
            break;
    }
    printf(" ");
    print();
}

void hanoi(int n, char src, char tmp, char dst)
{

    if (n == 1) {
        sum++;
        printf("第%4d 步", sum);
        printf("(%2d): %c-->%c", 1, src, dst);
        print_num(src, dst);
    }
    else if (n == 2) {
        sum++;
        printf("第%4d 步", sum);
        printf("(%2d): %c-->%c", 1, src, tmp);
        print_num(src, tmp);
        sum++;
        printf("第%4d 步", sum);
        printf("(%2d): %c-->%c", 2, src, dst);
        print_num(src, dst);
        sum++;
        printf("第%4d 步", sum);
        printf("(%2d): %c-->%c", 1, tmp, dst);
        print_num(tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        sum++;
        printf("第%4d 步", sum);
        printf("(%2d): %c-->%c", n, src, dst);
        print_num(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;//汉诺塔层数
    char src, dst, tmp;//起始柱、目标柱
    tmp = ' ';
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret = scanf("%d", &n);
        if (ret == 0) {
            while (getchar() != '\n');
            continue;
        }
        else {
            if (n < 1 || n>10) {
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
        if (ret == 0) {
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
        if (ret == 0) {
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

    initialization(n,src);
    hanoi(n, src, tmp, dst);

    return 0;
}