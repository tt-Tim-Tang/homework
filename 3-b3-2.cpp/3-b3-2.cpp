//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double num;
	int num_1, num_3,num_4,num_5,num_6,num_7,num_8,num_9,num_10,decimal_part,num_11,num_12;
	int num_2;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> num;
	num_1 = int(num / 1000000000);
	num_2 = int((num - num_1 * 1000000000.0)/100000000);
	num_3 = int((num - num_1 * 1000000000.0- num_2 * 100000000.0) / 10000000);
	num_4 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0) / 1000000);
	num_5 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0) / 100000);
	num_6 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0) / 10000);
	num_7 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0) / 1000);
	num_8 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0) / 100);
	num_9 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0) / 10);
	num_10 = int(num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0);
	decimal_part = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0 - num_10 * 1.0) * 100 + 0.5);
	num_11 = decimal_part / 10;
	num_12 = decimal_part - 10 * num_11;
	cout << setiosflags(ios::left);
	cout << setw(7) << "十亿位" << ": " << num_1<<endl ;
	cout << setw(7) << "亿位" << ": " << num_2 << endl;
	cout << setw(7) << "千万位" << ": " << num_3 << endl;
	cout << setw(7) << "百万位" << ": " << num_4 << endl;
	cout << setw(7) << "十万位" << ": " << num_5 << endl;
	cout << setw(7) << "万位" << ": " << num_6 << endl;
	cout << setw(7) << "千位" << ": " << num_7 << endl;
	cout << setw(7) << "百位" << ": " << num_8 << endl;
	cout << setw(7) << "十位" << ": " << num_9 << endl;
	cout << setw(7) << "圆" << ": " << num_10 << endl;
	cout << setw(7) << "角" << ": " << num_11 << endl;
	cout << setw(7) << "分" << ": " << num_12<<endl;
	return 0;


}