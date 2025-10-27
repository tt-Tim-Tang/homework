//2453805 唐先泽 大数据
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                     : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入文件名 : ";

	char filename[256];
	cin.getline(filename, 256);

	ifstream fin(filename, ios::binary);
	if (!fin.is_open()) {
		cerr << "输入文件" << filename << "打开失败!" << endl;
		return -1;
	}

	char buffer[16];
	int address = 0;
	while (fin) {

		fin.read(buffer, 16);
		//输出左侧地址
		cout << setw(8) << setfill('0') << hex <<uppercase << address << ":  ";

		//输出中间16进制字节
		int read_len = (int)(fin.gcount());
		for (int i = 0; i < 16; i++) {
			if(i<read_len){
				cout << setw(2) << setfill('0') << hex << (int)((unsigned char)(buffer[i]));
			}
			else {
				cout << "  ";
			}

			if (i == 7 && read_len > 8) {
				cout << " - ";
			}
			else if (i == 7 && read_len <= 8) {
				cout << "   ";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		//输出右侧ASCII字符
		for (int i = 0; i < read_len; i++) {
			unsigned char ch = (unsigned char)(buffer[i]);
			if (ch >= 33 && ch <= 126) {
				cout << ch;
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
		address += read_len;
	}
	fin.close();
	return 0;
}