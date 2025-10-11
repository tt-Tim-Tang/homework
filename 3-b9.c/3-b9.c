//2453805 Ã∆œ»‘Û µÁ–≈
#include<stdio.h>
int main()
{
	int i = 1, j = 1;
	for (j = 1; j <= 9; j++) {
		for (i = 1; i <= j; i++) {
			printf("%dx%d=%d", i, j, (i * j));
			if ((i * j) < 10) {
				printf("   ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}