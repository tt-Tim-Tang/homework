//2453805 唐先泽 电信
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（不包括宏定义、全局const变量）
   3、允许添加自定义函数
   ---------------------------------------------------------------------
*/
int calculate(int num)
{
	int sum = 0;
	while (1) {
		sum +=num % 10;
		num = num / 10;
		if (num == 0) {
			break;
		}

	}
	if (sum < 10) {
		return sum;
	}
	else {
		return calculate(sum);
	}
}

int result(int a[],int n, int base) 
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (calculate(a[i]) == base) {
			sum += 1;
		}
	}
	return sum;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	int n;
	int base;
	int a[10000];
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入"<<n<<"个正整数" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "请输入要统计的基数[1..9]" << endl;
	cin >> base;

	cout << n << "个数中迭代累加后值为" << base <<"的数字的个数" << " : " << result(a,n,base) << endl;


	return 0;
}
