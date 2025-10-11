//2453805 唐先泽 电信
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
/***************************************************************************
  函数名称：menu
  功    能：菜单
  输入参数：
  返 回 值：
  说    明：显示菜单
***************************************************************************/
char menu()
{
	char c;
	
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右(按大写HPKM不允许移动光标，边界停止)" << endl;
	cout << "4.用箭头键控制上下左右(按大写HPKM不允许移动光标，边界回绕)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-4]";
	while (1) {
		c = _getch();
		if (c == '1' || c == '2' || c == '3' || c == '4' || c == '0') {
			break;
		}
	}
	return c;

}
/* -- 按需增加的若干函数可以放在此处 --*/
/***************************************************************************
  函数名称：move_by_ijkl()
  功    能：ijkl移动
  输入参数：c1 （1，2） ,c2 （边停为1，环绕为2）
  返 回 值：
  说    明：
***************************************************************************/
void move_by_ijkl(char c1,int c2) 
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	init_border(hout);
	gotoxy(hout, 35, 9);
	int x = 35;
	int y = 9;
	char back;
	

	if (c1 == '1' && c2 == 1) {//边界停止,ijkl大小写,左箭头光标不允许下移
		while (1) {
			char c = _getch();
			if ((int)c == -32) { //不让左箭头移动，左箭头先返回0/224，再返回75（K也是75）
				c = _getch();
			    gotoxy(hout, x, y);
				continue;
				
			}
			switch (c) {
			case 'i':
			case 'I':
				if (y!=1) {
					gotoxy(hout, x, --y);
				}
				else{
					gotoxy(hout, x, y);

				}
				break;
			case 'j':
			case 'J':
				if (x!=1) {
					gotoxy(hout, --x, y);
				}
				else  {
					gotoxy(hout, x, y);
				}
				break;
			case 'k':
			case 'K':
				if (y!=17) {
					gotoxy(hout, x, ++y);
				}
				else {
					gotoxy(hout, x, y);
				}
				break;
			case 'l':
			case 'L':
				if (x != 69) {
					gotoxy(hout, ++x, y);
				}
				else {
					gotoxy(hout, x, y);
				}
				break;
			case ' ':
				showch(hout, x, y, ' ');
				gotoxy(hout, x, y);
				break;
			default:
				gotoxy(hout, x, y);
				break;
			}
			if (c == 'q' || c == 'Q') {
				break;
			}

		}
	}
	else if (c1 == '2' && c2 == 2) {//边界回绕,ijkl大小写,左箭头光标不允许下移
		while (1) {
			char c = _getch();
			if ((int)c == -32) { //不让左箭头移动，左箭头先返回0/224，再返回75（K也是75）
				c = _getch();
				gotoxy(hout, x, y);
				continue;
			}

			switch (c) {
			case 'i':
			case 'I':
				if (y!=1) {
					gotoxy(hout, x, --y);
				}
				else {
					y = 17;
					gotoxy(hout, x, y);
				}
				break;
			case 'j':
			case 'J':
				if (x != 1) {
					gotoxy(hout, --x, y);
				}
				else {
					x = 69;
					gotoxy(hout, x, y);
				}
				break;
			case 'k':
			case 'K':
				if (y != 17){
					gotoxy(hout, x, ++y);
				}
				else {
					y = 1;
					gotoxy(hout, x, y);
				}
				break;
			case 'l':
			case 'L':
				if (x != 69) {
					gotoxy(hout, ++x, y);
				}
				else {
					x = 1;
					gotoxy(hout, x, y);
				}
				break;
			case ' ':
				showch(hout, x, y, ' ');
				gotoxy(hout, x, y);
				break;
			default:
				gotoxy(hout, x, y);
				break;
			}

			if (c == 'q' || c == 'Q') {
				break;
			}
		}

	}

	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	while (1) {
		back = _getch();
		if ((int)back == 13) {
			cls(hout);
			break;
		}
	}

}

/***************************************************************************
  函数名称：move_by_arrow()
  功    能：箭头移动光标
  输入参数：c1 (3, 4) c2(边停为3，环绕为4）
  返 回 值：
  说    明：
***************************************************************************/
void move_by_arrow(char c1, int c2)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	init_border(hout);
	gotoxy(hout, 35, 9);
	int x = 35;
	int y = 9;
	char back;
	while (1) {
		if (c1 == '3'&& c2 == 3) {//用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）
			char c = _getch();
			if ((int)c == -32) {
				c = _getch();
				if ((int)c == 72) {//上箭头
					if (y != 1) {
						gotoxy(hout, x, --y);
					}
				}
				if ((int)c == 80) {//下箭头
					if (y != 17) {
						gotoxy(hout, x, ++y);
					}
				}
				if ((int)c == 75) {//左箭头
					if (x != 1) {
						gotoxy(hout, --x, y);
					}
				}
				if ((int)c == 77) {//右箭头
					if (x != 69) {
						gotoxy(hout, ++x, y);
					}
				}
	
			}
			else if (c == ' ') {
				showch(hout, x, y, ' ');
				gotoxy(hout, x, y);
			}
			else if (c == 'q' || c == 'Q') {
				break;
			}
			else {
				gotoxy(hout, x, y);
			}


		}
		else if (c1 == '4'&& c2 == 4) {
			char c = _getch();
			if ((int)c == -32) {
				c = _getch();
				if ((int)c == 72) {//上箭头
					if (y != 1) {
						gotoxy(hout, x, --y);
					}
					else {
						y = 17;
						gotoxy(hout, x, y);
					}
				}
				if ((int)c == 80) {//下箭头
					if (y != 17) {
						gotoxy(hout, x, ++y);
					}
					else {
						y = 1;
						gotoxy(hout, x, y);
					}
				}
				if ((int)c == 75) {//左箭头
					if (x != 1) {
						gotoxy(hout, --x, y);
					}
					else {
						x = 69;
						gotoxy(hout, x, y);
					}
				}
				if ((int)c == 77) {//右箭头
					if (x != 69) {
						gotoxy(hout, ++x, y);
					}
					else {
						x = 1;
						gotoxy(hout, x, y);
					}
				}

			}
			else if (c == ' '){
				showch(hout, x, y, ' ');
				gotoxy(hout, x, y);
			}
			else if (c == 'q' || c == 'Q') {
				break;
			}
			else {
				gotoxy(hout, x, y);
			}


		}
	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	while (1) {
		back = _getch();
		if ((int)back == 13) {
			cls(hout);
			break;
		}
	}

}



/***************************************************************************
  函数名称：main
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	char c;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	cls(hout);
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	while (1) {
		c = menu();
		if (c == '0') {
			cout << "0";
			break;
		}
		else if (c == '1') {
			cls(hout);
			move_by_ijkl(c, 1);
		}
		else if (c == '2') {
			cls(hout);
			move_by_ijkl(c, 2);
		}
		else if (c == '3') {
			cls(hout);
			move_by_arrow(c,3);
		}
		else if (c == '4') {
			cls(hout);
			move_by_arrow(c,4);
		}
	

	}
	

	/* 此句的作用是调用系统的cls命令清屏 */
	//cls(hout);

	/* 显示初始的边框及其中的随机字符 */
	//init_border(hout);

	//暂停
	//getchar();

	//gotoxy(hout, 0, 23);
	//cout << "游戏结束，按回车键退出." << endl;

	//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
	//getchar();

	return 0;
}