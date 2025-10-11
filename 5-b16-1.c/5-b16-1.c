//2453805 唐先泽 电信
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void input(char id_num[][8],char name[][9],int score[])
{
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", id_num[i], name[i], &score[i]);
	}
}
int compare(char ch_1[], char ch_2[])
{
	for (int i = 0; i < 8; i++) {
		if (ch_1[i] < ch_2[i]) {
			return 1;
		}
		if (ch_1[i] > ch_2[i]) {
			return 0;
		}
	}
	return 0;
}
void swap(char id_num[][8], char name[][9], int score[])//学号降序
{
	char temp_id[8] = { 0 };
	char temp_name[9] = { 0 };
	int temp_score = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (compare(id_num[j], id_num[j + 1])) {
				//改学号
				strcpy(temp_id, id_num[j]);
				strcpy(id_num[j], id_num[j + 1]);
				strcpy(id_num[j + 1], temp_id);
				//改名字
				strcpy(temp_name, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp_name);
				//改分数
				temp_score = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp_score;
			}
		}

	}
}
void output(char id_num[][8], char name[][9], int score[])
{
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++) {
		if (score[i] >= 60) {
			printf("%s %s %d\n", name[i], id_num[i], score[i]);
		}
	}
}
int main()
{
	char id_num[10][8] = { 0 };
	char name[10][9] = { 0 };
	int score[10] = { 0 };
	input(id_num, name, score);
	swap(id_num, name, score);
	printf("\n");
	output(id_num, name, score);
	return 0;
}