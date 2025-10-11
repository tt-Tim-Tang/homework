//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	int a[21] = {0};
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (int i = 0; i < 20; i++) {
		cin >> a[i];
		if (a[i] <= 0) {
			if (a[0] <= 0) {
				cout << "无有效输入" << endl;
				return 0;
			}
			else {
				break;
			}
		}

	}
	cout << "原数组为：" << endl;
	for (int i = 0; i < 20; i++) {
		if (a[i] <= 0) {
			break;
		}
		cout << a[i] << " " ;
	}
	cout << endl;
	cin.ignore(INT_MAX, '\n');
	cout << "请输入要插入的正整数" << endl;
	cin >> a[20];
	cout << "插入后的数组为：" << endl;
	int b[21] = {0};
	for (int i = 0; i < 20; i++) {
		if (a[i] > 0) {
			if (a[20] <= a[i]) {
				
				
				for (int j = i+1; j < 21; j++) {
					b[j] = a[j-1];
				}

				b[i] = a[20];

				for (int j = 0; j < i; j++) {
					b[j] = a[j];
				}
				break;
			}
			else if (a[20] > a[19]&&a[19]>0) {
				for (int j = 0; j < 21; j++) {
					b[j] = a[j];
				}
				break;
			}
			else {
				continue;
			}
		}
		else {
			if (a[i - 1] < a[20]) {
				b[i] = a[20];
				for (int j = 0; j < i; j++) {
					b[j] = a[j];
				}
				break;
			}
			else {
				break;
			}
		}
	}
	
	for (int i = 0; i < 21; i++) {
		if (b[i] > 0 || (i==0&&b[i]<=0)) {
			cout << b[i] << " ";
		}
		else {
			break;
		}
	}
	cout << endl;

	return 0;
}