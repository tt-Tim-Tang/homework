//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int min(int x, int y, int z = 2147483647, int w = 2147483647)
{
	return x < y ? (x < z ? (x < w ? x : w) : (z < w ? z : w)) : (y < z ? (y < w ? y : w) : (z < w ? z : w));
}
int main()
{
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		int num;
		int a, b, c, d;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else {
			if (num < 2 || num>4) {
				cout << "个数输入错误" << endl;
				break;
			}
			else if (num == 2) {
				cin >> a >> b;
				if (cin.fail() || a <= 0 || b <= 0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "min=" << min(a, b) << endl;
					break;
				}
			}
			else if (num == 3) {
				cin >> a >> b >> c;
				if (cin.fail() || a <= 0 || b <= 0 || c <= 0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "min=" << min(a, b, c) << endl;
					break;
				}
			}
			else if (num == 4) {
				cin >> a >> b >> c >> d;
				if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "min=" << min(a, b, c, d) << endl;
					break;
				}
			}
		}
	}
	return 0;

}