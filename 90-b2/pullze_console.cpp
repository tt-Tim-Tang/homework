//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
#include"pullze.h"
#include"cmd_console_tools.h"
using namespace std;

void draw_square(int x, int y,int bg_color,int fg_color)
{
    cct_showstr(x, y, "╔═╗",bg_color, fg_color, 1, -1);
    cct_showstr(x, y+1, "║○║", bg_color, fg_color, 1, -1);
    cct_showstr(x, y+2, "╚═╝", bg_color, fg_color, 1, -1);
}
void draw_blank(int x, int y)
{
    cct_showstr(x, y, "      ", COLOR_HWHITE,COLOR_BLACK, 1, -1);
    cct_showstr(x, y + 1, "      ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
    cct_showstr(x, y + 2, "      ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
}

void draw_x(int x, int y, int bg_color, int fg_color)
{
	cct_showstr(x, y, "╔═╗",bg_color,fg_color, 1, -1);
	cct_showstr(x, y + 1, "║×║", bg_color, fg_color, 1, -1);
	cct_showstr(x, y + 2, "╚═╝", bg_color, fg_color, 1, -1);
}
/***************************************************************************
  函数名称：draw_img
  功    能：
  输入参数：x,y起始坐标，size区域大小，array数组，remind_row/col提示行列，choice选择，width,height宽高
  返 回 值：
  说    明：
***************************************************************************/
void draw_img(int size, char* array, int* remind_row, int* remind_col, char choice, int width, int height, int x, int y)
{
	int d_x = 0, d_y = 0,loop_x=0,mode=2;
    if (choice == 'D' || choice == 'E' || choice == 'F' || choice == 'G') {
        d_x = 2 * size + 2;
        d_y = size + 1;
        loop_x = size;
        mode = 0;
    }
	if (choice == 'H' || choice == 'I' || choice == 'J' || choice == 'K') {
		d_x = 8 * size;
        d_y = 4 * size;
        loop_x = 4 * size;
        mode = 1;
	}

    if (choice == 'J'||choice=='F') {
        cout << "测试键盘 / 鼠标左键 / 右键，按回车退出" << endl;
    }



    if (choice == 'H'||choice=='D') {
		cct_gotoxy(x + 2, y - 1);
		for (int i = 0; i < size; i++) {
            if(choice=='H')
			    cout<<"  "<< char('a' + i) << " "<<"    ";
            if(choice=='D')
                cout << char('a' + i) << " ";

		}
        for (int i = 0; i < size; i++) {
            if (choice == 'H')
                cct_gotoxy(0, y + 2 + 4 * i);
			if (choice == 'D')
				cct_gotoxy(0, y + 1 + i);

            cout << char('A' + i) << " ";
        }
    }

    //画上边框
	cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_gotoxy(x + 2, y);
    for (int i = 0; i < loop_x; i++) {
        if ((i + 1) % 4 == 0) {
            if (mode == 0) {
                cout << "═ ";
            }
            if (mode == 1){
                cout << "╦ ";
            }
        }
        else {
            cout << "═ ";
        }
    }
	cct_showstr(x + d_x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);


    //画左右边框和下边框
    cct_gotoxy(x, y + 1);
    for (int i = 0; i < loop_x; i++) {
        for (int j = 0; j <= size; j++) {
            
            if (mode == 0 && j == 0) {
                cct_gotoxy(x, y + 1 + i);
                cout << "║ ";
            }
            if (mode == 0 && j == size) {
                cct_gotoxy(x + 2 + 2 * size, y + 1 + i);
                cout << "║ ";
            }
            if (mode == 1) {
                cct_gotoxy(x + 8 * j, y + 1 + i);
                cout << "║ ";
            }
        }
        if ((i + 1) % 4 == 0 && mode==1) {
            cct_gotoxy(x, y + i + 1);
            cout << "╠ ";
            for (int j = 0; j < 4 * size; j++) {
                if ((j + 1) % 4 == 0 && j != 4 * size - 1) {
					cout << "╬ ";
                }
				else if (j == 4 * size - 1) {
					cout << "╣ ";
				}
                else {
                    cout << "═ ";
                }
            }
        }
    }
	cct_showstr(x, y + d_y, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_gotoxy(x + 2, y + d_y);
    for (int i = 0; i < loop_x; i++) {
        if ((i + 1) % 4 == 0) {
            if (mode == 1) {
                cout << "╩ ";
            }
            if (mode == 0) {
                cout << "═ ";
            }
        }
        else {
            cout << "═ ";
        }
    }
	cct_showstr(x + d_x, y + d_y, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
   
    //画提示栏
    if (choice == 'I' || choice == 'J' || choice == 'K'||choice=='E'|| choice == 'F' || choice == 'G') {
        cct_showstr(x, y - 3 - height, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(x + 2, y - 3 - height, "═", COLOR_HWHITE, COLOR_BLACK, loop_x, -1);
        cct_showstr(x + d_x, y - 3 - height, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        for (int i = 0; i < height; i++) {
            cct_gotoxy(x, y - 2 - height + i);
            cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
            cout << "║" << " ";
            for (int k = 0; k < size; k++) {
                if (remind_col[size * k + i] == 0 && mode==1) {
                    if (k != size - 1) {
                        cout << "  " << " " << " " << "    ";
                    }
                    else {
						cout << "  " << " " << " " << "  ";
                    }
				}
                else if (remind_col[size * k + i] == 0 && mode == 0) {
                    cout << "  ";
                }
                else if (remind_col[size * k + i] != 0 && mode == 0) {
                    cout << right << setw(2) << remind_col[size * k + i];
                }
                    
                else if(remind_col[size * k + i] != 0 && mode == 1){
                    if (k != size - 1) {
                        cout << "  " << left << setw(2) << remind_col[size * k + i];
						cout<<resetiosflags(ios::left); // 重置对齐方式
                        cout << "    ";
                    }
                    else {
                        cout << "  " << left << setw(2) << remind_col[size * k + i];
                        cout << resetiosflags(ios::left); // 重置对齐方式
                        cout << "  ";
                    }
                }
            }
            cout << "║" << " ";
        }
        cct_showstr(x, y - 2, "╠", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(x + 2, y - 2, "═", COLOR_HWHITE, COLOR_BLACK, loop_x, -1);
        cct_showstr(x + d_x, y - 2, "╣", COLOR_HWHITE, COLOR_BLACK, 1, -1);

        cct_gotoxy(x, y - 1);
        cout << "║" << " ";
        for (int i = 0; i < size; i++) {
            if (mode == 1) {
                if (i != size - 1) {
                    cout << "  " << char('a' + i) << " " << "    ";
                }
                else {
                    cout << "  " << char('a' + i) << " " << "  ";
                }
            }
            if (mode == 0) {
                cout << " " << char('a' + i);
            }
        }
        cout << "║" << " ";
        cct_showstr(x, y, "╬", COLOR_HWHITE, COLOR_BLACK, 1, -1);

        cct_showstr(x + d_x, y, "╣", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(x, y + d_y, "╩", COLOR_HWHITE, COLOR_BLACK, 1, -1);

        
        cct_showstr(0, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(2, y, "═", COLOR_HWHITE, COLOR_BLACK, width, -1);
        cct_showstr(2 + 2 * width, y, "╦", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(4 + 2 * width, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);

        cct_showstr(0, y + d_y, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(2, y + d_y, "═", COLOR_HWHITE, COLOR_BLACK, width, -1);
        cct_showstr(2 + 2 * width, y + d_y, "╩", COLOR_HWHITE, COLOR_BLACK, 1, -1);
        cct_showstr(4 + 2 * width, y + d_y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);

        int m = 0;
        for (int i = 0; i < d_y - 1; i++) {
            cct_gotoxy(0, y + 1 + i);
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "║" << " ";
            if (((i - 1) % 4 == 0 && mode==1)|| mode==0) {
                for (int k = 0; k < width; k++) {
                    if (remind_row[size * m + k] == 0) {
                        cout << "  ";
                    }
                    else {
                        cout << left<< setw(2) << remind_row[size * m + k];
                        cout << resetiosflags(ios::left); // 重置对齐方式
                    }
                }
                cout << "║" << " ";
                cout << " " << char('A' + m);
                m++;
            }
            else {
                for (int k = 0; k < width; k++) {
                    cout << "  ";
                }
				cout << "║" << " ";
				cout << "  ";
            }
        }



    }


    //画格子
    if (mode == 1) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (array[size * i + j] == 0) {
                    draw_blank(x + 2 + 8 * j, y + 1 + 4 * i);
                }
                else if (array[size * i + j] == '0') {
                    if (choice != 'K') {
                        draw_square(x + 2 + 8 * j, y + 1 + 4 * i, COLOR_HBLUE, COLOR_BLACK);
                    }
                    else {
                        draw_blank(x + 2 + 8 * j, y + 1 + 4 * i);
                    }
                }
            }
        }
    }
    if (mode == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (array[size * i + j] == 0) {
                    cct_showstr(x + 2 + j * 2, y + 1 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
                }
                else {
                    if (choice == 'G') {
                        cct_showstr(x + 2 + j * 2, y + 1 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
                    }
                    else {
                        cct_showstr(x + 2 + j * 2, y + 1 + i, "○", COLOR_HBLUE, COLOR_BLACK, 1, -1);
                    }
                }
            }
        }
    }
	cout << endl << endl;
    if (choice != 'K'&&choice!='G') {
        cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
    }
}


void set_window(int size,char choice)
{
	
	cct_setfontsize("新宋体", 36);
	switch (size) {
	case 5:
		if(choice=='D')
			cct_setconsoleborder(17, 24);
		if(choice=='E'||choice=='F'||choice=='G')
			cct_setconsoleborder(55, 28);
        if (choice == 'H') {
            cct_setfontsize("新宋体", 24);
            cct_setconsoleborder(45, 38);
        }
		if (choice == 'I' || choice == 'J' || choice == 'K') {
			cct_setfontsize("新宋体", 24);
			cct_setconsoleborder(53, 42);
		}
		break;
	case 10:
		if (choice == 'D')
			cct_setconsoleborder(27, 28);
		if (choice == 'E'||choice=='F'|| choice == 'G')
			cct_setconsoleborder(59, 28);
        if (choice == 'H') {
			cct_setfontsize("新宋体", 16);
			cct_setconsoleborder(85, 58);
        }
        if (choice == 'I' || choice == 'J' || choice == 'K') {
            cct_setfontsize("新宋体", 16);
            cct_setconsoleborder(99, 63);
        }
		break;
	case 15:
		if (choice == 'D')
			cct_setconsoleborder(37, 28);
		if (choice == 'E'||choice=='F' || choice == 'G')
			cct_setfontsize("新宋体", 28);
			cct_setconsoleborder(61, 35);
        if (choice == 'H') {
            cct_setfontsize("新宋体", 12);
            cct_setconsoleborder(125, 78);
        }
        if (choice == 'I' || choice == 'J' || choice == 'K') {
            cct_setfontsize("新宋体", 12);
            cct_setconsoleborder(141, 90);
        }
		break;
	}
	cct_cls(); //清屏
}




