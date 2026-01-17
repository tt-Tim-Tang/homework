//2453805 唐先泽 大数据
#include<iostream>
#include<iomanip>
#include<cstring>
#include<climits>
using namespace std;

void output_status(short status,int if_start_line)
{
	if (!if_start_line) {
		cout << "当前状态：" << "0x" << right <<hex << setw(4) << setfill('0') << status << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << left << setw(4) << setfill(' ') << char('A'+i);
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		if (status % 2 == 1) {
			cout << left << setw(4) << setfill(' ') << "ON";
		}
		else {
			cout << left << setw(4) << setfill(' ') << "OFF";
		}
		status = status / 2;
	}
	cout << endl;
	cout << endl;
}

char low_to_up(char letter) {
	if (letter >= 'a' && letter <= 'z') {
		return char(letter - 32);
	}
	else {
		return letter;
	}
}

int main()
{
	short status = 0x0000;
	cout << "初始状态：" << "0x" << hex << setw(4) << setfill('0') << status << endl;
	output_status(status, 1);
	while (1) {
		cout << "请以(\"A On / J Off\"形式输入，输入\"Q on / off\"退出)"<<endl;
		char letter;
		char opt[20];
		cin >> letter >> opt;
		letter = low_to_up(letter);
		if (letter == 'Q') {
			break;
		}

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (letter < 'A' || letter > 'J') {
			continue;
		}
		else {
			for (int i = 0; i < 20; i++) {
				if(opt[i]=='\0'){
					break;
				}
				opt[i] = low_to_up(opt[i]);
			}

			if (strcmp(opt, "ON") == 0) {
				status = status | (1 << (letter - 'A'));
				output_status(status, 0);
			}
			else if (strcmp(opt, "OFF") == 0) {
				status = status & ~(1 << (letter - 'A'));
				output_status(status, 0);
			}
			else {
				continue;
			}

		}
	}
	return 0;
}