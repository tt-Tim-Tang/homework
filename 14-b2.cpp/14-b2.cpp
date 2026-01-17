//2453805 唐先泽 大数据
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
/* 如果有需要，此处可以添加头文件 */
#include<climits>
using namespace std;

/* 允许定义常变量/宏定义，但不允许定义全局变量 */

/* 可以添加自己需要的函数 */

/***************************************************************************
  函数名称：
  功    能：打印某个玩家的牌面信息，如果是地主，后面加标记
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int print(const char* prompt, const bool landlord, const unsigned long long player)
{
	/* 只允许定义不超过三个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	cout << prompt;
	for (int i = 0; i < 54; i++) {
		if (player & (1ULL << i)) {
			if (i == 53) {
				cout << "RJ ";
			}
			else if (i == 52) {
				cout << "BJ ";
			}
			else {
				#ifdef _WIN32
				if (i % 4 == 0) {
					cout << "c";
				}
				else if (i % 4 == 1) {
					cout << "d";
				}
				else if (i % 4 == 2) {
					cout << "h";
				}
				else {
					cout << "s";
				}
				#elif defined(__linux__)
				if (i % 4 == 0) {
					cout << "C";
				}
				else if (i % 4 == 1) {
					cout << "D";
				}
				else if (i % 4 == 2) {
					cout << "H";
				}
				else {
					cout << "S";
				}
				#endif

				if (i >= 0 && i < 28) {
					cout << ((i / 4) + 3) << " ";
				}
				else if (i >= 28 && i < 32) {
					cout << "T ";
				}
				else if (i >= 32 && i < 44) {
					cout << char((i / 4) - 8 + 'J') << " ";
				}
				else if (i >= 44 && i < 48) {
					cout << "A ";
				}
				else {
					cout << "2 ";
				}
			}
		}
	}
	if (landlord) {
		cout << "(地主)";
	}
	cout << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：发牌（含键盘输入地主）
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int deal(unsigned long long* player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	srand((unsigned int)time(NULL));
	unsigned long long pile = 0ULL;
	for (int i = 0; i < 54; i++) {
		pile = pile | (1ULL << i);
	}

	for (int i = 1; i <= 17; i++) {
		for (int p = 0; p <= 2; p++) {
			int remaining = 0;
			for (int j = 0; j < 54; j++) {
				if (pile & (1ULL << j)) {
					remaining++;
				}
			}
			int num_1 = rand() % remaining;
			int cur_num_1 = 0;
			for (int k = 0; k < 54; k++) {
				if (pile & (1ULL << k)) {
					if (cur_num_1 == num_1) {
						player[p] = player[p] | (1ULL << k);
						pile = pile & (~(1ULL << k));
						break;
					}
					cur_num_1++;
				}
			}
		}
		cout << "第" << i << "轮结束：" << endl;
		print("甲的牌：", 0, player[0]);
		print("乙的牌：", 0, player[1]);
		print("丙的牌：", 0, player[2]);
	}
	cout << endl;
	while (1) {
		cout << "请选择一个地主[0-2]：" << endl;
		int landlord;
		cin >> landlord;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << endl;
			continue;
		}
		if (landlord >= 0 && landlord <= 2) {
			for (int i = 0; i < 54; i++) {
				if(pile & (1ULL << i)) {
					player[landlord] = player[landlord] | (1ULL << i);
					pile = pile & (~(1ULL << i));
				}
			}
			return landlord;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数，不准修改
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
	int landlord; //返回0-2表示哪个玩家是地主

	cout << "按回车键开始发牌";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("甲的牌：", (landlord == 0), player[0]);
	print("乙的牌：", (landlord == 1), player[1]);
	print("丙的牌：", (landlord == 2), player[2]);

	return 0;
}