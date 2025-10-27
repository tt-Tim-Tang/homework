//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned char convert(const char* hex) {
	unsigned int val;
	sscanf(hex, "%2x", &val);
	return (unsigned char)val;
}
int main()
{
	fprintf(stderr, "文件名以下形式均可以:\n");
	fprintf(stderr, "    a.txt                     : 不带路径形式\n");
	fprintf(stderr, "    ..\\data\\b.dat             : 相对路径形式\n");
	fprintf(stderr, "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式\n");
	fprintf(stderr, "请输入要转换的hex格式文件名 : ");
	char infilename[256];
	scanf("%255s",infilename);
	fprintf(stderr, "请输入转换后的文件名        : ");
	char outfilename[256];
	scanf("%255s", outfilename);

	FILE* fin = fopen(infilename, "r");
	if (fin == NULL) {
		fprintf(stderr, "输入文件%s打开失败!\n", infilename);
		return -1;
	}
	FILE* fout = fopen(outfilename, "wb");
	if (fout == NULL) {
		fprintf(stderr, "输出文件%s打开失败!\n", outfilename);
		fclose(fin);
		return -1;
	}

	char line[256];
	char hex_buf[3];
	while (fgets(line, 256, fin)) {
		int i = 11;
		while (i < 60) {
			if (line[i] == ' ' || line[i] == '-') {
				i++;
				continue;
			}
			else {
				hex_buf[0] = line[i];
				hex_buf[1] = line[i + 1];
				hex_buf[2] = '\0';
				fputc(convert(hex_buf), fout);
				i += 2;
			}
		}
	}


	fclose(fin);
	fclose(fout);
	return 0;
}