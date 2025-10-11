//2453805 唐先泽 电信
#include <iostream>
#include"pullze.h"
#include"cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：main函数
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	while (1) {
		cct_cls(); // 清屏
		cct_setfontsize("新宋体", 16);
		cct_setconsoleborder(120,50,120,9900); // 设置窗口大小
		char ch = menu();
		cct_cls(); // 清屏
		switch (ch) {
		case'A':
		case'a':
			fun('A');
			break;
		case'B':
		case'b':
			fun('B');
			break;
		case'C':
		case'c':
			fun('C');
			break;
		case'D':
		case'd':
			fun('D');
			break;
		case'E':
		case'e':
			fun('E');
			break;
		case'F':
		case'f':
			fun('F');
			break;
		case'G':
		case'g':
			fun('G');
			break;
		case'H':
		case'h':
			fun('H');
			break;
		case'I':
		case'i':
			fun('I');
			break;
		case'J':
		case'j':
			fun('J');
			break;
		case'K':
		case'k':
			fun('K');
			break;
		case'Q':
		case'q':
			return 0;
		}
	}
	
	return 0;
}