//2453805 唐先泽 电信
#include<iostream>
using namespace std;
void input(string id_num[], string name[], int score[])
{
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> id_num[i] >> name[i] >> score[i];
	}
}
void swap(string id_num[], string name[], int score[])
{
	int temp_score = 0;
	string temp_id, temp_name;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (id_num[j] > id_num[j + 1]) {
				//改分数
				temp_score = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp_score;
				//改学号
				temp_id = id_num[j];
				id_num[j] = id_num[j + 1];
				id_num[j + 1] = temp_id;
				//改名字
				temp_name = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp_name;
			}
		}
	}
}
void output(string id_num[], string name[], int score[])
{
	cout << "全部学生(学号升序):" << endl;
	for (int i = 0; i < 10; i++) {
		cout << name[i] << " " << id_num[i] << " " << score[i] << endl;
	}
}

int main()
{
	string id_num[10], name[10];
	int score[10] = { 0 };
	input(id_num, name, score);
	swap(id_num, name, score);
	cout << endl;
	output(id_num, name, score);
	return 0;
}