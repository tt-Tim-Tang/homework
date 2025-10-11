//2453805 唐先泽 电信
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int len, daxie, xiaoxie, num, rest;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> daxie >> xiaoxie >> num >> rest;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	else {
		if (len > 16 || len < 12) {
			cout << "密码长度[" << len << "]不正确" << endl;
			return 0;
		}
		if (daxie < 2 || daxie>len) {
			cout << "大写字母个数[" << daxie << "]不正确" << endl;
			return 0;
		}
		if (xiaoxie < 2 || xiaoxie>len) {
			cout << "小写字母个数[" << xiaoxie << "]不正确" << endl;
			return 0;
		}
		if (num < 2 || num>len) {
			cout << "数字个数[" << num << "]不正确" << endl;
			return 0;
		}
		if (rest < 2 || rest>len) {
			cout << "其它符号个数[" << rest << "]不正确" << endl;
			return 0;
		}
		if (daxie + xiaoxie + num + rest > len) {
			cout << "所有字符类型之和[" << daxie << "+" << xiaoxie << "+" << num << "+" << rest << "]大于总密码长度[" << len << "]" << endl;
			return 0;
		}

	}

	cout << len << " " << daxie << " " << xiaoxie << " " << num << " " << rest << endl;

	//生成随机数
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 10; i++) {



		char output[16] = { 0 };
		for (int j = 0; j < daxie; j++) {
			int da_pos = rand() % len;
			if (output[da_pos] == 0) {
				output[da_pos] = rand() % 26 + 65;
			}
			else {
				j--;
			}
		}
		for (int j = 0; j < xiaoxie; j++) {
			int xiao_pos = rand() % len;
			if (output[xiao_pos] == 0) {
				output[xiao_pos] = rand() % 26 + 97;
			}
			else {
				j--;
			}
		}
		for (int j = 0; j < num; j++) {
			int num_pos = rand() % len;
			if (output[num_pos] == 0) {
				output[num_pos] = rand() % 10 + 48;
			}
			else {
				j--;
			}
		}
		for (int j = 0; j < rest; j++) {
			int rest_pos = rand() % len;
			if (output[rest_pos] == 0) {
				output[rest_pos] = other[rand() % 15];
			}
			else {
				j--;
			}
		}
		int left_num = len - daxie - xiaoxie - num - rest;
		if (left_num > 0) {
			for (int k = 0; k < left_num; k++) {//处理至少满足以后多出来的空位
				int temp = rand() % 4;
				if (temp == 0) {//大写字母
					int pos = rand() % len;
					if (output[pos] == 0) {
						output[pos]= rand() % 26 + 65;
					}
					else {
						k--;
					}
				}
				else if (temp == 1) {//小写字母
					int pos = rand() % len;
					if (output[pos] == 0) {
						output[pos] = rand() % 26 + 97;
					}
					else {
						k--;
					}
				}
				else if (temp == 2) {//数字
					int pos = rand() % len;
					if (output[pos] == 0) {
						output[pos] = rand() % 10 + 48;
					}
					else {
						k--;
					}
				}
				else {//其它符号
					int pos = rand() % len;
					if (output[pos] == 0) {
						output[pos] = other[rand() % 15];
					}
					else {
						k--;
					}
				}
			}

		}

		for (int m = 0; m < len; m++) {
			cout << output[m];
		}
		cout << endl;

	}

	return 0;
}