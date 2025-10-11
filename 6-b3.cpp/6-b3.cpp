//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	char input[33];
	unsigned int output=0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.getline(input, 33);
	char* p = input;
	for (; *p != '\0'; p++) {
		output = 2 * output + *p - '0';
	}
	cout << output << endl;
	return 0;
}