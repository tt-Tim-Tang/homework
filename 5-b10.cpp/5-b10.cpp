//2453805 唐先泽 电信
#include<iostream>
#include<iomanip>
using namespace std;
//蔡勒公式算某年某月某日是星期几
int zeller(int y, int m, int d)
{
	int c;
	int w;
	int y1;
	c = y / 100;
	y1 = y - c * 100;
	if (m == 1) {
		m = 13;
		y = y - 1;
		c = y / 100;
		y1 = y - c * 100;

	}
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y1 = y - c * 100;
	}
	w = y1 + y1 / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0) {
		while (1) {
			w += 7;
			if (w >= 0) {
				w = w % 7;
				break;
			}
		}
	}
	else {
		w = w % 7;
	}

	return w;
}


//输出某年某月的日历
void put_day_in_list(int year, int num, int start)
{
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
		m[2] = 29;
	}
	else {//平年
		m[2] = 28;
	}
	int jan[6][7] = { 0 };
	int feb[6][7] = { 0 };
	int mar[6][7] = { 0 };
	int apr[6][7] = { 0 };
	int may[6][7] = { 0 };
	int jun[6][7] = { 0 };
	int jul[6][7] = { 0 };
	int aug[6][7] = { 0 };
	int sep[6][7] = { 0 };
	int oct[6][7] = { 0 };
	int nov[6][7] = { 0 };
	int dec[6][7] = { 0 };

	//把输入年份的每个月的日期放入对应的二维数组中
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= m[i]; j++) {
			int w = zeller(year, i, j);
			switch (i) {
			case 1:
				if (jan[0][6] == 0) {
					jan[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (jan[k][w] == 0) {
							jan[k][w] = j;
							break;
						}
					}
				}
				break;
			case 2:
				if (feb[0][6] == 0) {
					feb[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (feb[k][w] == 0) {
							feb[k][w] = j;
							break;
						}
					}
				}
				break;
			case 3:
				if (mar[0][6] == 0) {
					mar[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (mar[k][w] == 0) {
							mar[k][w] = j;
							break;
						}
					}
				}
				break;
			case 4:
				if (apr[0][6] == 0) {
					apr[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (apr[k][w] == 0) {
							apr[k][w] = j;
							break;
						}
					}
				}
				break;
			case 5:
				if (may[0][6] == 0) {
					may[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (may[k][w] == 0) {
							may[k][w] = j;
							break;
						}
					}
				}
				break;
			case 6:
				if (jun[0][6] == 0) {
					jun[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (jun[k][w] == 0) {
							jun[k][w] = j;
							break;
						}
					}
				}
				break;
			case 7:
				if (jul[0][6] == 0) {
					jul[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (jul[k][w] == 0) {
							jul[k][w] = j;
							break;
						}
					}
				}
				break;
			case 8:
				if (aug[0][6] == 0) {
					aug[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (aug[k][w] == 0) {
							aug[k][w] = j;
							break;
						}
					}
				}
				break;
			case 9:
				if (sep[0][6] == 0) {
					sep[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (sep[k][w] == 0) {
							sep[k][w] = j;
							break;
						}
					}
				}
				break;
			case 10:
				if (oct[0][6] == 0) {
					oct[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (oct[k][w] == 0) {
							oct[k][w] = j;
							break;
						}
					}
				}
				break;
			case 11:
				if (nov[0][6] == 0) {
					nov[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (nov[k][w] == 0) {
							nov[k][w] = j;
							break;
						}
					}
				}
				break;
			case 12:
				if (dec[0][6] == 0) {
					dec[0][w] = j;
				}
				else {
					for (int k = 1; k <= 5; k++) {
						if (dec[k][w] == 0) {
							dec[k][w] = j;
							break;
						}
					}
				}
				break;
			}
		}
	}
	//输出每个月的日期
	int sum = 0;
	for (int i = 0; i <= 5; i++) {
		for (int n = start; n < (start + num); n++) {
			for (int j = 0; j <= 6; j++) {
				switch (n) {
				case 1:
					if (jan[5][j] != 0) {
						sum++;
					}
					if (jan[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << jan[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;

				case 2:
					if (feb[5][j] != 0) {
						sum++;
					}
					if (feb[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << feb[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 3:
					if (mar[5][j] != 0) {
						sum++;
					}
					if (mar[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << mar[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 4:
					if (apr[5][j] != 0) {
						sum++;
					}
					if (apr[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << apr[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 5:
					if (may[5][j] != 0) {
						sum++;
					}
					if (may[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << may[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 6:
					if (apr[5][j] != 0) {
						sum++;
					}
					if (jun[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << jun[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 7:
					if (jul[5][j] != 0) {
						sum++;
					}
					if (jul[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << jul[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 8:
					if (aug[5][j] != 0) {
						sum++;
					}
					if (aug[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << aug[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 9:
					if (sep[5][j] != 0) {
						sum++;
					}
					if (sep[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << sep[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 10:
					if (oct[5][j] != 0) {
						sum++;
					}
					if (oct[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << oct[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 11:
					if (nov[5][j] != 0) {
						sum++;
					}
					if (nov[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << nov[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;
				case 12:
					if (dec[5][j] != 0) {
						sum++;
					}
					if (dec[i][j] == 0) {
						cout << setw(4) << " ";
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					else {
						cout << setw(4) << left << dec[i][j];
						if (j == 6) {
							cout << setw(4) << " ";
						}
					}
					break;

				}

			}
		}
		cout << endl;

	}
	if (sum != 0) {
		cout << endl;
	}

}


void output(int num, int year)
{

	for (int i = 1; i < 13; i++) {
		cout << resetiosflags(ios::left);
		cout << setw(13) << i << "月";
		cout << setw(17) << " ";
		if (i % num == 0) {
			cout << endl;

			for (int k = 1; k <= num; k++) {
				char week_day[7][5] = { "Sun ","Mon ","Tue ","Wed " ,"Thu " ,"Fri " ,"Sat " };
				for (int j = 0; j < 7; j++) {
					cout << week_day[j];
				}
				cout << setw(4) << " ";
			}
			cout << endl;
			put_day_in_list(year, num, i - num + 1);



		}
	}
}
int main()
{
	int year;
	int num;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (year < 1900 || year>2100) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else {
				break;
			}
		}
	}
	while (1) {
		cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else {
			if (num != 1 && num != 2 && num != 3 && num != 4 && num != 6 && num != 12) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else {
				break;
			}
		}
	}
	cout << year << "年的日历:" << endl;
	cout << endl;
	output(num, year);

	return 0;
}


