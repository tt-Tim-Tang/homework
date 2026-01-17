//2453805 唐先泽 大数据
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int usage(const char* const procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2459999 2459998 all       80 screen" << endl;
	cout << "       " << procname << " 2459999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 6) {
		usage(argv[0]);
		return 0;
	}

	if (strcmp(argv[1], "all") == 0) {
		if (strcmp(argv[2], "all") != 0) {
			cout << "检查学号是all，匹配学号必须是all" << endl;
			return 0;
		}
	}

	if (strlen(argv[1])!= 7) {
		cout << "要检查的学号不是7位" << endl;
		return 0;
	}

	if (strlen(argv[1]) == 7) {
		for(int i=0; i < 7; i++) {
			if (argv[1][i] < '0' || argv[1][i] > '9') {
				cout << "要检查的学号不是7位数字" << endl;
				return 0;
			}
		}
		
		if (strlen(argv[2]) != 7) {
			if (strcmp(argv[2], "all") != 0) {
				cout << "要匹配的学号不是7位" << endl;
				return 0;
			}
		}

		if (strlen(argv[2]) == 7) {
			for(int i=0; i < 7; i++) {
				if (argv[2][i] < '0' || argv[2][i] > '9') {
					cout << "要匹配的学号不是7位数字" << endl;
					return 0;
				}
			}
		}
	}

	if (strlen(argv[3]) > 32) {
		cout << "源程序文件名超过了32字节" << endl;
		return 0;
	}

	if (strlen(argv[5]) > 32) {
		cout << "输出结果文件名超过了32字节" << endl;
		return 0;
	}

	cout << "参数检查通过" << endl;
	cout << "检查学号：" << argv[1] << endl;
	cout << "匹配学号：" << argv[2] << endl;
	cout << "源文件名：" << argv[3] << endl;
	if(atoi(argv[4])<60 || atoi(argv[4]) > 100) {
		cout << "匹配阈值："<< "80" << endl;
	}
	else {
		cout << "匹配阈值：" << argv[4] << endl;
	}
	cout << "输出目标：" << argv[5] << endl;

	return 0;
}