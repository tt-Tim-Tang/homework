//2453805 唐先泽 电信
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int a[1000] = { 0 };
	for (int i = 0; i < 1000; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < 1000; i++) {
		scanf("%d", &a[i]);
		if (a[i] < 0) {
			if (a[0] < 0) {
				printf("无有效输入\n");
				return 0;
			}
			break;
		}
	}

	printf("输入的数组为:\n");
	for (int i = 0; i < 1000; i++) {
		if (a[i] >= 0) {
			printf("%d ", a[i]);
			if ((i + 1) % 10 == 0) {
				printf("\n");
			}
			if (a[i + 1] < 0 && (i + 1) % 10 != 0) {
				printf("\n");
			}
		}
		else {
			break;
		}
	}
	printf("分数与人数的对应关系为:\n");
	for (int i = 0; i < 999; i++) {
		for (int j = i + 1; j < 1000; j++) {
			if (a[i] > a[j]) {
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (int i = 999; i >= 0; i--) {
		if (a[i] >= 0 && a[i] != a[i - 1]){
			int sum = 0;
			for (int j = 0; j < 1000;j++) {
				if (a[j] == a[i]) {
					sum += 1;
				}
			}
			printf("%d %d\n", a[i], sum);
		}
	}

	return 0;
}