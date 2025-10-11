//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include"5-b7.h"
const int X = 10;
const int Y = 20;
using namespace std;
int sum = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int top_a = 0;
int top_b = 0;
int top_c = 0;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void move_speed(int speed)//控制速度
{
    if (speed == 0) {
        while (1) {
			char ch = _getch();
			if (ch == 13) { // Enter key
                break;
            }

        }
	}
	else if (speed == 1) {
		Sleep(1000);
	}
	else if (speed == 2) {
		Sleep(500);
	}
	else if (speed == 3) {
		Sleep(200);
	}
	else if (speed == 4) {
		Sleep(50);
	}
    else if (speed == 5) {
        Sleep(0);
    }
}


void print_first_line(char src, char dst, int n, int speed, int show)//打印第一行
{
	cct_cls();
	cct_gotoxy(0, 0);
    if (show == 0) {
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层," << "延时设置为 " << speed << ",不显示内部数组值" << endl;
    }
    else {
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层," << "延时设置为 " << speed << ",显示内部数组值" << endl;
    }
}



void print()//打印每个柱子上的数字
{
    cout<<"A:";
    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) {
			cout << setw(2) << a[i];
        }
        else {
            cout<<"  ";
        }
    }
    cout<<" ";
    cout<<"B:";
    for (int i = 0; i < 10; i++) {
        if (b[i] > 0) {
			cout << setw(2) << b[i];
        }
        else {
            cout << "  ";
        }
    }
    cout << " ";
    cout << "C:";
    for (int i = 0; i < 10; i++) {
        if (c[i] > 0) {
			cout << setw(2) << c[i];
        }
        else {
            cout<<"  ";
        }
    }
    cout << endl;
}


void print_img();

void initialization(int n, char src,int show)//最开始的状态
{
    cct_gotoxy(X, Y);
    if (show) {
        cout<<"初始:                ";
    }
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
    if (show) {
        print();
    }
    print_img();

}

void move_num(char decline, char increase, int show)//移动数组中的数字并打印
{
    if (decline == 'a' || decline == 'A') {
        if (increase == 'b' || increase == 'B') {
            b[top_b++] = a[--top_a];
            a[top_a] = 0;
        }
        else if (increase == 'c' || increase == 'C') {
            c[top_c++] = a[--top_a];
            a[top_a] = 0;
        }
    }
    else if (decline == 'b' || decline == 'B') {
        if (increase == 'a' || increase == 'A') {
            a[top_a++] = b[--top_b];
            b[top_b] = 0;
        }
        else if (increase == 'c' || increase == 'C') {
            c[top_c++] = b[--top_b];
            b[top_b] = 0;
        }
    }
    else if (decline == 'c' || decline == 'C') {
        if (increase == 'a' || increase == 'A') {
            a[top_a++] = c[--top_c];
            c[top_c] = 0;
        }
        else if (increase == 'b' || increase == 'B') {
            b[top_b++] = c[--top_c];
            c[top_c] = 0;
        }
    }
    if (show) {
        cout << " ";
        print();
    }
    print_img();
}


void print_img()//打印图像
{
    cct_gotoxy(X - 5, Y - 5);
    cout << "=========================";
    cct_gotoxy(X - 3, Y - 4);
    cout << "A         B         C";
	for (int i = 9; i >= 0; i--) {
        if (a[i] > 0) {
            cct_gotoxy(X - 5, Y - 6 - i);
            cout << setw(3) << a[i];
        }
        else {
			cct_gotoxy(X - 5, Y - 6 - i);
			cout << "   ";
        }
	}
	for (int i = 9; i >= 0; i--) {
		if (b[i] > 0) {
			cct_gotoxy(X + 5, Y - 6 - i);
			cout << setw(3) << b[i];
		}
		else {
			cct_gotoxy(X + 5, Y - 6 - i);
			cout << "   ";
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (c[i] > 0) {
			cct_gotoxy(X + 15, Y - 6 - i);
			cout << setw(3) << c[i];
		}
		else {
			cct_gotoxy(X + 15, Y - 6 - i);
			cout << "   ";
		}
	}

}




/***************************************************************************
  函数名称：hanoi
  功    能：汉诺塔核心函数
  输入参数：n：当前操作的总层数，src：起始柱，tmp：临时柱，dst：目标柱，
			speed：速度，show：是否显示内部数组值
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,int speed,int show)
{
    if (n == 1) {
        sum++;
		cct_gotoxy(X, Y);
		cout << "第" << setw(4) << sum << "步";  
		cout << "(" << 1 << "#: " << src << "-->" << dst << ")";
        move_num(src, dst,show);
		move_speed(speed);
    }
    else if (n == 2) {
        sum++;
        cct_gotoxy(X, Y);
        cout << "第" << setw(4) << sum << "步";
        cout << "(" << 1 << "#: " << src << "-->" << tmp << ")";
        move_num(src, tmp, show);
        move_speed(speed);
        sum++;

        cct_gotoxy(X, Y);
        cout << "第" << setw(4) << sum << "步";
        cout << "(" << 2 << "#: " << src << "-->" << dst << ")";
        move_num(src, dst, show);
        move_speed(speed);
        sum++;

        cct_gotoxy(X, Y);
        cout << "第" << setw(4) << sum << "步";
        cout << "(" << 1 << "#: " << tmp << "-->" << dst << ")";

        move_num(tmp, dst, show);

        move_speed(speed);
    }
    else {
        hanoi(n - 1, src, dst, tmp, speed,show);
        sum++;
        
        cct_gotoxy(X, Y);
		cout << "第" << setw(4) << sum << "步";
		cout << "(" << n << "#: " << src << "-->" << dst << ")";
        move_num(src,dst,show);
		move_speed(speed);
        hanoi(n - 1, tmp, src, dst,speed,show);
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
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else {
            if (n < 1 || n>10) {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            else {
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else {
            if (src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
                cin.ignore(INT_MAX, '\n');
                break;
            }
            else {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail()) {
            cin.ignore(INT_MAX, '\n');
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
    int speed;
    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (speed < 0 || speed > 5) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else {
				cin.ignore(INT_MAX, '\n');
				break;
			}
		}
    }
    int show;
	cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
	cin >> show;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (show < 0 || show > 1) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else {
				cin.ignore(INT_MAX, '\n');
				break;
			}
		}
	}
	print_first_line(src, dst, n, speed, show);
	initialization(n, src,show);
	move_speed(speed);
	hanoi(n, src, tmp, dst, speed,show);

	cct_gotoxy(X, Y + 5);
    cout << endl;

	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}