//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int max(int x, int y, int z)
{
	return max(x, y) > z ? max(x, y) : z;
}
int max(int x, int y, int z, int w)
{
	return max(x, y, z) > w ? max(x, y, z) : w;
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
					cout << "max=" << max(a, b) << endl;
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
					cout << "max=" << max(a, b, c) << endl;
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
					cout << "max=" << max(a, b, c, d) << endl;
					break;
				}
			}
		}
	}
	return 0;

}