//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int no;
	char name[17];
	int score;
	struct student* next;
};
void eliminate_n(char* buff)
{
	char* p = buff;
	while (*p != '\0') {
		if (*p == '\n' || *p == '\r') {
			*p = '\0';
			return;
		}
		p++;
	}
}

int main()
{
	char filename[] = "list.txt";
	FILE* fin = fopen(filename, "r");
	if (fin == NULL) {
		printf("输入文件%s打开失败!\n", filename);
		return -1;
	}

	struct student* head = NULL;
	struct student* tail = NULL;
	while (1) {
		char buff[64];
		if (fgets(buff, 64, fin) == NULL) {
			break;
		}
		eliminate_n(buff);
		int no, score;
		char name[17];
		sscanf(buff, "%d %s %d", &no, name, &score);
		if (no == 9999999) {
			break;
		}
		struct student* new_student = (struct student*)malloc(sizeof(struct student));
		if (new_student == NULL) {
			printf("No Memory\n");
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

	fclose(fin);
	struct student* current = head;
	while (current != NULL) {
		printf("%d %s %d\n", current->no, current->name, current->score);
		struct student* temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}