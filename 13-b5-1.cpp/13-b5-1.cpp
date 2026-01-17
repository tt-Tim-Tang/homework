//2453805 唐先泽 大数据
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

void usage(const char* const procname)
{
	cout << "Usage : " << procname << " --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名" << endl;
	cout << "        " << procname << " --check a.txt" << endl;
	cout << "        " << procname << " --convert wtol a.win.txt a.linux.txt" << endl;
	cout << "        " << procname << " --convert ltow a.linux.txt a.win.txt" << endl;

}

int check(ifstream &infile){
	char ch;
	char prev_ch = 0;
	int count_a = 0;
	int count_d = 0;
	while (infile.get(ch)) {
		if (ch == 0x0A) {
			count_a++;
			if (prev_ch == 0x0D) {
				count_d++;
			}
		}
		prev_ch = ch;
	}
	if (count_a == count_d && count_a != 0) {
		return 1;
	}
	else if (count_a != 0 && count_d == 0) {
		return 2;
	}
	else {
		return 0;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	if(argc == 1) {
		usage(argv[0]);
		return 0;
	}
	if (strcmp(argv[1], "--check") == 0) {
		if (argc == 3) {
			ifstream infile(argv[2],ios::binary);
			if (!infile) {
				cout << "文件打开失败" << endl;
				return 0;
			}
			char ch;
			char prev_ch = 0;
			int count_a = 0;
			int count_d = 0;
			while (infile.get(ch)) {
				if (ch == 0x0A) {
					count_a++;
					if (prev_ch == 0x0D) {
						count_d++;
					}
				}
				prev_ch = ch;
			}
			if (count_a == count_d && count_a != 0) {
				cout << "Windows格式" << endl;
			}
			else if (count_a != 0 && count_d == 0) {
				cout << "Linux格式" << endl;
			}
			else {
				cout << "文件格式无法识别" << endl;
			}
			infile.close();
			return 0;
		}
		else {
			usage(argv[0]);
			return 0;
		}
		return 0;
	}

	if(strcmp(argv[1],"--convert")==0) {
		if(argc ==5) {
	
			if(strcmp(argv[2],"wtol")!=0 && strcmp(argv[2],"ltow")!=0) {
				usage(argv[0]);
				return 0;
			}

			ifstream infile(argv[3], ios::binary);
			if (!infile) {
				cout << "文件打开失败" << endl;
				return 0;
			}

			ofstream outfile(argv[4], ios::binary);
			if (!outfile) {
				cout << "文件创建失败" << endl;
				infile.close();
				return 0;
			}

			char ch;
			
			if (strcmp(argv[2], "wtol") == 0) {
				if(check(infile)!= 1){
					cout<<"文件格式无法识别"<<endl;
					infile.close();
					outfile.close();
					return 0;
				}
				infile.clear();
				infile.seekg(0, ios::beg);

				int opt = 0;
				bool pending_cr = false;
				while (infile.get(ch)) {
					if(pending_cr) {
						if(ch == 0x0A) {
							outfile.put(0x0A);
							opt++;
						}
						else {
							outfile.put(0x0D);
							outfile.put(ch);
						}
						pending_cr = false;
					}
					else {
						if(ch == 0x0D) {
							pending_cr = true;
						}
						else {
							outfile.put(ch);
						}
					}
				}
				if(pending_cr) {
					outfile.put(0x0D);
				}
				cout << "转换完成，去除" << opt << "个0x0D" << endl;
			}
			else if (strcmp(argv[2], "ltow") == 0) {
				if (check(infile) != 2) {
					cout << "文件格式无法识别" << endl;
					infile.close();
					outfile.close();
					return 0;
				}
				infile.clear();
				infile.seekg(0, ios::beg);

				int opt = 0;
				while (infile.get(ch)) {
					if (ch == 0x0A) {
						opt++;
						outfile.put(0x0D);
						outfile.put(0x0A);
					}
					else {
						outfile.put(ch);
					}
				}
				cout << "转换完成，加入" << opt << "个0x0D" << endl;
			}
			else {
				usage(argv[0]);
				infile.close();
				outfile.close();
				return 0;
			}
			infile.close();
			outfile.close();
			return 0;
		}
		else {
			usage(argv[0]);
			return 0;
		}
		return 0;
	}

	usage(argv[0]);

	return 0;
}