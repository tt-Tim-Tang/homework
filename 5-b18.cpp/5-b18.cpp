//2453805 Ã∆œ»‘Û µÁ–≈
#include<iostream>
using namespace std;
int tj_strlen(const char str[])
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
int main()
{
	char input[100] = { 0 };
	cin.getline(input, 100);
	static const char other[] = "!@#$%^&*-_=+,.?";
	int len, daxie, xiaoxie, num, rest;
	cin >> len >> daxie >> xiaoxie >> num >> rest;
	cin.ignore(INT_MAX, '\n');
	if (cin.fail()) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	else {
		if (len < 12 || len>16) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		if (daxie < 2 || daxie>len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		if (xiaoxie < 2 || xiaoxie>len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		if (num < 2 || num>len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		if (rest < 2 || rest>len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		if (daxie + xiaoxie + num + rest > len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		char ch[17] = { 0 };
		cin.getline(ch, 17);
		if (cin.fail()||tj_strlen(ch) != len) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
		int sum_num = 0, sum_daxie = 0, sum_xiaoxie = 0, sum_rest = 0;
		for (int k = 0; k < len; k++) {
			if (ch[k] >= '0' && ch[k] <= '9') {
				sum_num++;
			}
			else if (ch[k] >= 'A' && ch[k] <= 'Z') {
				sum_daxie++;
			}
			else if (ch[k] >= 'a' && ch[k] <= 'z') {
				sum_xiaoxie++;
			}
			else {
				for (int m = 0; m < 15; m++) {
					if (ch[k] == other[m]) {
						sum_rest++;
					}
				}
			}
		}
		if (sum_num < num || sum_daxie < daxie || sum_xiaoxie < xiaoxie || sum_rest < rest || (sum_num + sum_daxie + sum_xiaoxie + sum_rest != len)) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}

	}


	cout << "’˝»∑" << endl;

	return 0;
}