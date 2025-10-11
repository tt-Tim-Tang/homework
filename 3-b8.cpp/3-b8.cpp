//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a;
	int i,j;
	double k;
	double sum;
	sum = 1;
	bool flag = true;
	while (flag) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> a;
		if (a > 65 || a < -10) {
			cout << "输入非法，请重新输入" << endl;
		}
		else {
			flag = false;
			for (i=1;; i++) {
				k = 1.0;
				for (j = 1; j <= i; j++) {
					k = k * (a / j);
				}
				if (fabs(k) < pow(10, -6)) {
					break;
				}
				sum += k;
	
			}
			cout << "e^" << a << "=" << setprecision(10) << sum << endl;
		}

	}
	return 0;

}