//2453805 唐先泽 电信
# include<iostream>
# include<cmath>
# include<iomanip>
using namespace std;
int main()
{
	const float Pi = 3.14159f;
	int a, b, c;
	float s;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> c;
	s = 0.5f * a * b * sinf(c / 180.0f * Pi);
	cout << "三角形面积为 : " << fixed << setprecision(3) << s << endl;

	return 0;
}