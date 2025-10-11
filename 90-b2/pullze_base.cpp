//2453805 唐先泽 电信
#include <iostream>
#include<iomanip>
#include"pullze.h"
#include"cmd_console_tools.h"
#define WIDTH   11
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int area_size()
{
	int n;
	while (1) {
		cout << "请输入区域大小(5/10/15) ：";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
			continue;
		}
		else {
			if (n != 5 && n != 10 && n != 15) {
				continue;
			}
			else
				return n;
		}
	}
}
void draw_array(int size, char* array,int*remind_row,int*remind_col,char choice,int width,int height,int &x,int &y)
{
	if (choice == 'B'||choice=='C') {
		for (int i = 0; i < 2 * width + 3; i++) {
			cout << "-";
		}
		cout << "+";
		for (int k = 0; k < size / 5; k++) {
			for (int m = 0; m < WIDTH; m++) {
				cout << "-";
			}
			cout << "+";
		}
		cout << endl;
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < 2 * width + 3; i++) {
				cout << " ";
			}
			cout << "|";
			for (int k = 0; k < size; k++) {
				if (remind_col[size * k + j] == 0)
					cout << "  ";
				else
					cout << setw(2)<< remind_col[size * k + j];
				if ((k + 1) % 5 == 0) {
					cout << " |";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < 2 * width + 3; i++) {
			cout << "-";
		}
		cout << "+";
		for (int k = 0; k < size / 5; k++) {
			for (int m = 0; m < WIDTH; m++) {
				cout << "-";
			}
			cout << "+";
		}
		cout << endl;
		for (int i = 0; i < 2 * width + 3; i++) {
			cout << " ";
		}
		cout << "|";
		for (int i = 0; i < size; i++) {
			cout << " " << char('a' + i);
			if ((i + 1) % 5 == 0) {
				cout << " |";
			}
		}
		cout << endl;
	}

	if (choice == 'A') {
		cout << "+-+";
		for (int i = 0; i < size / 5; i++) {
			for (int j = 0; j < WIDTH; j++) {
				cout << "-";
			}
			cout << "+";
		}
		cout << endl;
		cout << "| |";
		for (int i = 0; i < size; i++) {
			cout << " " << char('a' + i);
			if ((i + 1) % 5 == 0) {
				cout << " |";
			}
		}
		cout << endl;

	}


	if (choice == 'B'||choice=='C') {
		for (int i = 0; i < 2 * width + 1; i++) {
			cout << "-";
		}
	}


	cout << "+-+";
	cct_getxy(x, y); // 获取当前光标位置
	for (int i = 0; i < size / 5; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << "-";
		}
		cout << "+";
	}
	cout << endl;


	for (int i = 0; i < size; i++)
	{
		if (choice == 'B'||choice=='C') {
			for (int k = 0; k < width; k++) {
				if (remind_row[size * i + k] == 0) {
					cout << "  ";
				}
				else {
					cout << setw(2) << remind_row[size * i + k];
				}
			}
			cout << " ";
		}
		cout << "|" << char('A' + i) << "|";
		for (int j = 0; j < size; j++) {
			if (array[size * i + j] == 0)
				cout << "  ";
			else
				if (choice == 'C')
					cout << "  ";
				else
				    cout << " " << array[size * i + j];
			if ((j + 1) % 5 == 0) {
				cout << " |";
			}
		}
		cout << endl;
		if ((i + 1) % 5 == 0) {
			if (choice == 'B'||choice=='C') {
				for (int k = 0; k < 2 * width + 1; k++) {
					cout << "-";
				}
			}
			cout << "+-+";
			for (int k = 0; k < size / 5; k++) {
				for (int m = 0; m < WIDTH; m++) {
					cout << "-";
				}
				cout << "+";
			}
			cout << endl;
		}
	}

}
char* array_choice(int size,char* a,char* b,char* c)
{
	if (size==5) {
		return a;
	}
	else if (size==10) {
		return b;
	}
	else if (size==15) {
		return c;
	}
	else {
		return 0;
	}
}
int* array_remind_choice(int size, int* a_row, int* b_row, int* c_row)
{
	if (size == 5) {
		return a_row;
	}
	else if (size == 10) {
		return b_row;
	}
	else if (size == 15) {
		return c_row;
	}
	else {
		return 0;
	}
}

int row_remind(int*remind_row,char*array,int size)
{
	int width = 0;
	for (int i = 0; i < size; i++) {
		int count = 0;
		int loc = 0;
		for (int j = 0; j < size; j++) {
			if (array[size * i + j] == '0') {
				count++;
			}
			else {
				if (count == 0) {
					continue;
				}
				else {
					remind_row[size * i + loc] = count;
					count = 0;
					loc++;
				}
			}
		}
		if (count != 0) { // 如果行末尾还有0
			remind_row[size * i + loc] = count;
			loc++;
		}
		if (width < loc) {
			width = loc;
		}
	}
	//调整元素位置以便输出
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < width; j++) {
			if (remind_row[i * size + j] != 0) {
				count++;
			}
			else
				break;
		}
		if (count < width) {
			for (int k = 0; k < count; k++) {
				remind_row[size * i + width - 1 - k] = remind_row[size * i + count - 1 - k];
			}
			for (int k = 0; k < width - count; k++) {
				remind_row[size * i + k] = 0;
			}
		}
	}
	return width;
}

int col_remind(int* remind_col, char* array, int size)
{
	int height = 0;
	for (int i = 0; i < size; i++) {
		int count = 0;
		int loc = 0;
		for (int j = 0; j < size; j++) {
			if (array[j * size + i] == '0') {
				count++;
			}
			else {
				if (count == 0) {
					continue;
				}
				else {
					remind_col[size * i + loc] = count;
					count = 0;
					loc++;
				}
			}
		}
		if (count != 0) { // 如果列末尾还有0
			remind_col[size * i + loc] = count;
			loc++;
		}
		if (height < loc) {
			height = loc;
		}
	}
	//调整元素位置以便输出
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < height; j++) {
			if (remind_col[i * size + j] != 0) {
				count++;
			}
			else
				break;
		}
		if (count < height) {
			for (int k = 0; k < count; k++) {
				remind_col[size * i + height - 1 - k] = remind_col[size * i +count-1-k];
			}
			for (int k = 0; k < height - count; k++) {
				remind_col[size * i + k] = 0;
			}
		}
	}
	return height;
}

int compare(int size, char* user, int* remind_row, int* remind_col)
{
	int a_row[25] = { 0 };
	int b_row[100] = { 0 };
	int c_row[225] = { 0 };
	int a_col[25] = { 0 };
	int b_col[100] = { 0 };
	int c_col[225] = { 0 };
	int* row = array_remind_choice(size, a_row, b_row, c_row);
	int* col = array_remind_choice(size, a_col, b_col, c_col);
	int width = row_remind(row, user, size);
	int height = col_remind(col, user, size);

	bool hasInput = false;
	for (int i = 0; i < size * size; ++i) {
		if (user[i] == '0') {
			hasInput = true;
			break;
		}
	}
	if (!hasInput) 
		return 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < width; j++) {
			if (remind_row[size * i + j] != row[size * i + j]) {
				return 0; //行不匹配
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < height; j++) {
			if (remind_col[size * i + j] != col[size * i + j]) {
				return 0; //列不匹配
			}
		}
	}
	return 1;
}




void game(int size, char* array, int* remind_row, int* remind_col,int width, int height,char choice)
{
	int cheat = 0;
	char test_a[25] = { 0};
	char test_b[100] = { 0 };
	char test_c[225] = { 0 };
	char* user = array_choice(size, test_a, test_b, test_c); //获取用户选择的数组
	for (int i = 0; i < size * size; i++) {
		user[i] = 0; //初始化用户输入数组
	}	
	if (choice == 'C') {
		cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
		while (1) {
			int x = 0, y = 0;
			if (cheat % 2 == 0)
				draw_array(size, array, remind_row, remind_col, 'C', width, height, x, y);
			else
				draw_array(size, array, remind_row, remind_col, 'B', width, height, x, y);
			int m = 0; //行计数器
			for (int i = 0; i < size; i++) {
				cct_gotoxy(x, y + m + 1);
				for (int j = 0; j < size; j++) {
					if (user[size * i + j] == 0 && array[size * i + j] == 0) {
						cout << "  "; //空格
					}
					else if (user[size * i + j] == 0 && array[size * i + j] == '0' && cheat % 2 != 0) {
						cout << " 0";
					}
					else if (user[size * i + j] == 0 && array[size * i + j] == '0' && cheat % 2 == 0) {
						cout << "  ";
					}
					else {
						cout << " ";
						if (cheat % 2 != 0) {
							if (user[size * i + j] == '0' && array[size * i + j] != '0') {
								cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
								putchar('X'); //显示字符
								cct_setcolor();
							}
							else {
								cct_setcolor(COLOR_HYELLOW, COLOR_BLUE); //设置颜色
								putchar(user[size * i + j]); //显示字符
								cct_setcolor();
							}
						}
						else {
							cct_setcolor(COLOR_HYELLOW, COLOR_BLUE); //设置颜色
							putchar(user[size * i + j]); //显示字符
							cct_setcolor(); //恢复颜色
						}
					}

					if ((j + 1) % 5 == 0) {
						cout << " |"; //每5个字符后加一个分隔符
					}
				}
				m++;
				if ((i + 1) % 5 == 0)
					m++;
			}
			cout << endl;
			cout << endl;
			while (1) {
				cout << "命令形式：Aa = 等价于图形游戏中鼠标左键选择Aa位（区分大小写）" << endl;
				cout << "               不需要支持图形界面的右键打叉，再次输入Aa相当于清除" << endl;
				cout << "          X / x = 退出（新行仅有X / x，不分大小写)" << endl;
				cout << "          Y / y = 提交（新行仅有Y / y，不分大小写)" << endl;
				cout << "          Z / z = 作弊（新行仅有Z / z，不分大小写）" << endl;
				cout << "          Ctrl + c 强制退出" << endl;
				cout << "请输入 ：";
				char ch[3];
				cin.getline(ch, 3); //读取一行，最多3个字符
				if (cin.fail()) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "输入错误" << endl;
					cout << endl;
					continue;
				}
				else {
					if ((ch[0] == 'X' || ch[0] == 'x') && ch[1] == 0) {
						return; //退出
					}
					else if ((ch[0] == 'Y' || ch[0] == 'y') && ch[1] == 0) {
						if (compare(size, user, remind_row, remind_col)) {
							cout << "提交成功，游戏结束" << endl;
							return; //提交
						}
						else {
							cout << "提交错误，可用作弊模式查看" << endl;
							cout << endl;
							continue;
						}
					}
					else if ((ch[0] == 'Z' || ch[0] == 'z') && ch[1] == 0) {
						cout << "输入Z/z后：" << endl;
						cheat++;
						break;
					}
					else if (ch[0] >= 'A' && ch[0] < 'A' + size && ch[1] >= 'a' && ch[1] < 'a' + size) {
						int i = ch[0] - 'A'; //行
						int j = ch[1] - 'a'; //列
						if (user[size * i + j] == 0) {
							user[size * i + j] = '0'; //如果没有输入，输入0
						}
						else {
							user[size * i + j] = 0; //如果已经输入，清除
						}
						break;
					}
					else {
						cout << "输入错误" << endl;
						cout << endl;
						continue;
					}
				}
			}
		}
	}
	
	if (choice == 'G') {
		cout << "左键选○/右键选× ，Y/y提交，Z/z作弊，Q/q结束" << endl;
		
		int x = 6 + 2 * width, y = 4 + height, row = 0, col = 0;
		char ins = 0;
		while (1) {
			if (cheat % 2 == 0) {//作弊模式关
				draw_img(size, array, remind_row, remind_col, 'G', width, height, x, y);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (user[size * i + j] == 0) {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == '0') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_HBLUE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == 'X') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "×", COLOR_HRED, COLOR_BLACK, 1, -1);
						}
					}
				}
			}
			else {//作弊模式开
				draw_img(size, array, remind_row, remind_col, 'G', width, height, x, y);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (array[size * i + j] == '0') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_WHITE, COLOR_BLACK, 1, -1);
						}
						else {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
						}
					}
				}
	

				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (user[size * i + j] == 0 && array[size * i + j] == '0') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_WHITE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == 0 && array[size * i + j] == 0) {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == 'X'&&array[size*i+j]==0) {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "×", COLOR_HRED, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == 'X' && array[size * i + j] == '0') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "×", COLOR_HBLUE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == '0' && array[size * i + j] == '0') {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_HBLUE, COLOR_BLACK, 1, -1);
						}
						else if (user[size * i + j] == '0' && array[size * i + j] == 0) {
							cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_HRED, COLOR_BLACK, 1, -1);
						}
					}
				}
			}
			
			while (1) {
				int  mouse_LR = 2;
				read_mouse(size, x, y, 'G', row, col, ins, mouse_LR);
				if (user[size * row + col] == 0 && mouse_LR == 0) {
					user[size * row + col] = '0'; //左键选○

				}
				else if (user[size * row + col] == 0 && mouse_LR == 1) {
					user[size * row + col] = 'X'; //右键选╳
				}
				else if (user[size * row + col] == '0' && mouse_LR == 0) {
					user[size * row + col] = 0; //左键取消选○
				}
				else if (user[size * row + col] == '0' && mouse_LR == 1) {
					user[size * row + col] = 'X'; //右键选╳
				}
				else if (user[size * row + col] == 'X' && mouse_LR == 0) {
					user[size * row + col] = '0'; //左键取消╳选○
				}
				else if (user[size * row + col] == 'X' && mouse_LR == 1) {
					user[size * row + col] = 0; //右键取消选╳
				}

				if (cheat % 2 == 0) {
					if (user[size * row + col] == 0) {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == '0') {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "○", COLOR_HBLUE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == 'X') {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "×", COLOR_HRED, COLOR_BLACK, 1, -1);
					}
				}

				if (cheat % 2 != 0) {
					if (user[size * row + col] == 0 && array[size * row + col] == '0') {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "○", COLOR_WHITE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == 0 && array[size * row + col] == 0) {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == 'X' && array[size * row + col] == '0') {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "×", COLOR_HBLUE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == 'X' && array[size * row + col] == 0) {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "×", COLOR_HRED, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == '0' && array[size * row + col] == '0') {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "○", COLOR_HBLUE, COLOR_BLACK, 1, -1);
					}
					else if (user[size * row + col] == '0' && array[size * row + col] == 0) {
						cct_showstr(x + 2 + col * 2, y + 1 + row, "○", COLOR_HRED, COLOR_BLACK, 1, -1);
					}
				}


				if (ins == 'L' || ins == 'R') {
					continue;
				}

				if (ins == 'Q' || ins == 'q') {
					return; //结束游戏
				}
				if (ins == 'Y' || ins == 'y') {
					if (compare(size, user, remind_row, remind_col)) {
						cct_setcolor();
						cct_gotoxy(x, y + size + 2);
						cout << "提交成功，游戏结束           " << endl;
						return; //提交
					}
					else {
						cct_setcolor();
						cct_gotoxy(x, y + size + 2);
						cout << "提交错误，可用作弊模式查看" << endl;
						cout << endl;
						continue;
					}
				}
				if (ins == 'Z' || ins == 'z') {
					cheat++;
					break; //作弊模式
				}
			}
		}
	}


	if (choice == 'K') {
		cout << "左键选○/右键选× ，Y/y提交，Z/z作弊，Q/q结束" << endl;

		int x = 6 + 2 * width, y = 4 + height, row = 0, col = 0;
		char ins = 0;

		while (1) {
			if (cheat % 2 == 0) {//作弊模式关
				draw_img(size, array, remind_row, remind_col, 'K', width, height, x, y);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (user[size * i + j] == 0) {
							draw_blank(x + 2 + j * 8, y + 1 + 4 * i);
						}
						else if (user[size * i + j] == '0') {
							draw_square(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HBLUE, COLOR_BLACK);
						}
						else if (user[size * i + j] == 'X') {
							draw_x(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HRED, COLOR_BLACK);
						}
					}
				}
			}
			else {//作弊模式开
				draw_img(size, array, remind_row, remind_col, 'K', width, height, x, y);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (array[size * i + j] == '0') {
							draw_square(x + 2 + j * 8, y + 1 + 4 * i, COLOR_WHITE, COLOR_BLACK);
						}
						else {
							draw_blank(x + 2 + j * 8, y + 1 + 4 * i);
						}
					}
				}


				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (user[size * i + j] == 0 && array[size * i + j] == '0') {
							draw_square(x + 2 + j * 8, y + 1 + 4 * i, COLOR_WHITE, COLOR_BLACK);
						}
						else if (user[size * i + j] == 0 && array[size * i + j] == 0) {
							draw_blank(x + 2 + j * 8, y + 1 + 4 * i);
						}
						else if (user[size * i + j] == 'X' && array[size * i + j] == 0) {
							draw_x(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HRED, COLOR_BLACK);
						}
						else if (user[size * i + j] == 'X' && array[size * i + j] == '0') {
							draw_x(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HBLUE, COLOR_BLACK);
						}
						else if (user[size * i + j] == '0' && array[size * i + j] == '0') {
							draw_square(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HBLUE, COLOR_BLACK);
						}
						else if (user[size * i + j] == '0' && array[size * i + j] == 0) {
							draw_square(x + 2 + j * 8, y + 1 + 4 * i, COLOR_HRED, COLOR_BLACK);
						}
					}
				}
			}

			while (1) {
				int  mouse_LR = 2;
				read_mouse(size, x, y, 'K', row, col, ins, mouse_LR);
				if (user[size * row + col] == 0 && mouse_LR == 0) {
					user[size * row + col] = '0'; //左键选○

				}
				else if (user[size * row + col] == 0 && mouse_LR == 1) {
					user[size * row + col] = 'X'; //右键选╳
				}
				else if (user[size * row + col] == '0' && mouse_LR == 0) {
					user[size * row + col] = 0; //左键取消选○
				}
				else if (user[size * row + col] == '0' && mouse_LR == 1) {
					user[size * row + col] = 'X'; //右键选╳
				}
				else if (user[size * row + col] == 'X' && mouse_LR == 0) {
					user[size * row + col] = '0'; //左键取消╳选○
				}
				else if (user[size * row + col] == 'X' && mouse_LR == 1) {
					user[size * row + col] = 0; //右键取消选╳
				}

				if (cheat % 2 == 0) {
					if (user[size * row + col] == 0) {
						draw_blank(x + 2 + col * 8, y + 1 + 4 * row); //绘制空白
					}
					else if (user[size * row + col] == '0') {
						draw_square(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HBLUE, COLOR_BLACK); //绘制蓝色方块
					}
					else if (user[size * row + col] == 'X') {
						draw_x(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HRED, COLOR_BLACK); //绘制红色叉
					}
				}

				if (cheat % 2 != 0) {
					if (user[size * row + col] == 0 && array[size * row + col] == '0') {
						draw_square(x + 2 + col * 8, y + 1 + 4 * row, COLOR_WHITE, COLOR_BLACK); //绘制白色方块
					}
					else if (user[size * row + col] == 0 && array[size * row + col] == 0) {
						draw_blank(x + 2 + col * 8, y + 1 + 4 * row); //绘制空白
					}
					else if (user[size * row + col] == 'X' && array[size * row + col] == '0') {
						draw_x(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HBLUE, COLOR_BLACK); //绘制蓝色叉
					}
					else if (user[size * row + col] == 'X' && array[size * row + col] == 0) {
						draw_x(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HRED, COLOR_BLACK); //绘制红色叉
					}
					else if (user[size * row + col] == '0' && array[size * row + col] == '0') {
						draw_square(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HBLUE, COLOR_BLACK); //绘制蓝色方块
					}
					else if (user[size * row + col] == '0' && array[size * row + col] == 0) {
						draw_square(x + 2 + col * 8, y + 1 + 4 * row, COLOR_HRED, COLOR_BLACK); //绘制红色方块
					}
				}


				if (ins == 'L' || ins == 'R') {
					continue;
				}

				if (ins == 'Q' || ins == 'q') {
					return; //结束游戏
				}
				if (ins == 'Y' || ins == 'y') {
					if (compare(size, user, remind_row, remind_col)) {
						cct_setcolor();
						cct_gotoxy(x, y + 4 * size + 1);
						cout << "提交成功，游戏结束             " << endl;
						return; //提交
					}
					else {
						cct_setcolor();
						cct_gotoxy(x, y + 4 * size + 1);
						cout << "提交错误，可用作弊模式查看" << endl;
						cout << endl;
						continue;
					}
				}
				if (ins == 'Z' || ins == 'z') {
					cheat++;
					break; //作弊模式
				}
			}
		}

	}
}


