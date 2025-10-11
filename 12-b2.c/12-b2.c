//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

double definite_integration(double (*f)(double),int n, double low, double high)
{
	double delta_x = (high - low) / n;
	double result = 0;
	for (int i = 1; i < n+1; i++) {
		result += f(low + i * delta_x) * delta_x;
	}
	return result;
}
int main()
{
	int n;//划分数量
	double low, high, value;

	printf("请输入sinxdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	value = definite_integration(sin,n,low,high);
	printf("sinxdx[%g~%g/n=%d] : %g\n", low, high, n, value);

	printf("请输入cosxdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	value = definite_integration(cos,n,low,high);
	printf("cosxdx[%g~%g/n=%d] : %g\n", low, high, n, value);

	printf("请输入e^xdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	value = definite_integration(exp,n,low,high);
	printf("e^xdx[%g~%g/n=%d] : %g\n", low, high, n, value);

	return 0;
}