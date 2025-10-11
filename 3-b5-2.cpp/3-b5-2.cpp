//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	int year, month, day,day_out;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	if (month >= 13 || month <= 0) {
		cout << "输入错误-月份不正确" << endl;
	}
	else  {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {           // 闰年
			switch (month) {
			case 12:
				day_out = 335 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 11:
				day_out = 305 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 10:
				day_out = 274 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 9:
				day_out = 244 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 8:
				day_out = 213 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 7:
				day_out = 182 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 6:
				day_out = 152 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 5:
				day_out = 121 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 4:
				day_out = 91 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 3:
				day_out = 60 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
					break;
			case 2:
				day_out = 31 + day;
				if (day >= 30 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
					break;
			case 1:
				day_out = day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
					break;
				}

	
		}
		else {                                                        // 不是闰年
			switch (month) {
			case 12:
				day_out = 334 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 11:
				day_out = 304 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 10:
				day_out = 273 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 9:
				day_out = 243 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 8:
				day_out = 212 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 7:
				day_out = 181 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 6:
				day_out = 151 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 5:
				day_out = 120 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 4:
				day_out = 90 + day;
				if (day >= 31 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 3:
				day_out = 59 + day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 2:
				day_out = 31 + day;
				if (day >= 29 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			case 1:
				day_out = day;
				if (day >= 32 || day <= 0) {
					cout << "输入错误-日与月的关系非法" << endl;
				}
				else {
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_out << "天" << endl;
				}
				break;
			}
		}
	}
    return 0;
}