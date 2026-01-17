//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
	int no;
	char name[17];
	int score;
	int rank;
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
	char filename[] = "student.txt";
	FILE* fin = fopen(filename, "r");
	if(fin == NULL){
		printf("输入文件%s打开失败!\n", filename);
		return -1;
	}
	char buff[64];
	fgets(buff, 10, fin);
	eliminate_n(buff);
	int num_students;
	sscanf(buff, "%d", &num_students);
	struct student* p = (struct student*)malloc(num_students * sizeof(struct student));
	if (p == NULL) {
		printf("No Memory\n");
		return -1;
	}
	for (int i = 0; i < num_students; i++) {
		fgets(buff, 64, fin);
		eliminate_n(buff);
		int no, score;
		char name[17];
		sscanf(buff, "%d %s %d", &no, name, &score);
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
		}
		if (swapped == 0) {
			break;
		}
	}

	p[0].rank = 1;
	for(int i=1;i<num_students;i++){
		if(p[i].score==p[i-1].score){
			p[i].rank = p[i-1].rank;
		}
		else{
			p[i].rank = i+1;
		}
	}

	for(int i = 0;i < num_students;i++){
		int swapped = 0;
		for(int j = 0;j < num_students - 1 - i;j++){
			if(p[j].no > p[j+1].no){
				swapped = 1;
				struct student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
		if (swapped == 0) {
			break;
		}
	}

	for(int i=0;i<num_students;i++){
		printf("%d %s %d %d\n", p[i].no, p[i].name, p[i].score, p[i].rank);
	}
	
	fclose(fin);
	free(p);
	return 0;
}