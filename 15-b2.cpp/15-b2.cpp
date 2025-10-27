//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

unsigned char convert(const char* hex) {
	unsigned int val;
	sscanf(hex, "%2X", &val);
	return (unsigned char)val;
}

int main()
{
	cerr<< "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                     : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入要转换的hex格式文件名 : ";
	char infilename[256];
	cin.getline(infilename, 256);
	cerr << "请输入转换后的文件名        : ";
	char outfilename[256];
	cin.getline(outfilename, 256);


	ifstream fin(infilename);
	if (!fin.is_open()) {
		cerr << "输入文件" << infilename << "打开失败!" << endl;
		return -1;
	}
	ofstream fout(outfilename, ios::binary);
	if (!fout.is_open()) {
		cerr << "输出文件" << outfilename << "打开失败!" << endl;
		fin.close();
		return -1;
	}
	char line[256];
	char hex_buf[3];

	while (fin.getline(line,256)) {
		int i = 11;
		while(i<60){
			if(line[i]==' '||line[i]=='-'){
				i++;
				continue;
			}
			else {
				hex_buf[0] = line[i];
				hex_buf[1] = line[i + 1];
				hex_buf[2] = '\0';
				fout.put(convert(hex_buf));
				i += 2;
			}
		}

	}


	fin.close();
	fout.close();
	return 0;
}