//2453805 唐先泽 电信
#include<iostream>
using namespace std;
#include "7-b2.h"
#include "cmd_console_tools.h"
/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */


/***************************************************************************
  函数名称：show_menu_item
  功    能：安全输出菜单项，宽度不足时不拆分汉字，空格补齐
  输入参数：str-字符串，width-显示宽度，x/y-坐标，bg/fg_color-颜色
  返 回 值：无
  说    明：仅本文件内部使用
***************************************************************************/
static void show_menu_item(const char* str, int width, int x, int y, int bg_color, int fg_color,int buffercols) {
    int display_width = 0;
    int i = 0;
    int judge = 0;
    // 计算能完整显示的字符数
    while (str[i] != '\0' && display_width < width) {
        unsigned char ch = str[i];
        if (ch >= 0xA1 && ch <= 0xFE) { // 汉字
            if (display_width + 2 > width) {
                break; // 剩余宽度不足2，不能输出半个汉字
            }
            display_width += 2;
            i += 2;
        } 
        else {
            display_width += 1;
            i += 1;
        }
    }



    int display_width1 = 0;
    int j = 0;
    while (str[j] != '\0' && display_width1 < buffercols-x) {
        unsigned char ch = str[j];
        if (ch >= 0xA1 && ch <= 0xFE) { // 汉字
            if (display_width1 + 2 > buffercols-x) {
                judge = 1;
                break; // 剩余宽度不足2，不能输出半个汉字
            }
            display_width1 += 2;
            j += 2;
        }
        else {
            display_width1 += 1;
            j += 1;
        }
    }

    // 输出可显示部分
    cct_showstr(x, y, str, bg_color, fg_color, 1, i);
    // 用空格补齐
    int fill = width - display_width;

    
    if (fill > 0) {
        if (x + 4 + width > buffercols&&judge==1) { // 如果x+4+width超过了缓冲区宽度
            cct_showstr(x + display_width , y, " ", bg_color, fg_color, fill-1, -1);
        }
        else {
            for (int k = 0; k < fill; k++) {
                cct_showstr(x + display_width + k, y, " ", bg_color, fg_color, 1, -1);

            }
        }
    }
}



/***************************************************************************
  函数名称：pop_menu
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    int width = original_para->width; //菜单宽度，不含左右边框
    int x = original_para->start_x; //左上角x坐标
    int y = original_para->start_y; //左上角y坐标
    int high = original_para->high; //菜单高度，不含上下边框
    int bg_color = original_para->bg_color; //背景色
    int fg_color = original_para->fg_color; //前景色

    int menu_count = 0;
    while (menu[menu_count][0] != '\0') {
        menu_count++;
    }
    if (high > menu_count) {
        high = menu_count; //如果高度大于菜单项数，则缩小为菜单项数
    }
    int title_size = strlen(original_para->title);

    if (width < title_size) {
        width = title_size; //如果宽度小于标题长度，则宽度设置为标题长度
    }
    if (width % 2 != 0) { //如果宽度是奇数，则加1
        width++;
    }

    cct_showstr(x, y, "╔", bg_color, fg_color, 1, -1);

    if (title_size % 2 == 0) {
        cct_showstr(x + 2, y, "═", bg_color, fg_color, (width-title_size)/2/2, -1);
        cct_showstr(x + 2 + (width - title_size) / 2/2*2, y, original_para->title, bg_color, fg_color, 1, -1);
        cct_showstr(x + 2 + (width - title_size) / 2/2*2+title_size, y, "═", bg_color, fg_color, (width- (width - title_size) / 2 / 2 * 2-title_size)/2, -1);
    }
    else {
        title_size++; //如果标题是奇数个字符，则需要加1
        cct_showstr(x + 2, y, "═", bg_color, fg_color, (width - title_size) /2/2, -1);
        cct_showstr(x + 2 + (width - title_size) / 2/2*2, y, original_para->title, bg_color, fg_color, 1, title_size);
        cct_showstr(x + 2 + (width - title_size) / 2/2*2+title_size, y, "═", bg_color, fg_color, (width - (width - title_size) / 2 / 2 * 2 - title_size) / 2, -1);
    }

	
    cct_showstr(x + 2 + width, y, "╗", bg_color, fg_color, 1, -1);

    int columns,lines,buffercols,bufferlines;
    cct_getconsoleborder(columns, lines, buffercols, bufferlines); //获取当前窗口的列数
    for (int i = 0; i < high; i++) {
        cct_showstr(x, y +1+i, "║", bg_color, fg_color, 1, -1);
        if (x + 4 + width > buffercols) {
            cct_showstr(x + 2 + width-columns, y + 2 + i, "║", bg_color, fg_color, 1, -1);
        }
        else {
            cct_showstr(x + 2 + width, y + 1 + i, "║", bg_color, fg_color, 1, -1);
        }
        //cct_showstr(x + 2 + width, y + 1 + i, "║", bg_color, fg_color, 1, -1);
    }

    cct_showstr(x, y+high+1, "╚", bg_color, fg_color, 1, -1);
	if (x + 4 + width > buffercols) {
		cct_showstr(x + 2 + width - columns, y + high + 2, "╝", bg_color, fg_color, 1, -1);
	}
	else
        cct_showstr(x + 2 + width, y + high + 1, "╝", bg_color, fg_color, 1, -1);
    //cct_showstr(x + 2 + width, y+high+1, "╝", bg_color, fg_color, 1, -1);
    cct_showstr(x + 2, y + high+1, "═", bg_color, fg_color, width / 2, -1);

    // 输出菜单项，宽度不足时不拆分汉字
    for (int m = 0; menu[m][0] != 0 && m < high; m++) {
        show_menu_item(menu[m], width, x + 2, y + 1 + m, bg_color, fg_color, buffercols);
        cout << endl;
    }


    cct_gotoxy(x + 2, ++y); //将光标移动到菜单第一行
    cct_setcursor(CURSOR_INVISIBLE); //隐藏光标

    if (menu[0][0] == '\0') { //菜单为空
        cct_setcolor(bg_color, fg_color);
        return 0;
    }

    int mx, my, maction, key1, key2;

    if (high < menu_count) { //如果菜单项数大于显示高度，则需要滚动
        show_menu_item(menu[y - original_para->start_y - 1], width, x + 2, y, fg_color, bg_color, buffercols);
        int bottom_choice = high;//当前菜单项的底部的选项
        while (1) {

            int ret = cct_read_keyboard_and_mouse(mx, my, maction, key1, key2);
            if (ret == CCT_KEYBOARD_EVENT) {

                
                if (key1 == 0xe0 && key2 == KB_ARROW_UP) {
                    if (y > original_para->start_y + 1) { // 如果光标不在第一行
                        // 修改为只高亮和恢复当前行，不滚动菜单内容
                        show_menu_item(menu[bottom_choice + y - original_para->start_y - high - 1], width, x + 2, y, bg_color, fg_color, buffercols);
                        cct_gotoxy(x + 2, --y); // 向上移动光标
                        show_menu_item(menu[bottom_choice + y - original_para->start_y - high - 1], width, x + 2, y, fg_color, bg_color, buffercols);
             
                    } 
                    else if (y == original_para->start_y + 1 && bottom_choice - high > 0) { // 只有在当前行是最上方时才滚动
                        bottom_choice--;
                        for (int i = 0; i < high; i++) {
                            show_menu_item(menu[bottom_choice - high + i], width, x + 2, original_para->start_y + 1 + i, bg_color, fg_color, buffercols);
                        }
                        y = original_para->start_y + 1;
                        show_menu_item(menu[bottom_choice - high], width, x + 2, y, fg_color, bg_color,buffercols);
                        cct_gotoxy(x + 2, y);
                    }
                }
                else if (key1 == 0xe0 && key2 == KB_ARROW_DOWN) {
                    if (y < original_para->start_y + high) { // 如果光标不在最后一行
                        show_menu_item(menu[bottom_choice+y - original_para->start_y-high  - 1], width, x + 2, y, bg_color, fg_color, buffercols);
                        cct_gotoxy(x + 2, ++y); // 向下移动光标
                        show_menu_item(menu[bottom_choice + y - original_para->start_y - high - 1], width, x + 2, y, fg_color, bg_color, buffercols);
                    } 
                    else if (bottom_choice < menu_count) { // 如果可以向下滚动
                        bottom_choice++;
                        for (int i = 0; i < high; i++) {
                            show_menu_item(menu[bottom_choice - high + i], width, x + 2, original_para->start_y + 1 + i, bg_color, fg_color, buffercols);
                        }
                        y = original_para->start_y + high;
                        show_menu_item(menu[bottom_choice - 1], width, x + 2, y, fg_color, bg_color, buffercols);
                        cct_gotoxy(x + 2, y);
                    }
                }
            
                else if (key1 == 0x0d) { //回车键
                    return bottom_choice-original_para->start_y-high+y; //返回选择的菜单项数（从1开始计数）
                }
            }
        }
    }
    else {
        while (1) {

            show_menu_item(menu[y - original_para->start_y - 1], width, x + 2, y, fg_color, bg_color, buffercols);
            int ret = cct_read_keyboard_and_mouse(mx, my, maction, key1, key2);
            if (ret == CCT_KEYBOARD_EVENT) {
                if (key1 == 0xe0 && key2 == KB_ARROW_UP) {
                    if (y > original_para->start_y + 1) { //如果光标不在第一行
                        cct_gotoxy(x + 2, --y); //向上移动光标
                        show_menu_item(menu[y + 1 - original_para->start_y - 1], width, x + 2, y + 1, bg_color, fg_color, buffercols);
                    }
                }
                else if (key1 == 0xe0 && key2 == KB_ARROW_DOWN) {
                    if (y < original_para->start_y + high) { //如果光标不在最后一行
                        cct_gotoxy(x + 2, ++y); //向下移动光标
                        show_menu_item(menu[y - 1 - original_para->start_y - 1], width, x + 2, y - 1, bg_color, fg_color,buffercols);
                    }
                }
                else if (key1 == 0x0d) { //回车键
                    return y - original_para->start_y; //返回选择的菜单项数（从1开始计数）
                }
            }
        }
    }
    return 0; //按需返回
}
