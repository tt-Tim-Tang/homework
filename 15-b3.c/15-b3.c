//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	fprintf(stderr, "文件名以下形式均可以:\n");
	fprintf(stderr, "    a.txt                     : 不带路径形式\n");
	fprintf(stderr, "    ..\\data\\b.dat             : 相对路径形式\n");
	fprintf(stderr, "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式\n");
	fprintf(stderr, "请输入文件名 : ");

	char filename[256];
	scanf("%255s", filename);

	FILE* fin = fopen(filename, "rb");
	if(fin==NULL){
		fprintf(stderr, "输入文件%s打开失败!\n", filename);
		return -1;
	}
	char buffer[16];
	int address = 0;

	int read_len;
	while ((read_len = fread(buffer, 1, 16, fin)) > 0) {
		//输出左侧地址
		printf("%08X:  ", address);
		//输出中间16进制字节
		for(int i=0;i<16;i++){
			if(i<read_len){
				printf("%02X", (unsigned char)(buffer[i]));
			}
			else{
				printf("  ");
			}
			if(i==7&&read_len>8){
				printf(" - ");
			}
			else if(i==7&&read_len<=8){
				printf("   ");
			}
			else{
				printf(" ");
			}
		}
		printf(" ");
		//输出右侧ASCII字符
		for(int i=0;i<read_len;i++){
			unsigned char ch = (unsigned char)(buffer[i]);
			if(ch>=33&&ch<=126){
				printf("%c", ch);
			}
			else{
				printf(".");
			}
		}
		printf("\n");
		address += read_len;
	}
	fclose(fin);
	return 0;
}