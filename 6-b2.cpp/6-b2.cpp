//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	char str[80];
	char cpy[80] = { 0 };
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	cin.getline(str, 80);
	int len = strlen(str);
	char* p1, * p2;
	for (p1=str,p2=cpy+len-1; p1 - str < len; p1++,p2--) {
		*p2 = *p1;
	}
	int ret = strcmp(str, cpy);
	if (ret==0) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}