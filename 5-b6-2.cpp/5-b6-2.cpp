//2453805 唐先泽 电信
#include <iostream>
#include <iomanip>
using namespace std;
int sum = 0;
int a[3] = { 0 };
int b[3][10] = { {0},{0},{0} };
// A柱：b[0][1-10] B柱：b[1][1-10] C柱：b[2][1-10]
void print()
{
    cout<<"A:";
    for (int i = 0; i < 10; i++) {
        if (b[0][i] > 0) {
            printf("%2d", b[0][i]);
        }
        else {
            cout<<"  ";
        }
    }
    cout<<" ";
    cout<<"B:";
    for (int i = 0; i < 10; i++) {
        if (b[1][i] > 0) {
            printf("%2d", b[1][i]);
        }
        else {
            cout<<"  ";
        }
    }
    cout<<" ";
    cout<<"C:";
    for (int i = 0; i < 10; i++) {
        if (b[2][i] > 0) {
            printf("%2d", b[2][i]);
        }
        else {
            cout<<"  ";
        }
    }
    cout << endl;
}
void initialization(int n, char src) {
    cout << "初始:                ";
    switch (src) {
        case 'a':
        case 'A':
            a[0] = n;
            a[1] = 0;
            a[2] = 0;
            for (int i = 0; i < n; i++) {
                b[0][i] = n - i;
            }
            break; 
        case 'b':
        case 'B':
            a[0] = 0;
            a[1] = n;
            a[2] = 0;
            for (int i = 0; i < n; i++) {
                b[1][i] = n - i;
            }
            break;
        case 'c':
        case 'C':
            a[0] = 0;
            a[1] = 0;
            a[2] = n;
            for (int i = 0; i < n; i++) {
                b[2][i] = n - i;
            }
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
            b[1][a[1]++] = b[0][--a[0]];
            b[0][a[0]] = 0;
            break;
        case 'c':
        case 'C':
            b[2][a[2]++] = b[0][--a[0]];
            b[0][a[0]] = 0;
            break;

        }
        break;
    case 'b':
    case 'B':
        switch (increase) {
        case 'a':
        case 'A':
            b[0][a[0]++] = b[1][--a[1]];
            b[1][a[1]] = 0;
            break;
        case 'c':
        case 'C':
            b[2][a[2]++] = b[1][--a[1]];
            b[1][a[1]] = 0;
            break;

        }
        break;
    case 'c':
    case 'C':
        switch (increase) {
        case 'a':
        case 'A':
            b[0][a[0]++] = b[2][--a[2]];
            b[2][a[2]] = 0;
            break;
        case 'b':
        case 'B':
            b[1][a[1]++] = b[2][--a[2]];
            b[2][a[2]] = 0;
            break;

        }
        break;
    }
    cout<<" ";
    print();
}
void hanoi(int n, char src, char tmp, char dst)
{

    if (n == 1) {
        sum++;
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << setw(2) << "1" <<")" << ": " << src << "-->" << dst;
        print_num(src, dst);
    }
    else if (n == 2) {
        sum++;
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << setw(2) << "1" << ")" << ": " << src << "-->" << tmp;
        print_num(src, tmp);
        sum++;
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << setw(2) << "2" << ")" << ": " << src << "-->" << dst;
        print_num(src, dst);
        sum++;
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << setw(2) << "1" << ")" << ": " << tmp << "-->" << dst;
        print_num(tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        sum++;
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst;
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
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else {
            if (n < 1 || n>10) {
                cin.ignore(1024, '\n');
                continue;
            }
            else {
                cin.ignore(1024, '\n');
                break;
            }
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else {
            if (src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
                cin.ignore(1024, '\n');
                break;
            }
            else {
                cin.ignore(1024, '\n');
                continue;
            }
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail()) {
            cin.ignore(1024, '\n');
            cin.clear();
            continue;
        }
        else {
            if (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c') {

                if ((src == 'A' || src == 'a') && (dst == 'A' || dst == 'a')) {
                    cin.ignore(INT_MAX, '\n');
                    cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                    continue;
                }
                else if ((src == 'B' || src == 'b') && (dst == 'B' || dst == 'b')) {
                    cin.ignore(INT_MAX, '\n');
                    cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                    continue;
                }
                else if ((src == 'C' || src == 'c') && (dst == 'C' || dst == 'c')) {
                    cin.ignore(INT_MAX, '\n');
                    cout << "目标柱(C)不能与起始柱(C)相同" << endl;
                    continue;
                }

                else {
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
            else {
                cin.ignore(INT_MAX, '\n');
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

    
    initialization(n, src);
    hanoi(n, src, tmp, dst);

    return 0;
}