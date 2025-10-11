//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int num;
    cout << "请输入一个[1..30000]间的整数:" << endl;
    cin >> num;
    cout << setiosflags(ios::left);
    cout << setw(5) << "万位" << ": " << (num / 10000) << endl;
    cout << setw(5) << "千位" << ": " << (num / 1000 % 10) << endl;
    cout << setw(5) << "百位" << ": " << (num / 100 % 10) << endl;
    cout << setw(5) << "十位" << ": " << (num / 10 % 10) << endl;
    cout << setw(5) << "个位" << ": " << (num % 10) << endl;
    return 0;
}