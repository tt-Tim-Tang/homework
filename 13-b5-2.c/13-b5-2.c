//2453805 唐先泽 大数据
#include <stdio.h>
#include<string.h>

void usage(const char* procname)
{
	printf("Usage : %s --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名\n", procname);
	printf("        %s --check a.txt\n", procname);
	printf("        %s --convert wtol a.win.txt a.linux.txt\n", procname);
	printf("        %s --convert ltow a.linux.txt a.win.txt\n", procname);
}

int check(FILE* infile) {
	char ch;
	char prev_ch = 0;
	int count_a = 0;
	int count_d = 0;
	while ((ch = fgetc(infile)) != EOF) {
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
	if (argc == 1) {
		usage(argv[0]);
		return 0;
	}
	if (strcmp(argv[1], "--check") == 0) {
		if (argc == 3) {
			FILE* infile = fopen(argv[2], "rb");
			if (!infile) {
				printf("文件打开失败\n");
				return 0;
			}
			char ch;
			char prev_ch = 0;
			int count_a = 0;
			int count_d = 0;
			while ((ch = fgetc(infile)) != EOF) {
				if (ch == 0x0A) {
					count_a++;
					if (prev_ch == 0x0D) {
						count_d++;
					}
				}
				prev_ch = ch;
			}
			if (count_a == count_d && count_a != 0) {
				printf("Windows格式\n");
			}
			else if (count_a != 0 && count_d == 0) {
				printf("Linux格式\n");
			}
			else {
				printf("文件格式无法识别\n");
			}
			fclose(infile);
			return 0;
		}
		else {
			usage(argv[0]);
			return 0;
		}
		return 0;
	}

	if (strcmp(argv[1], "--convert") == 0) {
		if (argc == 5) {

			if (strcmp(argv[2], "wtol") != 0 && strcmp(argv[2], "ltow") != 0) {
				usage(argv[0]);
				return 0;
			}

			FILE* infile = fopen(argv[3], "rb");
			if (!infile) {
				printf("文件打开失败\n");
				return 0;
			}

			FILE* outfile = fopen(argv[4], "wb");
			if (!outfile) {
				printf("文件创建失败\n");
				fclose(infile);
				return 0;
			}

			char ch;

			if (strcmp(argv[2], "wtol") == 0) {
				if (check(infile) != 1) {
					printf("文件格式无法识别\n");
					fclose(infile);
					fclose(outfile);
					return 0;
				}
				rewind(infile);

				int opt = 0;
				int pending_cr = 0;
				while ((ch = fgetc(infile)) != EOF) {
					if (pending_cr) {
						if (ch == 0x0A) {
							fputc(0x0A, outfile);
							opt++;
						}
						else {
							fputc(0x0D, outfile);
							fputc(ch, outfile);
						}
						pending_cr = 0;
					}
					else {
						if (ch == 0x0D) {
							pending_cr = 1;
						}
						else {
							fputc(ch, outfile);
						}
					}
				}
				if (pending_cr) {
					fputc(0x0D, outfile);
				}
				printf("转换完成，去除%d个0x0D\n", opt);
			}
			else if (strcmp(argv[2], "ltow") == 0) {
				if (check(infile) != 2) {
					printf("文件格式无法识别\n");
					fclose(infile);
					fclose(outfile);
					return 0;
				}
				rewind(infile);

				int opt = 0;
				while ((ch = fgetc(infile)) != EOF) {
					if (ch == 0x0A) {
						opt++;
						fputc(0x0D, outfile);
						fputc(0x0A, outfile);
					}
					else {
						fputc(ch, outfile);
					}
				}
				printf("转换完成，加入%d个0x0D\n", opt);
			}
			else {
				usage(argv[0]);
				fclose(infile);
				fclose(outfile);
				return 0;
			}
			fclose(infile);
			fclose(outfile);
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