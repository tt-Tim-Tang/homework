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
	struct student* next;
};

int main()
{
	char filename[] = "list.txt";
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "文件读取失败" << endl;
		return -1;
	}
	struct student* head = NULL;
	struct student* tail = NULL;
	while (true) {
		char line[64];
		if (!fin.getline(line, 64)) {
			break;
		}
		istringstream in_stu(line);
		int no, score;
		char name[17];
		in_stu >> no >> name >> score;
		if (no == 9999999) {
			break;
		}
		struct student* new_student = new(nothrow) struct student;
		if (new_student == NULL) {
			cout << "No Memory" << endl;
			return -1;
		}
		new_student->no = no;
		strcpy(new_student->name, name);
		new_student->score = score;
		new_student->next = NULL;
		if (head == NULL) {
			head = new_student;
			tail = new_student;
		}
		else {
			tail->next = new_student;
			tail = new_student;
		}
	}
	fin.close();
	struct student* p = head;
	while(p!= NULL) {
		cout << p->no << " " << p->name << " " << p->score << endl;
		struct student* temp = p;
		p = p->next;
		delete temp;
	}
	return 0;
}