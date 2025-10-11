//2453805 唐先泽 电信
#include<iostream>
using namespace std;

#define        N    2000
#define        END_NUM        -1

void input(int* array, const int n) {
    int* p = array;
    for (int i = 0; i < n; i++) {
        cin >> *p;
        if (*p == END_NUM) break;
        p++;
    }
}

void output(int* array, const int n) {
    int* p = array;
    int count = 0; // 记录已输出元素个数
    while (*p != END_NUM && count < N) { // 防止越界
        cout << *p << " ";
        count++;
        if (count % n == 0) 
            cout << endl; // 每n个换行
        p++;
    }
    cout << endl; // 确保最后有换行（可选）
}

void adjust(int* array) {
    int t, * p1, * p2;
    p1 = p2 = array;

    // 定位到最后一个有效元素（非END_NUM）
    while (*p2 != END_NUM && p2 < array + N) 
        p2++;
    if (p2 > array) 
        p2--; // 若存在有效元素，回退到最后一个

    // 双指针交换奇偶位置
    while (p1 < p2) {
        // p1找偶数
        while (p1 < p2 && *p1 % 2 != 0) 
            p1++;
        // p2找奇数
        while (p1 < p2 && *p2 % 2 == 0) 
            p2--;
        // 交换
        if (p1 < p2) {
            t = *p1;
            *p1 = *p2;
            *p2 = t;
            p1++; // 移动避免重复处理
        }
    }
}

int main(int argc, char** argv) {
    int a[N + 1];

    cout << "请输入数组各元素(正整数),以" << END_NUM << "结束(不含" << END_NUM << "最多" << N << "个数)" << endl;
    input(a, N);

    cout << "数组的内容为" << endl;
    output(a, 15);

    adjust(a);
    cout << "调整后数组的内容为" << endl;
    output(a, 10);

    return 0;
}