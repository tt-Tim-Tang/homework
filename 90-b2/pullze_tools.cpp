//2453805 唐先泽 电信
#include <iostream>
#include<conio.h>
#include"cmd_console_tools.h"
#include"pullze.h"
#define WIDTH   11
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char menu()
{
	cout << "---------------------------------------------------------" << endl;
	cout << "A.内部数组，原样输出" << endl;
	cout << "B.内部数组，生成提示行列并输出" << endl;
	cout << "C.内部数组，游戏版" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "D.n * n的框架(无分隔线)，原样输出" << endl;
	cout << "E.n * n的框架(无分隔线)，含提示行列" << endl;
	cout << "F.n * n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "G.cmd图形界面完整版(无分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "H.n * n的框架(有分隔线)，原样输出" << endl;
	cout << "I.n * n的框架(有分隔线)，含提示行列" << endl;
	cout << "J.n * n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "K.cmd图形界面完整版(有分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Q.退出" << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "[请选择:]";
	char ch;
	while (1) {
		ch=_getch();
		if (ch >= 'A' && ch <= 'K' || ch == 'Q'||ch=='q'||ch>='a'&&ch<='k') {
			break;
		}
		else {
			continue;
		}
	}
	return ch;
}



void end_judge(int x,int y)
{
	while (1) {
		cct_gotoxy(x, y); //移动到原来的位置
		char ch[4];
		cin.getline(ch, 4); //读取一行，最多3个字符
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 清理多余输入
		}
		if ((ch[0] == 'E' || ch[0] == 'e') && (ch[1] == 'N' || ch[1] == 'n') && (ch[2] == 'D' || ch[2] == 'd')) {
			return;
		}
		else {
			cct_gotoxy(0, y + 1); //移动到下一行
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(x, y);
			cout << "    ";
		}
	}


}

void read_mouse(int size, int x, int y,char choice,int &row,int &col,char &ins,int &mouse_LR)
{
	int mx, my, maction, key1, key2;
	int loop = 1;
	//左是0，右是1,int mouse_LR
	cct_enable_mouse(); //启用鼠标
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	cct_setcolor();
	while (loop) {
		int ret = cct_read_keyboard_and_mouse(mx, my, maction, key1, key2);
		if (ret == CCT_MOUSE_EVENT) {
			if (choice == 'F' || choice == 'G') {
				cct_gotoxy(x, y + size + 2);
				cout << "[当前光标] ";
				cct_gotoxy(x + 11, y + size + 2);
				if ((mx - x) < 2 || (mx - x) > 2 * size + 1 || (my - y) < 1 || (my - y) > size) {
					cout << "位置非法            ";
				}
				else {
					cout << "          ";
					cct_gotoxy(x + 11, y + size + 2);
					cout << char('A' + (my - y - 1)) << "行" << char('a' + (mx - x) / 2 - 1) << "列                      ";
				}
				switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK:
					if ((mx - x) >= 2 && (mx - x) <= 2 * size + 1 && (my - y) >= 1 && (my - y) <= size) {
						cct_gotoxy(x, y + size + 2);
						cout << "[读到左键]";
						row = my - y - 1; //行号
						col = (mx - x) / 2 - 1; //列号
						mouse_LR = 0; //左键
					}
					if (choice == 'G') {
						ins = 'L'; //左键
						loop = 0;
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:
					if ((mx - x) >= 2 && (mx - x) <= 2 * size + 1 && (my - y) >= 1 && (my - y) <= size) {
						cct_gotoxy(x, y + size + 2);
						cout << "[读到右键]";
						row = my - y - 1; //行号
						col = (mx - x) / 2 - 1; //列号
						mouse_LR = 1; //右键
					}
					if (choice == 'G') {
						ins = 'R'; //右键
						loop = 0;
					}
					break;
				}
			}

			if (choice == 'J' || choice == 'K') {
				cct_gotoxy(x, y + size * 4 + 1);
				cout << "[当前光标] ";
				cct_gotoxy(x + 11, y + size * 4 + 1);
				if ((mx - x) < 2 || (mx - x) > 8 * size - 1 || (my - y) < 1 || (my - y) > 4 * size - 1 || (mx - x) % 8 == 0 || (mx - x - 1) % 8 == 0 || (my - y) % 4 == 0) {
					cout << "位置非法";
				}
				else {
					cout << "          ";
					cct_gotoxy(x + 11, y + size * 4 + 1);
					cout << char('A' + (my - y)/4) << "行" << char('a' + (mx - x) / 8) << "列                      ";
				}
				switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK:
					if ((mx - x) >= 2 && (mx - x) <= 8 * size - 1 && (my - y) >= 1 && (my - y) <= 4 * size - 1 && (mx - x) % 8 != 0 && (mx - x - 1) % 8 != 0 && (my - y) % 4 != 0) {
						cct_gotoxy(x, y + size * 4 + 1);
						cout << "[读到左键]";
						row = (my - y) / 4; //行号
						col = (mx - x) / 8; //列号
						mouse_LR = 0; //左键
					}
					if (choice == 'K') {
						ins = 'L'; //左键
						loop = 0;
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:
					if ((mx - x) >= 2 && (mx - x) <= 8 * size - 1 && (my - y) >= 1 && (my - y) <= 4 * size - 1 && (mx - x) % 8 != 0 && (mx - x - 1) % 8 != 0 && (my - y) % 4 != 0) {
						cct_gotoxy(x, y + size * 4 + 1);
						cout << "[读到右键]";
						row = (my - y) / 4; //行号
						col = (mx - x) / 8; //列号
						mouse_LR = 1; //右键
					}
					if (choice == 'K') {
						ins = 'R'; //右键
						loop = 0;
					}
					break;
				}
			}

			
		}
				
		else if (ret == CCT_KEYBOARD_EVENT) {
			if (key1 == 13) { //回车键
				if (choice == 'F' || choice == 'G') {
					cct_gotoxy(x, y + size + 2);
					cout << "[读到回车键]                ";
				}
				else if (choice == 'J' || choice == 'K') {
					cct_gotoxy(x, y + size * 4 + 1);
					cout << "[读到回车键]                ";
				}  
				if (choice == 'F'||choice=='J') {
					break;
				}
			}
			else {
				if (choice == 'F' || choice == 'G') {
					cct_gotoxy(x, y + size + 2);
				}
				else if (choice == 'J' || choice == 'K') {
					cct_gotoxy(x, y + size * 4 + 1);
				}
				if (choice == 'G'||choice=='K') {
					if (key1 == 'Y' || key1 == 'y') {
						cout << "读到提交键                  ";
						ins = 'Y';
						break;
					}
					else if (key1 == 'Z' || key1 == 'z') {
						cout << "读到作弊键                  ";
						ins = 'Z';
						break;
					}
					else if (key1 == 'Q' || key1 == 'q') {
						cout << "[读到Q/q，游戏结束]                         ";
						ins = 'Q';
						break;
					}
					else {
						cout << "[读到键码] " << key1 << "/" << key2<<"                 ";
					}
				}
				if (choice == 'F'||choice=='J') {
					cout << "[读到键码] " << key1 << "/" << key2<<"                    ";
				}
			}
		}

	}
}

/***************************************************************************
  函数名称：fun
  功    能：根据用户选择的选项执行相应的功能
  输入参数：choice - 用户选择的选项
  返 回 值：无
  说    明：该函数根据用户输入的选项执行不同的功能，包括显示数组、游戏模式等。
  ***************************************************************************/
void fun(char choice)
{
	char a[25] = { 0 };
	char b[100] = { 0 };
	char c[225] = { 0 };
	int a_row[25] = { 0 };
	int b_row[100] = { 0 };
	int c_row[225] = { 0 };
	int a_col[25] = { 0 };
	int b_col[100] = { 0 };
	int c_col[225] = { 0 };
	srand(unsigned int(time(0)));
	int size = area_size();
	cout << "初始数组：" << endl;

	char* array = array_choice(size, a, b, c);
	int* remind_row = array_remind_choice(size, a_row, b_row, c_row);
	int* remind_col = array_remind_choice(size, a_col, b_col, c_col);
	int num_0 = (size * size + 1) / 2;

	//数组初始化
	for (int i = 0; i < num_0; i++) {
		int x = rand() % size;
		int y = rand() % size;
		if (array[x * size + y] == 0) {
			array[x * size + y] = '0';
		}
		else {
			i--;
		}
	}
	int place_x = 0, place_y = 0,p_mouse=0;
	char place = 0;
	int width = row_remind(remind_row, array, size);
	int height = col_remind(remind_col, array, size);
	if (choice == 'A' || choice == 'B')
		draw_array(size, array, remind_row, remind_col, choice, width, height, place_x, place_y);
	if (choice == 'C') {
		game(size, array, remind_row, remind_col, width, height, 'C');
	}
	if (choice == 'D') {
		set_window(size, 'D');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 2, 2);
	}
	if (choice == 'E') {
		set_window(size, 'E');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 6 + 2 * width, 4 + height);
	}
	if (choice == 'F') {
		set_window(size, 'F');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 6 + 2 * width, 4 + height);
		read_mouse(size, 6 + 2 * width, 4 + height,choice,place_x,place_y,place,p_mouse);
		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
	}
	if (choice == 'G') {
		set_window(size, 'G');
		game(size, array, remind_row, remind_col, width, height, 'G');
		cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
		cct_gotoxy(0, 6 + height + size);
	}
	if (choice == 'H') {
		set_window(size, 'H');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 2, 2);
	}
	if (choice == 'I') {
		set_window(size, 'I');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 6 + 2 * width, 4 + height);
	}
	if (choice == 'J') {
		set_window(size, 'J');
		draw_img(size, array, remind_row, remind_col, choice, width, height, 6 + 2 * width, 4 + height);
		read_mouse(size, 6 + 2 * width, 4 + height, choice, place_x, place_y, place, p_mouse);
		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
	}
	if (choice == 'K') {
		set_window(size, 'K');
		game(size, array, remind_row, remind_col, width, height, 'K');
		cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
		cct_gotoxy(0, 5 + height + 4 * size);
	}
	cct_setcolor();
	cout << endl;
	cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	if (choice == 'A' || choice == 'B')
		cin.ignore(INT_MAX, '\n');
	end_judge(x, y);
}












