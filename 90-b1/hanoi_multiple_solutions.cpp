//2453805 唐先泽 电信
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi_const_value.h"
#include "cmd_hdc_tools.h"
using namespace std;
int speed = 0;
int sum = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int top_a = 0;
int top_b = 0;
int top_c = 0;

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
//控制X
int x_func(int choice)
{
    if (choice == 4) {
        return MenuItem4_Start_X;
    }
    else if (choice == 8 || choice == 9) {
        return MenuItem8_Start_X;
    }
    else {
        return 0;
    }
}
//控制Y
int y_func(int choice)
{
    if (choice == 4) {
        return MenuItem4_Start_Y;
    }
    else if (choice == 8 || choice == 9) {
        return MenuItem8_Start_Y;
    }
    else {
        return 0;
    }
}
//小写转大写
char my_toupper(char ch)
{
    if (ch >= 97 && ch <= 122) {
        return ch - 32;
    }
    else {
        return ch;
    }
}
//延时设置
void move_time()
{
    if (speed == 0) {
        while (1) {
            char ch = _getch();
            if (ch == 13) {
                break;
            }
        }
    }
    else {
        Sleep(speed);
    }
}
//打印第一行
void print_first_line(char src, char dst, int n,int choice)
{
    if (choice != 8&&choice!=9)
        cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    if (choice == 4) {
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层" << ",延时设置为 " << speed << "ms" << endl;
    }
    if (choice==6||choice == 7||choice==9) {
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层" << endl;
    }
    if (choice == 8) {
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层" << ",延时设置为 " << speed << "ms（前7步，后面自动变为0ms）" << endl;
    }
    
}
//输入层数，返回层数
int input_layer_num()
{
    int n;
    cout << endl;
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
                return n;
            }
        }
    }
}
//输入起始柱，返回起始柱
char input_src()
{
    char src;
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
                return my_toupper(src);
            }
            else {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
        }
    }
}
//输入目标柱，返回目标柱
char input_dst(char src)
{
    char dst;
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
                if (my_toupper(dst) == src) {
                    cin.ignore(INT_MAX, '\n');
                    cout << "目标柱("<<src<<")不能与起始柱("<<src<<")相同" << endl;
                    continue;
                }
                else {
                    return my_toupper(dst);
                }
            }
            else {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
        }
    }
}
//得到中间柱
char get_tmp(char src,char dst)
{
    return 'A' + 'B' + 'C' - src - dst;
}
void output(int n, int choice, int sum, char src, char dst);
void move_num(char decline, char increase, int choice);

//打印每个柱子上的数字(横向输出)
void print()
{
    cout << "A:";
    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) {
            cout << setw(2) << a[i];
        }
        else {
            cout << "  ";
        }
    }
    cout << " ";
    cout << "B:";
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
            cout << "  ";
        }
    }
    cout << endl;
}
//打印数组图像(纵向)
void print_img(const int x,const int y)
{
    cct_gotoxy(x + Underpan_A_X_OFFSET-2, y + Underpan_A_Y_OFFSET-1);
    cout << setfill('=') << setw(2 * Underpan_Distance + 5) << "=";
    cct_gotoxy(x +Underpan_A_X_OFFSET, y+Underpan_A_Y_OFFSET);
    cout << "A"<<setfill(' ') << setw(Underpan_Distance - 1) << " " << "B" << setw(Underpan_Distance - 1) << " " << "C";
    for (int i = 9; i >= 0; i--) {
        if (a[i] > 0) {
            cct_gotoxy(x + Underpan_A_X_OFFSET, y + Underpan_A_Y_OFFSET-2 - i);
            cout << a[i];
        }
        else {
            cct_gotoxy(x + Underpan_A_X_OFFSET, y + Underpan_A_Y_OFFSET - 2 - i);
            cout << "   ";
        }
    }
    for (int i = 9; i >= 0; i--) {
        if (b[i] > 0) {
            cct_gotoxy(x + Underpan_A_X_OFFSET+ Underpan_Distance, y + Underpan_A_Y_OFFSET - 2 - i);
            cout << b[i];
        }
        else {
            cct_gotoxy(x + Underpan_A_X_OFFSET + Underpan_Distance, y + Underpan_A_Y_OFFSET - 2 - i);
            cout << "   ";
        }
    }
    for (int i = 9; i >= 0; i--) {
        if (c[i] > 0) {
            cct_gotoxy(x + Underpan_A_X_OFFSET + 2*Underpan_Distance, y + Underpan_A_Y_OFFSET - 2 - i);
            cout << c[i];
        }
        else {
            cct_gotoxy(x + Underpan_A_X_OFFSET + 2 * Underpan_Distance, y + Underpan_A_Y_OFFSET - 2 - i);
            cout << "   ";
        }
    }
}
//盘子延时设置
void move_plate_time(int choice)
{
    if (choice == 8 && sum > 7) {
        Sleep(0);
    }
    else {
        move_time();
    }
}

//画移动盘子
void move_plate(char decline,char increase,int choice)
{
    int temp[3][10] = { 0 }, num_top[3] = {top_a,top_b,top_c};
    for (int i = 0; i < 10; i++) {
        temp[0][i] = a[i];
        temp[1][i] = b[i];
        temp[2][i] = c[i];
    }
    int dec_num = decline - 65;
    int inc_num = increase - 65;
    int num_plate = temp[inc_num][num_top[inc_num]-1];
    int width = (2 * num_plate + 1) * HDC_Base_Width;
    int height = HDC_Base_High;
    int color = HDC_COLOR[num_plate];
    int plate_x = HDC_Start_X + dec_num * (23 * HDC_Base_Width + HDC_Underpan_Distance) + 23 * HDC_Base_Width / 2 - width / 2;
    int plate_y = HDC_Start_Y - height * (num_top[dec_num] + 1);
    int move_x_distance = (increase - decline) * (HDC_Underpan_Distance + 23 * HDC_Base_Width);
    while (plate_y >= HDC_Top_Y) {
        hdc_rectangle(plate_x, plate_y + height - HDC_Step_Y, width, HDC_Step_Y, HDC_COLOR[0]);//涂抹
        if (plate_y > HDC_Start_Y - 13 * height)
            hdc_rectangle(plate_x + (width - HDC_Base_Width) / 2, plate_y + height - HDC_Step_Y, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);//恢复立柱
        plate_y -= HDC_Step_Y;
        hdc_rectangle(plate_x, plate_y, width, HDC_Step_Y, color);//上移
        move_plate_time(choice);
    }
    if (move_x_distance > 0) {
        for (int i = 0; i < (move_x_distance/HDC_Step_X); i++) {
            hdc_rectangle(plate_x, plate_y, HDC_Step_X, height, HDC_COLOR[0]);//涂抹
            hdc_rectangle(plate_x + width, plate_y, HDC_Step_X, height, color);//右移
            plate_x += HDC_Step_X;
            move_plate_time(choice);
        }
    }
    else {
        for (int i = 0; i < (fabs(move_x_distance) / HDC_Step_X); i++) {
            hdc_rectangle(plate_x + width - HDC_Step_X, plate_y, HDC_Step_X, height, HDC_COLOR[0]);//涂抹
            plate_x -= HDC_Step_X;
            hdc_rectangle(plate_x, plate_y, HDC_Step_X, height, color);//左移
            move_plate_time(choice);
        }
    }
    while (plate_y + num_top[inc_num]*height < HDC_Start_Y) {
        hdc_rectangle(plate_x, plate_y, width, HDC_Step_Y, HDC_COLOR[0]);//涂抹
        if (plate_y >= HDC_Start_Y - 12 * height) {
            hdc_rectangle(plate_x + (width - HDC_Base_Width) / 2, plate_y, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);//恢复立柱
        }
        hdc_rectangle(plate_x, plate_y+height, width, HDC_Step_Y, color);//下移
        plate_y += HDC_Step_Y;
        move_plate_time(choice);
    }
}


//移动数组中的数字并调用函数打印
void move_num(char decline, char increase,int choice)
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
    if (choice != 7)//3,4,8,9横向数组
        print();
    if (choice == 4 ||choice==8||choice==9) //4,8,9纵向数组
        print_img(x_func(choice), y_func(choice));
    if (choice == 7||choice==8||choice==9)
        move_plate(decline, increase,choice);
}
//通过调用函数输出对应choice的全部需求
void output(int n, int choice, int sum, char src, char dst)
{
    if (choice == 1) {
        cout << n << "# " << src << "---->" << dst << endl;
    }
    else {
        if (choice == 4) {
            cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        }
        if (choice == 8 || choice == 9) {
            cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
        }
        if (choice != 7) {
            cout << "第" << setw(4) << sum << "步";
            cout << "(" << n << "#: " << src << "-->" << dst << ") ";
        }
        if (choice == 2) {
            cout << endl;
        }
        if (choice == 3) {
            move_num(src, dst, choice);
        }
        if (choice == 4 || choice == 8||choice==9) {
            move_num(src, dst, choice);
            move_time();
        }
        if (choice == 7) {
            if (sum < 2)
                move_num(src, dst, choice);
            else
                return;
        }
    }
}
void draw_pillar_base();
//初始化
void initialization(int n, char src,char dst, int choice)//最开始的状态
{
    if (choice == 8||choice==9)
        print_first_line(src, dst, n, choice);
    cct_gotoxy(x_func(choice), y_func(choice));
    cout << "初始:                ";
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
    if (choice != 7) {
        print();
        print_img(x_func(choice), y_func(choice));
    }
    if (choice == 8||choice==9)
        draw_pillar_base();
}
//画底盘和柱子
void draw_pillar_base()
{
    hdc_cls();
    hdc_rectangle(HDC_Start_X, HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X+ 23 * HDC_Base_Width+HDC_Underpan_Distance, HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X +2*( 23 * HDC_Base_Width + HDC_Underpan_Distance), HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X+ 22 * HDC_Base_Width/2, HDC_Start_Y-12*HDC_Base_High, HDC_Base_Width, 12*HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 22 * HDC_Base_Width / 2 + 23 * HDC_Base_Width + HDC_Underpan_Distance, HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, 12 * HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 22 * HDC_Base_Width / 2 + 2 * (23 * HDC_Base_Width + HDC_Underpan_Distance), HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, 12 * HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
}
//画盘子
void draw_plate(char src,int n)
{
    int temp[3][10] = {0};
    for (int i = 0; i < 10; i++) {
        temp[0][i] = a[i];
        temp[1][i] = b[i];
        temp[2][i] = c[i];
    }
    int src_num = src - 65;//src_num:0,1,2 ->A,B,C
    for (int i = 0; i < n;i++) {
        int c = temp[src_num][i];
        hdc_rectangle(HDC_Start_X + src_num * (23 * HDC_Base_Width + HDC_Underpan_Distance) + (11 - n + i) * HDC_Base_Width, HDC_Start_Y - (i + 1) * HDC_Base_High, (2 * n - 2 * i + 1) * HDC_Base_Width, HDC_Base_High,HDC_COLOR[n-i]);
        Sleep(HDC_Init_Delay);
    }
}

//汉诺塔递归
void hanoi(int n, char src, char tmp, char dst,int choice)
{
    if (n == 1) {
        sum++;
        output(1,choice,sum,src,dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp,choice);
        sum++;
        output(n, choice, sum, src, dst);
        hanoi(n - 1, tmp, src, dst,choice);
    }
}
//选项1、2
void first_second_func(int n, char src, char tmp, char dst,int choice)
{
    hanoi(n, src, tmp, dst, choice);
}
void third_func(int n, char src, char tmp, char dst, int choice)
{
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
    hanoi(n, src, tmp, dst, choice);
}
//选项4
void fourth_func(char src,char tmp,char dst,int n)
{
    print_first_line(src, dst, n,4);
    initialization(n, src,dst, 4);
    move_time();
    hanoi(n, src, tmp, dst, 4);
}
//选项5
void fifth_func()
{
    cct_cls();
    hdc_init(RGB(255, 255, 255), RGB(0, 0, 0), 8 * 120, 16 * 30);
    draw_pillar_base();
}
//选项6
void sixth_func(char src,char dst,int n,int choice)
{
    hdc_init(RGB(255, 255, 255), RGB(0, 0, 0), 8 * 120, 16 * 30);
    print_first_line(src, dst, n, choice);
    draw_pillar_base();
    draw_plate(src, n);

}
//选项7
void seventh_func(char src,char tmp, char dst, int n, int choice)
{
    initialization(n, src,dst, choice);
    hdc_init(RGB(255, 255, 255), RGB(0, 0, 0), 8 * 120, 16 * 30);
    print_first_line(src, dst, n, choice);
    draw_pillar_base();
    draw_plate(src, n);
    hanoi(n, src, tmp, dst, choice);
}
//选项8
void eighth_func(char src, char tmp, char dst, int n, int choice)
{
    cct_cls();
    hdc_init(RGB(255, 255, 255), RGB(0, 0, 0), 8 * 120, 16 * 30);
    initialization(n, src,dst, choice);
    draw_plate(src, n);
    hanoi(n, src, tmp, dst, choice);
}
//选项9出错后重置
void reset(char src,char dst,int n,int mistake) {
    cct_gotoxy(x_func(9), y_func(9) + 2);
    if (mistake == 0) {
        cout << "源柱为空!                        ";
    }
    else {
        cout << "大盘压小盘，非法移动!";
    }
    Sleep(1000);
    cct_gotoxy(x_func(9), y_func(9) + 2);
    cout << "                                           ";
    print_first_line(src, dst, n, 9);
}
//选项9问问题
void query(int n,char src, char dst) {
    while (1) {
        cct_gotoxy(x_func(9), y_func(9)+1);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：          ";
        cct_gotoxy(x_func(9) + 60, y_func(9) + 1);
        int temp[3][10] = { 0 }, top[3] = {top_a,top_b,top_c};
        char ch[20] = { 0 };
        for (int i = 0; i < 10; i++) {
            temp[0][i] = a[i];
            temp[1][i] = b[i];
            temp[2][i] = c[i];
        }
        cin.getline(ch, 20);
        if ((my_toupper(ch[0]) == 'q' || my_toupper(ch[0]) == 'Q') && ch[1] == 0) {
            cct_gotoxy(x_func(9), y_func(9) + 2);
            cout << "游戏终止!!!!!                        ";
            return;
        }
        else if (my_toupper(ch[0]) >= 'A' && my_toupper(ch[0]) <= 'C' && my_toupper(ch[1]) >= 'A' && my_toupper(ch[1]) <= 'C' && ch[2] == 0&&my_toupper(ch[0])!=my_toupper(ch[1])) {
            if (top[my_toupper(ch[0])-'A']==0) {//判断源柱是否为空
                reset(src, dst, n ,0);
                continue;
            }
            else if (top[my_toupper(ch[1]) - 'A'] != 0 &&temp[my_toupper(ch[0]) - 'A'][top[my_toupper(ch[0]) - 'A']-1]> temp[my_toupper(ch[1]) - 'A'][top[my_toupper(ch[1]) - 'A'] - 1]) {//判断是否大盘压小盘
                reset(src, dst, n,1);
                continue;
            }
            else {
                sum++;
                output(temp[my_toupper(ch[0]) - 'A'][top[my_toupper(ch[0]) - 'A'] - 1], 9, sum, my_toupper(ch[0]), my_toupper(ch[1]));
                top[0] = top_a;
                top[1] = top_b;
                top[2] = top_c;
                if (top[my_toupper(ch[1]) - 'A'] == n && my_toupper(ch[1]) == dst) {
                    cct_gotoxy(x_func(9), y_func(9) + 2);
                    cout << "游戏结束!!!!!                        ";
                    return;
                }
            }
        }
        else
            continue;
    }
}
//选项9
void ninth_func(char src, char tmp, char dst, int n, int choice)
{
    cct_cls();
    hdc_init(RGB(255, 255, 255), RGB(0, 0, 0), 8 * 120, 16 * 30);
    initialization(n, src, dst, choice);
    draw_plate(src, n);
    query(n,src, dst);
    
}

//选项4延时设置
void fourth_time_record()
{
    while (1) {
        cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms)";
        cin >> speed;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else {
            if (speed < 0 || speed > 200) {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            else {
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
    }
}

// 选项7、8延时设置
void seventh_eighth_time_record()
{
    while (1) {
        cout << "请输入移动速度(0-20：0-按回车单步演示 1-20:延时1-20ms)";
        cin >> speed;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else {
            if (speed < 0 || speed > 20) {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            else {
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
    }
}
//选项9延时设置
void ninth_time_record()
{
    while (1) {
        cout << "请输入移动速度(1-20:延时1-20ms)";
        cin >> speed;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else {
            if (speed < 1 || speed > 20) {
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            else {
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
    }
}
//选项1,2,3,4,5,6,7,8,9输入所有参数
void all_input(int* num, char* src, char* dst, char* tmp,int choice)
{
    *num = input_layer_num();
    *src = input_src();
    *dst = input_dst(*src);
    *tmp = get_tmp(*src, *dst);
    if (choice == 4) {
        fourth_time_record();
    }
    if (choice == 7||choice==8) {
        seventh_eighth_time_record();
    }
    if (choice == 9) {
        ninth_time_record();
    }
}
//每次开始前重置数组
void starting_set()
{
    sum = 0;
    top_a = 0;
    top_b = 0;
    top_c = 0;
    for (int i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
}
   /***************************************************************************
	 函数名称：select
	 功    能：接收菜单输入，执行对应函数
	 输入参数：int choice(1-9)
	 返 回 值：
	 说    明：
   ***************************************************************************/
void select(int choice)
{
    int num ;
    char src,dst,tmp;
    starting_set();
    if (choice == 1||choice==2) {
        all_input(&num, &src, &dst, &tmp,choice);
        first_second_func(num, src, tmp, dst,choice);
	}
    if (choice == 3) {
        all_input(&num, &src, &dst, &tmp, choice);
        third_func(num, src, tmp, dst, choice);
    }
    if (choice == 4) {
        all_input(&num, &src, &dst, &tmp, choice);
        fourth_func(src, tmp, dst, num);
    }
    if (choice == 5) {
        fifth_func();
    }
    if (choice == 6) {
        all_input(&num, &src, &dst, &tmp, choice);
        sixth_func(src, dst, num, choice);
    }
    if (choice == 7) {
        all_input(&num, &src, &dst, &tmp, choice);
        seventh_func(src, tmp, dst, num, choice);
    }
    if (choice == 8) {
        all_input(&num, &src, &dst, &tmp, choice);
        eighth_func(src, tmp, dst, num, choice);
    }
    if (choice == 9) {
        all_input(&num, &src, &dst, &tmp, choice);
        ninth_func(src, tmp, dst, num, choice);
    }
    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
}










