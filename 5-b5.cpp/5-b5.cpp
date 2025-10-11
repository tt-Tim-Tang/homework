//2453805 唐先泽 电信
# include<iostream>
using namespace std;
int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;;
	int a[1000] = { 0 };
	for (int i = 0; i < 1000; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < 1000; i++) {
		cin>>a[i];
		if (a[i] < 0) {
			if (a[0] < 0) {
				cout<<"无有效输入"<<endl;
				return 0;
			}
			break;
		}
	}

	cout<<"输入的数组为:"<<endl;
	for (int i = 0; i < 1000; i++) {
		if (a[i] >= 0) {
			cout<<a[i]<<" ";
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
			if (a[i + 1] < 0 && (i + 1) % 10 != 0) {
				cout << endl;
			}
		}
		else {
			break;
		}
	}
	cout<<"分数与名次的对应关系为:"<<endl;
	//数组内数据从小到大排序
	for (int i = 0; i < 999; i++) {
		for (int j = i + 1; j < 1000; j++) {
			if (a[i] > a[j]) {
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (int i = 999; i >= 0; i--) {
		if (a[i] >= 0) {
			if (i == 999) {
				int sum = 0;
				for (int j = 0; j < 1000; j++) {
					if (a[j] == a[i]) {
						sum += 1;
					}
				}
				for (int m = 0; m < sum; m++) {
					cout << a[i] <<" " <<(1000 - i) << endl;
				}

			}
			else {
				if (a[i] != a[i + 1]) {
					int sum = 0;
					for (int j = 0; j < 1000; j++) {
						if (a[j] == a[i]) {
							sum += 1;
						}
					}
					for (int m = 0; m < sum; m++) {
						cout << a[i]<<" " << (1000 - i) << endl;
					}
				}
			}
		}
	}

	return 0;
}