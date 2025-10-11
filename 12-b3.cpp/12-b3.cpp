//2453805 唐先泽 大数据
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入月份(1-12)"<<endl;
	int m;
	const char* month[] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
	if (cin >> m && m >= 1 && m <= 12)
		cout << *(month + m - 1) << endl;
	else
		cout << "Invalid" << endl;
	return 0;
}