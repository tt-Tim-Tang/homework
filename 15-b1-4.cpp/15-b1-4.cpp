//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

struct student {
	int no;
	char name[17];
	int score;
	int rank;
};


int main()
{
	char filename[] = "student.txt";
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "文件读取失败" << endl;
		return -1;
	}

	char buff[64];
	fin.getline(buff, 64);
	istringstream in(buff);
	int num_students;
	in >> num_students;
	struct student* p = new(nothrow) struct student[num_students];
	if (p == NULL) {
		cout << "No Memory" << endl;
		return -1;
	}
	for (int i = 0; i < num_students; i++) {
		fin.getline(buff, 64);
		int no, score;
		char name[17];
		istringstream in_stu(buff);
		in_stu >> no >> name >> score;
		p[i].no = no;
		strcpy(p[i].name, name);
		p[i].score = score;
		p[i].rank = 0;
	}

	for (int i = 0; i < num_students - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < num_students - 1 - i; j++) {
			if (p[j].score < p[j + 1].score) {
				swapped = 1;
				struct student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
			if (p[j].score == p[j + 1].score) {
				if (p[j].no > p[j + 1].no) {
					swapped = 1;
					struct student temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
		}
		if (swapped == 0) {
			break;
		}
	}

	p[0].rank = 1;
	for (int i = 1; i < num_students; i++) {
		if (p[i].score == p[i - 1].score) {
			p[i].rank = p[i - 1].rank;
		}
		else {
			p[i].rank = i + 1;
		}
	}


	for (int i = 0; i < num_students; i++) {
		cout << p[i].no << " " << p[i].name << " " << p[i].score << " " << p[i].rank << endl;
	}

	fin.close();
	delete[]p;
	return 0;


}