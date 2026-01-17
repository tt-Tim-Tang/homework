//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;

struct student {
	int no;
	char info[30];
	char school[20];
};
int main()
{
	srand((unsigned)time(NULL));
	char filename[] = "stulist.txt";
	ifstream fin(filename);
	if(!fin.is_open()){
		cout << "文件读取失败" << endl;
		return -1;
	}
	char buff[64];
	fin.getline(buff, 64);
	istringstream in_select_num(buff);
	int num_select;
	in_select_num >> num_select;
	fin.getline(buff, 64);
	istringstream in_stu_num(buff);
	int num_students;
	in_stu_num >> num_students;

	struct student* res = new(nothrow) struct student[num_select];
	if (res == NULL) {
		cout << "No Memory" << endl;
		return -1;
	}
	for (int i = 0; i < num_select; i++) {
		char line[80];
		fin.getline(line, 80);
		istringstream in(line);
		int no;
		char info[30];
		char school[20];
		in >> no >> info >> school;

		res[i].no = no;
		strcpy(res[i].info, info);
		strcpy(res[i].school, school);

	}

	for (int i = num_select; i < num_students; i++) {
		char line[80];
		fin.getline(line, 80);
		istringstream in(line);
		int no;
		char info[30];
		char school[20];
		in >> no >> info >> school;

		int num = rand() % (i + 1);
		if (num < num_select) {
			res[num].no = no;
			strcpy(res[num].info, info);
			strcpy(res[num].school, school);
		}
	}
	fin.close();

	char out_filename[] = "result.txt";
	ofstream fout(out_filename);

	if (!fout.is_open()) {
		cout << "文件打开失败" << endl;
		return -1;
	}

	for (int i = 0; i < num_select; i++) {
		fout << res[i].no << " " << res[i].info << " " << res[i].school << endl;
	}
	fout.close();

	delete[] res;

	cout << "输出完成" << endl;


	return 0;
}
// 选择申请连续空间当数组用的理由：我选择的这种随机抽签方法用链表做元素替换时间复杂度会比直接申请连续空间当数组高而且实现起来更复杂
// 而且由于本题可以知道选择的人数，即提前知道总大小，用链表反而会因为存指针使得内存开销更大